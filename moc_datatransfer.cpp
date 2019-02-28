/****************************************************************************
** Meta object code from reading C++ file 'datatransfer.h'
**
** Created: Thu Jan 31 08:08:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datatransfer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datatransfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataTransfer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      45,   13,   13,   13, 0x08,
      78,   13,   13,   13, 0x08,
     109,   13,   13,   13, 0x08,
     145,  140,   13,   13, 0x08,
     193,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DataTransfer[] = {
    "DataTransfer\0\0on_pushButton_upload_clicked()\0"
    "on_pushButton_download_clicked()\0"
    "on_pushButton_backup_clicked()\0"
    "on_pushButton_cancel_clicked()\0arg1\0"
    "on_comboBox_db_csv_currentIndexChanged(QString)\0"
    "on_pushButton_clicked()\0"
};

void DataTransfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DataTransfer *_t = static_cast<DataTransfer *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_upload_clicked(); break;
        case 1: _t->on_pushButton_download_clicked(); break;
        case 2: _t->on_pushButton_backup_clicked(); break;
        case 3: _t->on_pushButton_cancel_clicked(); break;
        case 4: _t->on_comboBox_db_csv_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DataTransfer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DataTransfer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DataTransfer,
      qt_meta_data_DataTransfer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataTransfer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataTransfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataTransfer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataTransfer))
        return static_cast<void*>(const_cast< DataTransfer*>(this));
    return QDialog::qt_metacast(_clname);
}

int DataTransfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
