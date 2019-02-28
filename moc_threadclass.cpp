/****************************************************************************
** Meta object code from reading C++ file 'threadclass.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "threadclass.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      34,   12,   12,   12, 0x05,
      49,   12,   12,   12, 0x05,
      60,   12,   12,   12, 0x05,
      80,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,   99,   12,   12, 0x0a,
     134,   12,   12,   12, 0x0a,
     149,   12,   12,   12, 0x08,
     164,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ThreadClass[] = {
    "ThreadClass\0\0Thread_stopped(bool)\0"
    "thread_error()\0readData()\0thread_data_saved()\0"
    "UploadBackground()\0rpy\0"
    "http_get_server_reply(QString)\0"
    "start_Thread()\0errorHandler()\0"
    "pausethread()\0"
};

void ThreadClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadClass *_t = static_cast<ThreadClass *>(_o);
        switch (_id) {
        case 0: _t->Thread_stopped((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->thread_error(); break;
        case 2: _t->readData(); break;
        case 3: _t->thread_data_saved(); break;
        case 4: _t->UploadBackground(); break;
        case 5: _t->http_get_server_reply((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->start_Thread(); break;
        case 7: _t->errorHandler(); break;
        case 8: _t->pausethread(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadClass::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadClass,
      qt_meta_data_ThreadClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadClass))
        return static_cast<void*>(const_cast< ThreadClass*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ThreadClass::Thread_stopped(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadClass::thread_error()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ThreadClass::readData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ThreadClass::thread_data_saved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ThreadClass::UploadBackground()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
