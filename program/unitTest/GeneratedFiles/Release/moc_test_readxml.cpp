/****************************************************************************
** Meta object code from reading C++ file 'test_readxml.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test_readxml.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_readxml.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_test_readXML[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      29,   13,   13,   13, 0x08,
      45,   13,   13,   13, 0x08,
      63,   13,   13,   13, 0x08,
      82,   13,   13,   13, 0x08,
      93,   13,   13,   13, 0x08,
     105,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_test_readXML[] = {
    "test_readXML\0\0wrongFirstID()\0"
    "wrongSecondID()\0existsNotNumber()\0"
    "coincidedNumbers()\0overSize()\0emptyTree()\0"
    "severalNodesOnBothTree()\0"
};

void test_readXML::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        test_readXML *_t = static_cast<test_readXML *>(_o);
        switch (_id) {
        case 0: _t->wrongFirstID(); break;
        case 1: _t->wrongSecondID(); break;
        case 2: _t->existsNotNumber(); break;
        case 3: _t->coincidedNumbers(); break;
        case 4: _t->overSize(); break;
        case 5: _t->emptyTree(); break;
        case 6: _t->severalNodesOnBothTree(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData test_readXML::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject test_readXML::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_test_readXML,
      qt_meta_data_test_readXML, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &test_readXML::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *test_readXML::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *test_readXML::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_test_readXML))
        return static_cast<void*>(const_cast< test_readXML*>(this));
    return QObject::qt_metacast(_clname);
}

int test_readXML::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
