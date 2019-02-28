/****************************************************************************
** Meta object code from reading C++ file 'rate_config.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rate_config.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rate_config.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Rate_Config[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      44,   12,   12,   12, 0x08,
      76,   12,   12,   12, 0x08,
     107,   12,   12,   12, 0x08,
     139,   12,   12,   12, 0x08,
     168,   12,   12,   12, 0x08,
     205,   12,   12,   12, 0x08,
     244,   12,   12,   12, 0x08,
     284,   12,   12,   12, 0x08,
     326,   12,   12,   12, 0x08,
     363,   12,   12,   12, 0x08,
     401,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Rate_Config[] = {
    "Rate_Config\0\0on_pushButton_HP_cft_clicked()\0"
    "on_pushButton_HP_bale_clicked()\0"
    "on_pushButton_RP_cft_clicked()\0"
    "on_pushButton_RP_husk_clicked()\0"
    "on_pushButton_save_clicked()\0"
    "on_lineEdit_auto_cft_returnPressed()\0"
    "on_lineEdit_auto_count_returnPressed()\0"
    "on_lineEdit_company_cft_returnPressed()\0"
    "on_lineEdit_company_count_returnPressed()\0"
    "on_lineEdit_van_rate_returnPressed()\0"
    "on_lineEdit_van_count_returnPressed()\0"
    "on_pushButton_back_clicked()\0"
};

void Rate_Config::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Rate_Config *_t = static_cast<Rate_Config *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_HP_cft_clicked(); break;
        case 1: _t->on_pushButton_HP_bale_clicked(); break;
        case 2: _t->on_pushButton_RP_cft_clicked(); break;
        case 3: _t->on_pushButton_RP_husk_clicked(); break;
        case 4: _t->on_pushButton_save_clicked(); break;
        case 5: _t->on_lineEdit_auto_cft_returnPressed(); break;
        case 6: _t->on_lineEdit_auto_count_returnPressed(); break;
        case 7: _t->on_lineEdit_company_cft_returnPressed(); break;
        case 8: _t->on_lineEdit_company_count_returnPressed(); break;
        case 9: _t->on_lineEdit_van_rate_returnPressed(); break;
        case 10: _t->on_lineEdit_van_count_returnPressed(); break;
        case 11: _t->on_pushButton_back_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Rate_Config::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Rate_Config::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Rate_Config,
      qt_meta_data_Rate_Config, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Rate_Config::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Rate_Config::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Rate_Config::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Rate_Config))
        return static_cast<void*>(const_cast< Rate_Config*>(this));
    return QWidget::qt_metacast(_clname);
}

int Rate_Config::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
