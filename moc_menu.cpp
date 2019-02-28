/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Menu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   19,    5,    5, 0x0a,
      54,    5,    5,    5, 0x0a,
      65,    5,    5,    5, 0x08,
     104,    5,    5,    5, 0x08,
     137,    5,    5,    5, 0x08,
     175,    5,    5,    5, 0x08,
     211,    5,    5,    5, 0x08,
     245,    5,    5,    5, 0x08,
     281,    5,    5,    5, 0x08,
     323,    5,    5,    5, 0x08,
     360,    5,    5,    5, 0x08,
     398,    5,    5,    5, 0x08,
     435,    5,    5,    5, 0x08,
     466,    5,    5,    5, 0x08,
     498,    5,    5,    5, 0x08,
     531,    5,    5,    5, 0x08,
     563,    5,    5,    5, 0x08,
     596,    5,    5,    5, 0x08,
     634,    5,    5,    5, 0x08,
     666,    5,    5,    5, 0x08,
     701,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Menu[] = {
    "Menu\0\0data_saved()\0rpy\0"
    "http_get_server_reply(QString)\0"
    "callMenu()\0on_pushButton_device_setting_clicked()\0"
    "on_pushButton_download_clicked()\0"
    "on_pushButton_Configuration_clicked()\0"
    "on_pushButton_rate_config_clicked()\0"
    "on_pushButton_Day_Close_clicked()\0"
    "on_pushButton_Shift_Close_clicked()\0"
    "on_pushButton_Other_batch_close_clicked()\0"
    "on_pushButton_batch_config_clicked()\0"
    "on_pushButton_master_config_clicked()\0"
    "on_pushButton_input_config_clicked()\0"
    "on_pushButton_diesel_clicked()\0"
    "on_pushButton_Reports_clicked()\0"
    "on_pushButton_purchase_clicked()\0"
    "on_pushButton_payment_clicked()\0"
    "on_pushButton_Day_Open_clicked()\0"
    "on_pushButton_Data_transfer_clicked()\0"
    "on_pushButton_Receipt_clicked()\0"
    "on_pushButton_Reset_Data_clicked()\0"
    "on_pushButton_Void_Last_Bill_clicked()\0"
};

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Menu *_t = static_cast<Menu *>(_o);
        switch (_id) {
        case 0: _t->data_saved(); break;
        case 1: _t->http_get_server_reply((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->callMenu(); break;
        case 3: _t->on_pushButton_device_setting_clicked(); break;
        case 4: _t->on_pushButton_download_clicked(); break;
        case 5: _t->on_pushButton_Configuration_clicked(); break;
        case 6: _t->on_pushButton_rate_config_clicked(); break;
        case 7: _t->on_pushButton_Day_Close_clicked(); break;
        case 8: _t->on_pushButton_Shift_Close_clicked(); break;
        case 9: _t->on_pushButton_Other_batch_close_clicked(); break;
        case 10: _t->on_pushButton_batch_config_clicked(); break;
        case 11: _t->on_pushButton_master_config_clicked(); break;
        case 12: _t->on_pushButton_input_config_clicked(); break;
        case 13: _t->on_pushButton_diesel_clicked(); break;
        case 14: _t->on_pushButton_Reports_clicked(); break;
        case 15: _t->on_pushButton_purchase_clicked(); break;
        case 16: _t->on_pushButton_payment_clicked(); break;
        case 17: _t->on_pushButton_Day_Open_clicked(); break;
        case 18: _t->on_pushButton_Data_transfer_clicked(); break;
        case 19: _t->on_pushButton_Receipt_clicked(); break;
        case 20: _t->on_pushButton_Reset_Data_clicked(); break;
        case 21: _t->on_pushButton_Void_Last_Bill_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Menu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Menu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Menu,
      qt_meta_data_Menu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Menu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Menu))
        return static_cast<void*>(const_cast< Menu*>(this));
    return QWidget::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Menu::data_saved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
