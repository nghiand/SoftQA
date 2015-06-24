/****************************************************************************
** Meta object code from reading C++ file 'test_findrootmaxcommontree.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test_findrootmaxcommontree.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_findrootmaxcommontree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_test_findRootMaxCommonTree[] = {

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
      28,   27,   27,   27, 0x08,
      58,   27,   27,   27, 0x08,
      77,   27,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_test_findRootMaxCommonTree[] = {
    "test_findRootMaxCommonTree\0\0"
    "notExistsPairOfMatchedNodes()\0"
    "dataInRootsEqual()\0dataInRootsAreDifferent()\0"
};

void test_findRootMaxCommonTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        test_findRootMaxCommonTree *_t = static_cast<test_findRootMaxCommonTree *>(_o);
        switch (_id) {
        case 0: _t->notExistsPairOfMatchedNodes(); break;
        case 1: _t->dataInRootsEqual(); break;
        case 2: _t->dataInRootsAreDifferent(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData test_findRootMaxCommonTree::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject test_findRootMaxCommonTree::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_test_findRootMaxCommonTree,
      qt_meta_data_test_findRootMaxCommonTree, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &test_findRootMaxCommonTree::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *test_findRootMaxCommonTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *test_findRootMaxCommonTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_test_findRootMaxCommonTree))
        return static_cast<void*>(const_cast< test_findRootMaxCommonTree*>(this));
    return QObject::qt_metacast(_clname);
}

int test_findRootMaxCommonTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
