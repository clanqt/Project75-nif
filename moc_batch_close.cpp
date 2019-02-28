/****************************************************************************
** Meta object code from reading C++ file 'batch_close.h'
**
** Created: Thu Jan 31 08:08:24 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "batch_close.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batch_close.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Batch_Close[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      33,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   12,   12,   12, 0x08,
      70,   12,   12,   12, 0x08,
     109,   12,   12,   12, 0x08,
     139,   12,   12,   12, 0x08,
     180,   12,   12,   12, 0x08,
     226,   12,   12,   12, 0x08,
     265,   12,   12,   12, 0x08,
     306,   12,   12,   12, 0x08,
     346,   12,   12,   12, 0x08,
     380,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Batch_Close[] = {
    "Batch_Close\0\0goto_next_vihecle()\0"
    "goto_next_batch()\0odo_reading_slot()\0"
    "on_lineEdit_manuf_bale_returnPressed()\0"
    "on_pushButton_close_clicked()\0"
    "on_lineEdit_bull_reading_returnPressed()\0"
    "on_lineEdit_generator_reading_returnPressed()\0"
    "on_lineEdit_eb_reading_returnPressed()\0"
    "on_pushButton_goto_odo_reading_clicked()\0"
    "on_lineEdit_odo_reading_returnPressed()\0"
    "on_pushButton_close_odo_clicked()\0"
    "on_pushButton_odo_save_clicked()\0"
};

void Batch_Close::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Batch_Close *_t = static_cast<Batch_Close *>(_o);
        switch (_id) {
        case 0: _t->goto_next_vihecle(); break;
        case 1: _t->goto_next_batch(); break;
        case 2: _t->odo_reading_slot(); break;
        case 3: _t->on_lineEdit_manuf_bale_returnPressed(); break;
        case 4: _t->on_pushButton_close_clicked(); break;
        case 5: _t->on_lineEdit_bull_reading_returnPressed(); break;
        case 6: _t->on_lineEdit_generator_reading_returnPressed(); break;
        case 7: _t->on_lineEdit_eb_reading_returnPressed(); break;
        case 8: _t->on_pushButton_goto_odo_reading_clicked(); break;
        case 9: _t->on_lineEdit_odo_reading_returnPressed(); break;
        case 10: _t->on_pushButton_close_odo_clicked(); break;
        case 11: _t->on_pushButton_odo_save_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Batch_Close::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Batch_Close::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Batch_Close,
      qt_meta_data_Batch_Close, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Batch_Close::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Batch_Close::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Batch_Close::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Batch_Close))
        return static_cast<void*>(const_cast< Batch_Close*>(this));
    return QWidget::qt_metacast(_clname);
}

int Batch_Close::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Batch_Close::goto_next_vihecle()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Batch_Close::goto_next_batch()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
