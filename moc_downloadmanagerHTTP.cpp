/****************************************************************************
** Meta object code from reading C++ file 'downloadmanagerHTTP.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "downloadmanagerHTTP.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadmanagerHTTP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadManagerHTTP[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   21,   20,   20, 0x05,
      45,   20,   20,   20, 0x05,
      64,   20,   20,   20, 0x05,
      93,   81,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     111,  107,   20,   20, 0x0a,
     126,   20,   20,   20, 0x0a,
     134,   20,   20,   20, 0x0a,
     143,   20,   20,   20, 0x08,
     154,   20,   20,   20, 0x08,
     169,   20,   20,   20, 0x08,
     205,  180,   20,   20, 0x08,
     242,  237,   20,   20, 0x08,
     277,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DownloadManagerHTTP[] = {
    "DownloadManagerHTTP\0\0qsLine\0"
    "addLine(QString)\0downloadComplete()\0"
    "downloadFailed()\0nPercentage\0progress(int)\0"
    "url\0download(QUrl)\0pause()\0resume()\0"
    "download()\0finishedHead()\0finished()\0"
    "bytesReceived,bytesTotal\0"
    "downloadProgress(qint64,qint64)\0code\0"
    "error(QNetworkReply::NetworkError)\0"
    "timeout()\0"
};

void DownloadManagerHTTP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DownloadManagerHTTP *_t = static_cast<DownloadManagerHTTP *>(_o);
        switch (_id) {
        case 0: _t->addLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->downloadComplete(); break;
        case 2: _t->downloadFailed(); break;
        case 3: _t->progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->download((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 5: _t->pause(); break;
        case 6: _t->resume(); break;
        case 7: _t->download(); break;
        case 8: _t->finishedHead(); break;
        case 9: _t->finished(); break;
        case 10: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 11: _t->error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 12: _t->timeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DownloadManagerHTTP::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DownloadManagerHTTP::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DownloadManagerHTTP,
      qt_meta_data_DownloadManagerHTTP, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownloadManagerHTTP::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownloadManagerHTTP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownloadManagerHTTP::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadManagerHTTP))
        return static_cast<void*>(const_cast< DownloadManagerHTTP*>(this));
    return QObject::qt_metacast(_clname);
}

int DownloadManagerHTTP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void DownloadManagerHTTP::addLine(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DownloadManagerHTTP::downloadComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void DownloadManagerHTTP::downloadFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void DownloadManagerHTTP::progress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
