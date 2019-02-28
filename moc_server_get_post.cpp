/****************************************************************************
** Meta object code from reading C++ file 'server_get_post.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "server_get_post.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server_get_post.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Server_Get_Post[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   16,   16,   16, 0x0a,
      74,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Server_Get_Post[] = {
    "Server_Get_Post\0\0read_server_reply(QString)\0"
    "replyFinished(QNetworkReply*)\0"
    "ThreadSlot()\0"
};

void Server_Get_Post::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Server_Get_Post *_t = static_cast<Server_Get_Post *>(_o);
        switch (_id) {
        case 0: _t->read_server_reply((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->ThreadSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Server_Get_Post::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Server_Get_Post::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Server_Get_Post,
      qt_meta_data_Server_Get_Post, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Server_Get_Post::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Server_Get_Post::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Server_Get_Post::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Server_Get_Post))
        return static_cast<void*>(const_cast< Server_Get_Post*>(this));
    return QWidget::qt_metacast(_clname);
}

int Server_Get_Post::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Server_Get_Post::read_server_reply(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
