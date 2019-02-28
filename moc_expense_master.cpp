/****************************************************************************
** Meta object code from reading C++ file 'expense_master.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "expense_master.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'expense_master.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Expense_Master[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      44,   15,   15,   15, 0x08,
      73,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Expense_Master[] = {
    "Expense_Master\0\0on_pushButton_add_clicked()\0"
    "on_pushButton_save_clicked()\0"
    "on_lineEdit_expense_name_returnPressed()\0"
};

void Expense_Master::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Expense_Master *_t = static_cast<Expense_Master *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_add_clicked(); break;
        case 1: _t->on_pushButton_save_clicked(); break;
        case 2: _t->on_lineEdit_expense_name_returnPressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Expense_Master::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Expense_Master::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Expense_Master,
      qt_meta_data_Expense_Master, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Expense_Master::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Expense_Master::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Expense_Master::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Expense_Master))
        return static_cast<void*>(const_cast< Expense_Master*>(this));
    return QWidget::qt_metacast(_clname);
}

int Expense_Master::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
