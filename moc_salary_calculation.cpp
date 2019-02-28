/****************************************************************************
** Meta object code from reading C++ file 'salary_calculation.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "salary_calculation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'salary_calculation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Salary_Calculation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   41,   19,   19, 0x08,
     100,   92,   19,   19, 0x08,
     133,   92,   19,   19, 0x08,
     163,   19,   19,   19, 0x08,
     198,   19,   19,   19, 0x08,
     230,   19,   19,   19, 0x08,
     259,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Salary_Calculation[] = {
    "Salary_Calculation\0\0goto_next_employee()\0"
    "arg1\0on_comboBox_name_currentIndexChanged(QString)\0"
    "checked\0on_checkBox_target_clicked(bool)\0"
    "on_checkBox_hrs_clicked(bool)\0"
    "on_lineEdit_target_returnPressed()\0"
    "on_lineEdit_hrs_returnPressed()\0"
    "on_pushButton_next_clicked()\0"
    "on_pushButton_save_emp_salary_clicked()\0"
};

void Salary_Calculation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Salary_Calculation *_t = static_cast<Salary_Calculation *>(_o);
        switch (_id) {
        case 0: _t->goto_next_employee(); break;
        case 1: _t->on_comboBox_name_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_checkBox_target_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_checkBox_hrs_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_lineEdit_target_returnPressed(); break;
        case 5: _t->on_lineEdit_hrs_returnPressed(); break;
        case 6: _t->on_pushButton_next_clicked(); break;
        case 7: _t->on_pushButton_save_emp_salary_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Salary_Calculation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Salary_Calculation::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Salary_Calculation,
      qt_meta_data_Salary_Calculation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Salary_Calculation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Salary_Calculation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Salary_Calculation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Salary_Calculation))
        return static_cast<void*>(const_cast< Salary_Calculation*>(this));
    return QWidget::qt_metacast(_clname);
}

int Salary_Calculation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Salary_Calculation::goto_next_employee()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
