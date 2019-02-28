/****************************************************************************
** Meta object code from reading C++ file 'employeemaster.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "employeemaster.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employeemaster.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EmployeeMaster[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      53,   15,   15,   15, 0x08,
      93,   15,   15,   15, 0x08,
     134,   15,   15,   15, 0x08,
     169,   15,   15,   15, 0x08,
     205,   15,   15,   15, 0x08,
     244,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EmployeeMaster[] = {
    "EmployeeMaster\0\0on_lineEdit_emp_name_returnPressed()\0"
    "on_lineEdit_emp_contact_returnPressed()\0"
    "on_lineEdit_rate_pe_hour_returnPressed()\0"
    "on_lineEdit_target_returnPressed()\0"
    "on_lineEdit_charges_returnPressed()\0"
    "on_lineEdit_op_balance_returnPressed()\0"
    "on_pushButton_purchase_save_clicked()\0"
};

void EmployeeMaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EmployeeMaster *_t = static_cast<EmployeeMaster *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_emp_name_returnPressed(); break;
        case 1: _t->on_lineEdit_emp_contact_returnPressed(); break;
        case 2: _t->on_lineEdit_rate_pe_hour_returnPressed(); break;
        case 3: _t->on_lineEdit_target_returnPressed(); break;
        case 4: _t->on_lineEdit_charges_returnPressed(); break;
        case 5: _t->on_lineEdit_op_balance_returnPressed(); break;
        case 6: _t->on_pushButton_purchase_save_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData EmployeeMaster::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EmployeeMaster::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EmployeeMaster,
      qt_meta_data_EmployeeMaster, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmployeeMaster::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmployeeMaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmployeeMaster::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmployeeMaster))
        return static_cast<void*>(const_cast< EmployeeMaster*>(this));
    return QWidget::qt_metacast(_clname);
}

int EmployeeMaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
