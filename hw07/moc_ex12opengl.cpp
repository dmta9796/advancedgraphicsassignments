/****************************************************************************
** Meta object code from reading C++ file 'ex12opengl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ex12opengl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ex12opengl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ex12opengl_t {
    QByteArrayData data[7];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ex12opengl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ex12opengl_t qt_meta_stringdata_Ex12opengl = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Ex12opengl"
QT_MOC_LITERAL(1, 11, 9), // "setPasses"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "pass"
QT_MOC_LITERAL(4, 27, 8), // "setImage"
QT_MOC_LITERAL(5, 36, 3), // "img"
QT_MOC_LITERAL(6, 40, 5) // "reset"

    },
    "Ex12opengl\0setPasses\0\0pass\0setImage\0"
    "img\0reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ex12opengl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void,

       0        // eod
};

void Ex12opengl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ex12opengl *_t = static_cast<Ex12opengl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPasses((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->reset(); break;
        default: ;
        }
    }
}

const QMetaObject Ex12opengl::staticMetaObject = {
    { &CUgl::staticMetaObject, qt_meta_stringdata_Ex12opengl.data,
      qt_meta_data_Ex12opengl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ex12opengl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ex12opengl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ex12opengl.stringdata0))
        return static_cast<void*>(const_cast< Ex12opengl*>(this));
    return CUgl::qt_metacast(_clname);
}

int Ex12opengl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CUgl::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
