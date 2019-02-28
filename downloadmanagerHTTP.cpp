#include "downloadmanagerHTTP.h"
#include "mainwindow.h"

#include <QFileInfo>
#include <QDateTime>
#include <QDebug>
#include "global.h"

using namespace Global;


DownloadManagerHTTP::DownloadManagerHTTP(QObject *parent) :
    QObject(parent)
    , _pManager(NULL)
    , _pCurrentReply(NULL)
    , _pFile(NULL)
    , _nDownloadTotal(0)
    , _bAcceptRanges(false)
    , _nDownloadSize(0)
    , _nDownloadSizeAtPause(0)
{
}


DownloadManagerHTTP::~DownloadManagerHTTP()
{
    if (_pCurrentReply != NULL)
    {
        pause();
    }
}

void DownloadManagerHTTP::cancelDownload()
{
    gcheckAppDownload = false;
    _pCurrentReply->abort();
}

void DownloadManagerHTTP::download(QUrl url)
{
    downloadCompleteCheck=true;
    _URL = url;
    {
        QFileInfo fileInfo(url.toString());
        _qsFileName = fileInfo.fileName();
#if(SDK75)
        _qsFileName = "/home/root/"+_qsFileName;    //"149911111111.gz";
#endif
#if(NativeCompile)
        _qsFileName = "/home/demo/yaswant/sdjmi_with_std_ui/bmp_to_binary/"+_qsFileName;    //"149911111111.gz";
#endif
        gDownloadFileName = _qsFileName;
    }
    qDebug() << "download: URL=" <<url.toString() << gDownloadFileName;
    _nDownloadSize = 0;
    _nDownloadSizeAtPause = 0;

    _pManager = new QNetworkAccessManager(this);
    _CurrentRequest = QNetworkRequest(url);

    _pCurrentReply = _pManager->head(_CurrentRequest);

    _Timer.setInterval(5000);
    _Timer.setSingleShot(true);
    connect(&_Timer, SIGNAL(timeout()), this, SLOT(timeout()));
    _Timer.start();

    connect(_pCurrentReply, SIGNAL(finished()), this, SLOT(finishedHead()));
    connect(_pCurrentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
}


void DownloadManagerHTTP::pause()
{
    qDebug() << "pause() = " << _nDownloadSize;
    if (_pCurrentReply == NULL)
    {
        return;
    }
    _Timer.stop();
    disconnect(&_Timer, SIGNAL(timeout()), this, SLOT(timeout()));
    disconnect(_pCurrentReply, SIGNAL(finished()), this, SLOT(finished()));
    disconnect(_pCurrentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
    disconnect(_pCurrentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));

    _pCurrentReply->abort();
//    _pFile->write( _pCurrentReply->readAll());
    _pFile->flush();
    _pCurrentReply = 0;
    _nDownloadSizeAtPause = _nDownloadSize;
    _nDownloadSize = 0;
}


void DownloadManagerHTTP::resume()
{
    qDebug() << "resume() = " << _nDownloadSizeAtPause;

    download();
}


void DownloadManagerHTTP::download()
{
    qDebug() << "download()";
    downloadCompleteCheck=true;

    if (_bAcceptRanges)
    {
        QByteArray rangeHeaderValue = "bytes=" + QByteArray::number(_nDownloadSizeAtPause) + "-";
        if (_nDownloadTotal > 0)
        {
            rangeHeaderValue += QByteArray::number(_nDownloadTotal);
        }
        _CurrentRequest.setRawHeader("Range", rangeHeaderValue);
    }

    _pCurrentReply = _pManager->get(_CurrentRequest);

    _Timer.setInterval(5000);
    _Timer.setSingleShot(true);
    connect(&_Timer, SIGNAL(timeout()), this, SLOT(timeout()));
    _Timer.start();

    connect(_pCurrentReply, SIGNAL(finished()), this, SLOT(finished()));
    connect(_pCurrentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
    connect(_pCurrentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
}


void DownloadManagerHTTP::finishedHead()
{
    _Timer.stop();
    _bAcceptRanges = false;

    QList<QByteArray> list = _pCurrentReply->rawHeaderList();
    foreach (QByteArray header, list)
    {
        QString qsLine = QString(header) + " = " + _pCurrentReply->rawHeader(header);
        addLine(qsLine);
    }

    if (_pCurrentReply->hasRawHeader("Accept-Ranges"))
    {
        QString qstrAcceptRanges = _pCurrentReply->rawHeader("Accept-Ranges");
        _bAcceptRanges = (qstrAcceptRanges.compare("bytes", Qt::CaseInsensitive) == 0);
        qDebug() << "Accept-Ranges = " << qstrAcceptRanges << _bAcceptRanges;
    }

    _nDownloadTotal = _pCurrentReply->header(QNetworkRequest::ContentLengthHeader).toInt();

//    _CurrentRequest = QNetworkRequest(url);
    _CurrentRequest.setRawHeader("Connection", "Keep-Alive");
    _CurrentRequest.setAttribute(QNetworkRequest::HttpPipeliningAllowedAttribute, true);
    _pFile = new QFile(_qsFileName + ".part");
    if (!_bAcceptRanges)
    {
        _pFile->remove();
    }
    _pFile->open(QIODevice::ReadWrite | QIODevice::Append);

    _nDownloadSizeAtPause = _pFile->size();
    download();
}


void DownloadManagerHTTP::finished()
{
    qDebug() << __FUNCTION__<<downloadCompleteCheck;
    if(downloadCompleteCheck)
    {

        _Timer.stop();
        _pFile->close();
        QFile::remove(_qsFileName);
        _pFile->rename(_qsFileName + ".part", _qsFileName);
        _pFile = NULL;
        _pCurrentReply = 0;
        emit downloadComplete();
    }
    else
    {
        emit downloadFailed();
    }
}


void DownloadManagerHTTP::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    _Timer.stop();
    _nDownloadSize = _nDownloadSizeAtPause + bytesReceived;
    qDebug() << "Download Progress: Received=" << _nDownloadSize <<": Total=" << _nDownloadSizeAtPause + bytesTotal;

    _pFile->write(_pCurrentReply->readAll());
    int nPercentage = static_cast<int>((static_cast<float>(_nDownloadSizeAtPause + bytesReceived) * 100.0) / static_cast<float>(_nDownloadSizeAtPause + bytesTotal));
    qDebug() << nPercentage;
    emit progress(nPercentage);

    _Timer.start(5000);
}


void DownloadManagerHTTP::error(QNetworkReply::NetworkError code)
{
    qDebug() << __FUNCTION__ << "(" << code << ")"<<QTime::currentTime();
    downloadCompleteCheck=false;
}


void DownloadManagerHTTP::timeout()
{
    qDebug() << __FUNCTION__;
}
