/****************************************************************************
** Meta object code from reading C++ file 'payment.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "payment.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'payment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Payment[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      38,    8,    8,    8, 0x0a,
      81,    8,    8,    8, 0x0a,
     118,    8,    8,    8, 0x0a,
     160,    8,    8,    8, 0x0a,
     190,    8,    8,    8, 0x0a,
     235,    8,    8,    8, 0x0a,
     277,    8,    8,    8, 0x0a,
     321,    8,    8,    8, 0x0a,
     352,    8,    8,    8, 0x0a,
     397,    8,    8,    8, 0x0a,
     439,    8,    8,    8, 0x0a,
     483,    8,    8,    8, 0x0a,
     514,    8,    8,    8, 0x0a,
     554,    8,    8,    8, 0x0a,
     591,    8,    8,    8, 0x0a,
     621,    8,    8,    8, 0x08,
     658,  653,    8,    8, 0x08,
     705,  653,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Payment[] = {
    "Payment\0\0on_pushButton_Husk_clicked()\0"
    "on_lineEdit_vehicle_number_returnPressed()\0"
    "on_lineEdit_paid_amt_returnPressed()\0"
    "on_pushButton_husk_payment_save_clicked()\0"
    "on_pushButton_other_clicked()\0"
    "on_lineEdit_diesel_bunk_name_returnPressed()\0"
    "on_lineEdit_diesel_amount_returnPressed()\0"
    "on_pushButton_payment_diesel_save_clicked()\0"
    "on_pushButton_Diesel_clicked()\0"
    "on_lineEdit_labour_bunk_name_returnPressed()\0"
    "on_lineEdit_labour_amount_returnPressed()\0"
    "on_pushButton_payment_labour_save_clicked()\0"
    "on_pushButton_labour_clicked()\0"
    "on_lineEdit_labour_name_returnPressed()\0"
    "on_lineEdit_customer_returnPressed()\0"
    "on_pushButton_staff_clicked()\0"
    "on_pushButton_print_4_clicked()\0arg1\0"
    "on_lineEdit_vehicle_number_textEdited(QString)\0"
    "on_lineEdit_paid_amt_textEdited(QString)\0"
};

void Payment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Payment *_t = static_cast<Payment *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_Husk_clicked(); break;
        case 1: _t->on_lineEdit_vehicle_number_returnPressed(); break;
        case 2: _t->on_lineEdit_paid_amt_returnPressed(); break;
        case 3: _t->on_pushButton_husk_payment_save_clicked(); break;
        case 4: _t->on_pushButton_other_clicked(); break;
        case 5: _t->on_lineEdit_diesel_bunk_name_returnPressed(); break;
        case 6: _t->on_lineEdit_diesel_amount_returnPressed(); break;
        case 7: _t->on_pushButton_payment_diesel_save_clicked(); break;
        case 8: _t->on_pushButton_Diesel_clicked(); break;
        case 9: _t->on_lineEdit_labour_bunk_name_returnPressed(); break;
        case 10: _t->on_lineEdit_labour_amount_returnPressed(); break;
        case 11: _t->on_pushButton_payment_labour_save_clicked(); break;
        case 12: _t->on_pushButton_labour_clicked(); break;
        case 13: _t->on_lineEdit_labour_name_returnPressed(); break;
        case 14: _t->on_lineEdit_customer_returnPressed(); break;
        case 15: _t->on_pushButton_staff_clicked(); break;
        case 16: _t->on_pushButton_print_4_clicked(); break;
        case 17: _t->on_lineEdit_vehicle_number_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->on_lineEdit_paid_amt_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Payment::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Payment::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Payment,
      qt_meta_data_Payment, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Payment::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Payment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Payment::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Payment))
        return static_cast<void*>(const_cast< Payment*>(this));
    return QWidget::qt_metacast(_clname);
}

int Payment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
