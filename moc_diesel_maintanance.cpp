/****************************************************************************
** Meta object code from reading C++ file 'diesel_maintanance.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "diesel_maintanance.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diesel_maintanance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Diesel_Maintanance[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      53,   19,   19,   19, 0x08,
      83,   19,   19,   19, 0x08,
     112,   19,   19,   19, 0x08,
     152,   19,   19,   19, 0x08,
     186,   19,   19,   19, 0x08,
     229,   19,   19,   19, 0x08,
     268,   19,   19,   19, 0x08,
     311,  306,   19,   19, 0x08,
     353,   19,   19,   19, 0x08,
     382,   19,   19,   19, 0x08,
     417,   19,   19,   19, 0x08,
     459,  306,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Diesel_Maintanance[] = {
    "Diesel_Maintanance\0\0"
    "on_pushButton_purchase_clicked()\0"
    "on_pushButton_usage_clicked()\0"
    "on_pushButton_bull_clicked()\0"
    "on_pushButton_company_vehicle_clicked()\0"
    "on_pushButton_generator_clicked()\0"
    "on_lineEdit_today_parchase_returnPressed()\0"
    "on_lineEdit_bill_value_returnPressed()\0"
    "on_lineEdit_bunk_name_returnPressed()\0"
    "arg1\0on_lineEdit_bunk_name_textEdited(QString)\0"
    "on_pushButton_save_clicked()\0"
    "on_pushButton_save_usage_clicked()\0"
    "on_lineEdit_meter_reading_returnPressed()\0"
    "on_lineEdit_today_parchase_textChanged(QString)\0"
};

void Diesel_Maintanance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Diesel_Maintanance *_t = static_cast<Diesel_Maintanance *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_purchase_clicked(); break;
        case 1: _t->on_pushButton_usage_clicked(); break;
        case 2: _t->on_pushButton_bull_clicked(); break;
        case 3: _t->on_pushButton_company_vehicle_clicked(); break;
        case 4: _t->on_pushButton_generator_clicked(); break;
        case 5: _t->on_lineEdit_today_parchase_returnPressed(); break;
        case 6: _t->on_lineEdit_bill_value_returnPressed(); break;
        case 7: _t->on_lineEdit_bunk_name_returnPressed(); break;
        case 8: _t->on_lineEdit_bunk_name_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_save_clicked(); break;
        case 10: _t->on_pushButton_save_usage_clicked(); break;
        case 11: _t->on_lineEdit_meter_reading_returnPressed(); break;
        case 12: _t->on_lineEdit_today_parchase_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Diesel_Maintanance::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Diesel_Maintanance::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Diesel_Maintanance,
      qt_meta_data_Diesel_Maintanance, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Diesel_Maintanance::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Diesel_Maintanance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Diesel_Maintanance::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Diesel_Maintanance))
        return static_cast<void*>(const_cast< Diesel_Maintanance*>(this));
    return QWidget::qt_metacast(_clname);
}

int Diesel_Maintanance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
