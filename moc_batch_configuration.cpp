/****************************************************************************
** Meta object code from reading C++ file 'batch_configuration.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "batch_configuration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batch_configuration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Batch_Configuration[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      54,   20,   20,   20, 0x0a,
      89,   20,   20,   20, 0x0a,
     121,   20,   20,   20, 0x0a,
     150,   20,   20,   20, 0x0a,
     178,   20,   20,   20, 0x0a,
     218,   20,   20,   20, 0x0a,
     259,   20,   20,   20, 0x0a,
     305,  300,   20,   20, 0x0a,
     350,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Batch_Configuration[] = {
    "Batch_Configuration\0\0"
    "on_pushButton_purchase_clicked()\0"
    "on_pushButton_Production_clicked()\0"
    "on_pushButton_Company_clicked()\0"
    "on_pushButton_auto_clicked()\0"
    "on_pushButton_van_clicked()\0"
    "on_pushButton_Production_open_clicked()\0"
    "on_pushButton_Production_close_clicked()\0"
    "on_groupBox_company_production_clicked()\0"
    "arg1\0on_groupBox_company_production_toggled(bool)\0"
    "on_pushButton_purchase_save_clicked()\0"
};

void Batch_Configuration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Batch_Configuration *_t = static_cast<Batch_Configuration *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_purchase_clicked(); break;
        case 1: _t->on_pushButton_Production_clicked(); break;
        case 2: _t->on_pushButton_Company_clicked(); break;
        case 3: _t->on_pushButton_auto_clicked(); break;
        case 4: _t->on_pushButton_van_clicked(); break;
        case 5: _t->on_pushButton_Production_open_clicked(); break;
        case 6: _t->on_pushButton_Production_close_clicked(); break;
        case 7: _t->on_groupBox_company_production_clicked(); break;
        case 8: _t->on_groupBox_company_production_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_purchase_save_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Batch_Configuration::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Batch_Configuration::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Batch_Configuration,
      qt_meta_data_Batch_Configuration, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Batch_Configuration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Batch_Configuration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Batch_Configuration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Batch_Configuration))
        return static_cast<void*>(const_cast< Batch_Configuration*>(this));
    return QWidget::qt_metacast(_clname);
}

int Batch_Configuration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
