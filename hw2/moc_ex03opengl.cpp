/****************************************************************************
** Meta object code from reading C++ file 'ex03opengl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ex03opengl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ex03opengl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ex03opengl_t {
    QByteArrayData data[10];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ex03opengl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ex03opengl_t qt_meta_stringdata_Ex03opengl = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Ex03opengl"
QT_MOC_LITERAL(1, 11, 4), // "zoom"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "text"
QT_MOC_LITERAL(4, 22, 4), // "setX"
QT_MOC_LITERAL(5, 27, 1), // "X"
QT_MOC_LITERAL(6, 29, 4), // "setY"
QT_MOC_LITERAL(7, 34, 1), // "Y"
QT_MOC_LITERAL(8, 36, 7), // "setZoom"
QT_MOC_LITERAL(9, 44, 1) // "Z"

    },
    "Ex03opengl\0zoom\0\0text\0setX\0X\0setY\0Y\0"
    "setZoom\0Z"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ex03opengl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    9,

       0        // eod
};

void Ex03opengl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ex03opengl *_t = static_cast<Ex03opengl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->zoom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setZoom((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Ex03opengl::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ex03opengl::zoom)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Ex03opengl::staticMetaObject = {
    { &CUgl::staticMetaObject, qt_meta_stringdata_Ex03opengl.data,
      qt_meta_data_Ex03opengl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ex03opengl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ex03opengl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ex03opengl.stringdata0))
        return static_cast<void*>(const_cast< Ex03opengl*>(this));
    return CUgl::qt_metacast(_clname);
}

int Ex03opengl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CUgl::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Ex03opengl::zoom(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
