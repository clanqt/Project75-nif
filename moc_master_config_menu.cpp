/****************************************************************************
** Meta object code from reading C++ file 'master_config_menu.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "master_config_menu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'master_config_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Master_Config_Menu[] = {

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
      20,   19,   19,   19, 0x08,
      53,   19,   19,   19, 0x08,
      84,   19,   19,   19, 0x08,
     116,   19,   19,   19, 0x08,
     149,   19,   19,   19, 0x08,
     178,   19,   19,   19, 0x08,
     207,   19,   19,   19, 0x08,
     243,   19,   19,   19, 0x08,
     283,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Master_Config_Menu[] = {
    "Master_Config_Menu\0\0"
    "on_pushButton_Customer_clicked()\0"
    "on_pushButton_fuel_2_clicked()\0"
    "on_pushButton_expense_clicked()\0"
    "on_pushButton_Employee_clicked()\0"
    "on_pushButton_fuel_clicked()\0"
    "on_pushButton_save_clicked()\0"
    "on_pushButton_user_master_clicked()\0"
    "on_pushButton_save_app_config_clicked()\0"
    "on_pushButton_app_config_clicked()\0"
};

void Master_Config_Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Master_Config_Menu *_t = static_cast<Master_Config_Menu *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_Customer_clicked(); break;
        case 1: _t->on_pushButton_fuel_2_clicked(); break;
        case 2: _t->on_pushButton_expense_clicked(); break;
        case 3: _t->on_pushButton_Employee_clicked(); break;
        case 4: _t->on_pushButton_fuel_clicked(); break;
        case 5: _t->on_pushButton_save_clicked(); break;
        case 6: _t->on_pushButton_user_master_clicked(); break;
        case 7: _t->on_pushButton_save_app_config_clicked(); break;
        case 8: _t->on_pushButton_app_config_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Master_Config_Menu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Master_Config_Menu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Master_Config_Menu,
      qt_meta_data_Master_Config_Menu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Master_Config_Menu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Master_Config_Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Master_Config_Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Master_Config_Menu))
        return static_cast<void*>(const_cast< Master_Config_Menu*>(this));
    return QWidget::qt_metacast(_clname);
}

int Master_Config_Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
