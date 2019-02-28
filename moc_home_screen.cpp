/****************************************************************************
** Meta object code from reading C++ file 'home_screen.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "home_screen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'home_screen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Home_Screen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      56,   12,   12,   12, 0x08,
      91,   12,   12,   12, 0x08,
     133,   12,   12,   12, 0x08,
     177,   12,   12,   12, 0x08,
     211,  206,   12,   12, 0x08,
     257,  206,   12,   12, 0x08,
     305,   12,   12,   12, 0x08,
     339,   12,   12,   12, 0x08,
     376,   12,   12,   12, 0x08,
     415,   12,   12,   12, 0x08,
     455,   12,   12,   12, 0x08,
     496,  488,   12,   12, 0x08,
     531,  488,   12,   12, 0x08,
     564,   12,   12,   12, 0x08,
     606,  206,   12,   12, 0x08,
     652,   12,   12,   12, 0x08,
     689,   12,   12,   12, 0x08,
     735,   12,   12,   12, 0x08,
     780,   12,   12,   12, 0x08,
     828,   12,   12,   12, 0x08,
     872,  206,   12,   12, 0x08,
     919,  206,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Home_Screen[] = {
    "Home_Screen\0\0on_lineEdit_vehicle_number_returnPressed()\0"
    "on_lineEdit_height_returnPressed()\0"
    "on_lineEdit_customer_name_returnPressed()\0"
    "on_lineEdit_customer_mobile_returnPressed()\0"
    "on_pushButton_next_clicked()\0arg1\0"
    "on_lineEdit_customer_name_textEdited(QString)\0"
    "on_lineEdit_customer_mobile_textEdited(QString)\0"
    "on_lineEdit_count_returnPressed()\0"
    "on_lineEdit_reg_name_returnPressed()\0"
    "on_lineEdit_reg_length_returnPressed()\0"
    "on_lineEdit_reg_breadth_returnPressed()\0"
    "on_pushButton_reg_save_clicked()\0"
    "checked\0on_radioButton_count_clicked(bool)\0"
    "on_radioButton_cft_clicked(bool)\0"
    "on_lineEdit_height_inches_returnPressed()\0"
    "on_lineEdit_height_inches_textEdited(QString)\0"
    "on_lineEdit_reg_type_returnPressed()\0"
    "on_lineEdit_reg_breadth_inche_returnPressed()\0"
    "on_lineEdit_reg_length_inche_returnPressed()\0"
    "on_lineEdit_reg_opening_balance_returnPressed()\0"
    "on_pushButton_initial_config_save_clicked()\0"
    "on_lineEdit_vehicle_number_textEdited(QString)\0"
    "on_lineEdit_height_textEdited(QString)\0"
};

void Home_Screen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Home_Screen *_t = static_cast<Home_Screen *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_vehicle_number_returnPressed(); break;
        case 1: _t->on_lineEdit_height_returnPressed(); break;
        case 2: _t->on_lineEdit_customer_name_returnPressed(); break;
        case 3: _t->on_lineEdit_customer_mobile_returnPressed(); break;
        case 4: _t->on_pushButton_next_clicked(); break;
        case 5: _t->on_lineEdit_customer_name_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_customer_mobile_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_lineEdit_count_returnPressed(); break;
        case 8: _t->on_lineEdit_reg_name_returnPressed(); break;
        case 9: _t->on_lineEdit_reg_length_returnPressed(); break;
        case 10: _t->on_lineEdit_reg_breadth_returnPressed(); break;
        case 11: _t->on_pushButton_reg_save_clicked(); break;
        case 12: _t->on_radioButton_count_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_radioButton_cft_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_lineEdit_height_inches_returnPressed(); break;
        case 15: _t->on_lineEdit_height_inches_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_lineEdit_reg_type_returnPressed(); break;
        case 17: _t->on_lineEdit_reg_breadth_inche_returnPressed(); break;
        case 18: _t->on_lineEdit_reg_length_inche_returnPressed(); break;
        case 19: _t->on_lineEdit_reg_opening_balance_returnPressed(); break;
        case 20: _t->on_pushButton_initial_config_save_clicked(); break;
        case 21: _t->on_lineEdit_vehicle_number_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->on_lineEdit_height_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Home_Screen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Home_Screen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Home_Screen,
      qt_meta_data_Home_Screen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Home_Screen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Home_Screen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Home_Screen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Home_Screen))
        return static_cast<void*>(const_cast< Home_Screen*>(this));
    return QWidget::qt_metacast(_clname);
}

int Home_Screen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
