/****************************************************************************
** Meta object code from reading C++ file 'customer_details.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "customer_details.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customer_details.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Customer_Details[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      53,   17,   17,   17, 0x08,
      86,   17,   17,   17, 0x08,
     121,  116,   17,   17, 0x08,
     160,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Customer_Details[] = {
    "Customer_Details\0\0on_lineEdit_Excess_returnPressed()\0"
    "on_lineEdit_paid_returnPressed()\0"
    "on_pushButton_print_clicked()\0arg1\0"
    "on_lineEdit_Excess_textEdited(QString)\0"
    "on_pushButton_print_4_clicked()\0"
};

void Customer_Details::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Customer_Details *_t = static_cast<Customer_Details *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_Excess_returnPressed(); break;
        case 1: _t->on_lineEdit_paid_returnPressed(); break;
        case 2: _t->on_pushButton_print_clicked(); break;
        case 3: _t->on_lineEdit_Excess_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_print_4_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Customer_Details::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Customer_Details::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Customer_Details,
      qt_meta_data_Customer_Details, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Customer_Details::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Customer_Details::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Customer_Details::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Customer_Details))
        return static_cast<void*>(const_cast< Customer_Details*>(this));
    return QWidget::qt_metacast(_clname);
}

int Customer_Details::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
