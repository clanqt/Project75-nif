/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "settings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Settings[] = {

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
      10,    9,    9,    9, 0x0a,
      25,   21,    9,    9, 0x08,
      51,    9,    9,    9, 0x08,
      89,    9,    9,    9, 0x08,
     129,    9,    9,    9, 0x08,
     167,    9,    9,    9, 0x08,
     200,    9,    9,    9, 0x08,
     236,    9,    9,    9, 0x08,
     271,    9,    9,    9, 0x08,
     312,    9,    9,    9, 0x08,
     351,    9,    9,    9, 0x08,
     380,    9,    9,    9, 0x08,
     416,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Settings[] = {
    "Settings\0\0callMenu()\0str\0"
    "bill_title_entry(QString)\0"
    "on_pushButton_server_config_clicked()\0"
    "on_lineEdit_domain_name_returnPressed()\0"
    "on_pushButton_settings_back_clicked()\0"
    "on_pushButton_App_name_clicked()\0"
    "on_pushButton_device_name_clicked()\0"
    "on_pushButton_Bill_Title_clicked()\0"
    "on_pushButton_printer_settings_clicked()\0"
    "on_pushButton_device_setting_clicked()\0"
    "on_pushButton_save_clicked()\0"
    "on_pushButton_user_master_clicked()\0"
    "on_pushButton_customer_master_clicked()\0"
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Settings *_t = static_cast<Settings *>(_o);
        switch (_id) {
        case 0: _t->callMenu(); break;
        case 1: _t->bill_title_entry((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_server_config_clicked(); break;
        case 3: _t->on_lineEdit_domain_name_returnPressed(); break;
        case 4: _t->on_pushButton_settings_back_clicked(); break;
        case 5: _t->on_pushButton_App_name_clicked(); break;
        case 6: _t->on_pushButton_device_name_clicked(); break;
        case 7: _t->on_pushButton_Bill_Title_clicked(); break;
        case 8: _t->on_pushButton_printer_settings_clicked(); break;
        case 9: _t->on_pushButton_device_setting_clicked(); break;
        case 10: _t->on_pushButton_save_clicked(); break;
        case 11: _t->on_pushButton_user_master_clicked(); break;
        case 12: _t->on_pushButton_customer_master_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Settings::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Settings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Settings,
      qt_meta_data_Settings, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Settings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Settings))
        return static_cast<void*>(const_cast< Settings*>(this));
    return QWidget::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
