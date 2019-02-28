/****************************************************************************
** Meta object code from reading C++ file 'staff_cash.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "staff_cash.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'staff_cash.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Staff_Cash[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      41,   11,   11,   11, 0x0a,
      68,   11,   11,   11, 0x0a,
     102,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Staff_Cash[] = {
    "Staff_Cash\0\0on_pushButton_from_clicked()\0"
    "on_pushButton_to_clicked()\0"
    "on_pushButton_from_save_clicked()\0"
    "on_pushButton_from_save_2_clicked()\0"
};

void Staff_Cash::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Staff_Cash *_t = static_cast<Staff_Cash *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_from_clicked(); break;
        case 1: _t->on_pushButton_to_clicked(); break;
        case 2: _t->on_pushButton_from_save_clicked(); break;
        case 3: _t->on_pushButton_from_save_2_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Staff_Cash::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Staff_Cash::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Staff_Cash,
      qt_meta_data_Staff_Cash, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Staff_Cash::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Staff_Cash::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Staff_Cash::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Staff_Cash))
        return static_cast<void*>(const_cast< Staff_Cash*>(this));
    return QWidget::qt_metacast(_clname);
}

int Staff_Cash::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
