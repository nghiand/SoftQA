/****************************************************************************
** Meta object code from reading C++ file 'test_readtree.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test_readtree.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_readtree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_test_readTree[] = {

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
      15,   14,   14,   14, 0x08,
      25,   14,   14,   14, 0x08,
      44,   14,   14,   14, 0x08,
      62,   14,   14,   14, 0x08,
      73,   14,   14,   14, 0x08,
      83,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_test_readTree[] = {
    "test_readTree\0\0wrongID()\0coincidedNumbers()\0"
    "existsNotNumber()\0overSize()\0oneNode()\0"
    "severalNodes()\0"
};

void test_readTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        test_readTree *_t = static_cast<test_readTree *>(_o);
        switch (_id) {
        case 0: _t->wrongID(); break;
        case 1: _t->coincidedNumbers(); break;
        case 2: _t->existsNotNumber(); break;
        case 3: _t->overSize(); break;
        case 4: _t->oneNode(); break;
        case 5: _t->severalNodes(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData test_readTree::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject test_readTree::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_test_readTree,
      qt_meta_data_test_readTree, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &test_readTree::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *test_readTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *test_readTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_test_readTree))
        return static_cast<void*>(const_cast< test_readTree*>(this));
    return QObject::qt_metacast(_clname);
}

int test_readTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
