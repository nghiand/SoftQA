/****************************************************************************
** Meta object code from reading C++ file 'test_computecommontree.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test_computecommontree.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_computecommontree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_test_computeCommonTree[] = {

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
      24,   23,   23,   23, 0x08,
      50,   23,   23,   23, 0x08,
      74,   23,   23,   23, 0x08,
      99,   23,   23,   23, 0x08,
     129,   23,   23,   23, 0x08,
     145,   23,   23,   23, 0x08,
     159,   23,   23,   23, 0x08,
     173,   23,   23,   23, 0x08,
     187,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_test_computeCommonTree[] = {
    "test_computeCommonTree\0\0"
    "differentNumbersInRoots()\0"
    "nonSubTreeOnFirstRoot()\0"
    "nonSubTreeOnSecondRoot()\0"
    "notExistsPairOfMatchedChild()\0"
    "twoTreesEqual()\0randomTest1()\0"
    "randomTest2()\0randomTest3()\0randomTest4()\0"
};

void test_computeCommonTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        test_computeCommonTree *_t = static_cast<test_computeCommonTree *>(_o);
        switch (_id) {
        case 0: _t->differentNumbersInRoots(); break;
        case 1: _t->nonSubTreeOnFirstRoot(); break;
        case 2: _t->nonSubTreeOnSecondRoot(); break;
        case 3: _t->notExistsPairOfMatchedChild(); break;
        case 4: _t->twoTreesEqual(); break;
        case 5: _t->randomTest1(); break;
        case 6: _t->randomTest2(); break;
        case 7: _t->randomTest3(); break;
        case 8: _t->randomTest4(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData test_computeCommonTree::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject test_computeCommonTree::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_test_computeCommonTree,
      qt_meta_data_test_computeCommonTree, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &test_computeCommonTree::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *test_computeCommonTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *test_computeCommonTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_test_computeCommonTree))
        return static_cast<void*>(const_cast< test_computeCommonTree*>(this));
    return QObject::qt_metacast(_clname);
}

int test_computeCommonTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
