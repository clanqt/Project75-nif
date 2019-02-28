/****************************************************************************
** Meta object code from reading C++ file 'downloadmanagerFTP.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "downloadmanagerFTP.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadmanagerFTP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadManagerFTP[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   20,   19,   19, 0x05,
      44,   19,   19,   19, 0x05,
      75,   63,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   89,   19,   19, 0x0a,
     108,   19,   19,   19, 0x0a,
     116,   19,   19,   19, 0x0a,
     125,   19,   19,   19, 0x08,
     136,   19,   19,   19, 0x08,
     152,  147,   19,   19, 0x08,
     187,   19,   19,   19, 0x08,
     203,  197,   19,   19, 0x08,
     224,  221,   19,   19, 0x08,
     253,  244,   19,   19, 0x08,
     296,  279,   19,   19, 0x08,
     325,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DownloadManagerFTP[] = {
    "DownloadManagerFTP\0\0qsLine\0addLine(QString)\0"
    "downloadComplete()\0nPercentage\0"
    "progress(int)\0url\0download(QUrl)\0"
    "pause()\0resume()\0download()\0finished()\0"
    "code\0error(QNetworkReply::NetworkError)\0"
    "timeout()\0state\0stateChanged(int)\0id\0"
    "commandStarted(int)\0id,error\0"
    "commandFinished(int,bool)\0replyCode,detail\0"
    "rawCommandReply(int,QString)\0readyRead()\0"
};

void DownloadManagerFTP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DownloadManagerFTP *_t = static_cast<DownloadManagerFTP *>(_o);
        switch (_id) {
        case 0: _t->addLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->downloadComplete(); break;
        case 2: _t->progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->download((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 4: _t->pause(); break;
        case 5: _t->resume(); break;
        case 6: _t->download(); break;
        case 7: _t->finished(); break;
        case 8: _t->error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 9: _t->timeout(); break;
        case 10: _t->stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->commandStarted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->commandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->rawCommandReply((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 14: _t->readyRead(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DownloadManagerFTP::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DownloadManagerFTP::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DownloadManagerFTP,
      qt_meta_data_DownloadManagerFTP, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownloadManagerFTP::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownloadManagerFTP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownloadManagerFTP::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadManagerFTP))
        return static_cast<void*>(const_cast< DownloadManagerFTP*>(this));
    return QObject::qt_metacast(_clname);
}

int DownloadManagerFTP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void DownloadManagerFTP::addLine(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DownloadManagerFTP::downloadComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void DownloadManagerFTP::progress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
