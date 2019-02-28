/****************************************************************************
** Meta object code from reading C++ file 'downloadmanager.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "downloadmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   17,   16,   16, 0x05,
      53,   41,   16,   16, 0x05,
      67,   16,   16,   16, 0x05,
      86,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     107,  103,   16,   16, 0x0a,
     122,   16,   16,   16, 0x0a,
     130,   16,   16,   16, 0x0a,
     139,   17,   16,   16, 0x08,
     161,   41,   16,   16, 0x08,
     180,   16,   16,   16, 0x08,
     204,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DownloadManager[] = {
    "DownloadManager\0\0qsLine\0addLine(QString)\0"
    "nPercentage\0progress(int)\0downloadComplete()\0"
    "downloadFailed()\0url\0download(QUrl)\0"
    "pause()\0resume()\0localAddLine(QString)\0"
    "localProgress(int)\0localDownloadComplete()\0"
    "localDownloadCanceled()\0"
};

void DownloadManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DownloadManager *_t = static_cast<DownloadManager *>(_o);
        switch (_id) {
        case 0: _t->addLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->downloadComplete(); break;
        case 3: _t->downloadFailed(); break;
        case 4: _t->download((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 5: _t->pause(); break;
        case 6: _t->resume(); break;
        case 7: _t->localAddLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->localProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->localDownloadComplete(); break;
        case 10: _t->localDownloadCanceled(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DownloadManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DownloadManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DownloadManager,
      qt_meta_data_DownloadManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownloadManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownloadManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownloadManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadManager))
        return static_cast<void*>(const_cast< DownloadManager*>(this));
    return QObject::qt_metacast(_clname);
}

int DownloadManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DownloadManager::addLine(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DownloadManager::progress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DownloadManager::downloadComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void DownloadManager::downloadFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
