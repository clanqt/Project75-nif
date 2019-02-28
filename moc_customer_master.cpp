/****************************************************************************
** Meta object code from reading C++ file 'customer_master.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "customer_master.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customer_master.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Customer_Master[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      60,   16,   16,   16, 0x08,
      97,   16,   16,   16, 0x08,
     134,   16,   16,   16, 0x08,
     173,   16,   16,   16, 0x08,
     218,   16,   16,   16, 0x08,
     258,   16,   16,   16, 0x08,
     304,   16,   16,   16, 0x08,
     357,  352,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Customer_Master[] = {
    "Customer_Master\0\0"
    "on_lineEdit_vehicle_number_returnPressed()\0"
    "on_pushButton_vehicle_save_clicked()\0"
    "on_lineEdit_reg_name_returnPressed()\0"
    "on_lineEdit_reg_length_returnPressed()\0"
    "on_lineEdit_reg_length_inche_returnPressed()\0"
    "on_lineEdit_reg_breadth_returnPressed()\0"
    "on_lineEdit_reg_breadth_inche_returnPressed()\0"
    "on_lineEdit_reg_opening_balance_returnPressed()\0"
    "arg1\0on_lineEdit_vehicle_number_textEdited(QString)\0"
};

void Customer_Master::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Customer_Master *_t = static_cast<Customer_Master *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_vehicle_number_returnPressed(); break;
        case 1: _t->on_pushButton_vehicle_save_clicked(); break;
        case 2: _t->on_lineEdit_reg_name_returnPressed(); break;
        case 3: _t->on_lineEdit_reg_length_returnPressed(); break;
        case 4: _t->on_lineEdit_reg_length_inche_returnPressed(); break;
        case 5: _t->on_lineEdit_reg_breadth_returnPressed(); break;
        case 6: _t->on_lineEdit_reg_breadth_inche_returnPressed(); break;
        case 7: _t->on_lineEdit_reg_opening_balance_returnPressed(); break;
        case 8: _t->on_lineEdit_vehicle_number_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Customer_Master::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Customer_Master::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Customer_Master,
      qt_meta_data_Customer_Master, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Customer_Master::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Customer_Master::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Customer_Master::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Customer_Master))
        return static_cast<void*>(const_cast< Customer_Master*>(this));
    return QWidget::qt_metacast(_clname);
}

int Customer_Master::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
