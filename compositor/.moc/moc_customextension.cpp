/****************************************************************************
** Meta object code from reading C++ file 'customextension.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../customextension.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customextension.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QtWayland__CustomExtension_t {
    QByteArrayData data[12];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtWayland__CustomExtension_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtWayland__CustomExtension_t qt_meta_stringdata_QtWayland__CustomExtension = {
    {
QT_MOC_LITERAL(0, 0, 26), // "QtWayland::CustomExtension"
QT_MOC_LITERAL(1, 27, 15), // "requestReceived"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "text"
QT_MOC_LITERAL(4, 49, 5), // "value"
QT_MOC_LITERAL(5, 55, 10), // "initialize"
QT_MOC_LITERAL(6, 66, 19), // "QWaylandCompositor*"
QT_MOC_LITERAL(7, 86, 10), // "compositor"
QT_MOC_LITERAL(8, 97, 9), // "sendEvent"
QT_MOC_LITERAL(9, 107, 16), // "QWaylandSurface*"
QT_MOC_LITERAL(10, 124, 7), // "surface"
QT_MOC_LITERAL(11, 132, 4) // "time"

    },
    "QtWayland::CustomExtension\0requestReceived\0"
    "\0text\0value\0initialize\0QWaylandCompositor*\0"
    "compositor\0sendEvent\0QWaylandSurface*\0"
    "surface\0time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtWayland__CustomExtension[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   34,    2, 0x02 /* Public */,
       8,    4,   37,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    3,    4,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::UInt, QMetaType::QString, QMetaType::UInt,   10,   11,    3,    4,

       0        // eod
};

void QtWayland::CustomExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CustomExtension *_t = static_cast<CustomExtension *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: _t->initialize((*reinterpret_cast< QWaylandCompositor*(*)>(_a[1]))); break;
        case 2: _t->sendEvent((*reinterpret_cast< QWaylandSurface*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWaylandCompositor* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CustomExtension::*_t)(const QString & , uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomExtension::requestReceived)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QtWayland::CustomExtension::staticMetaObject = {
    { &QWaylandCompositorExtensionTemplate<CustomExtension>::staticMetaObject, qt_meta_stringdata_QtWayland__CustomExtension.data,
      qt_meta_data_QtWayland__CustomExtension,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtWayland::CustomExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtWayland::CustomExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtWayland__CustomExtension.stringdata0))
        return static_cast<void*>(const_cast< CustomExtension*>(this));
    if (!strcmp(_clname, "QtWaylandServer::qt_example_extension"))
        return static_cast< QtWaylandServer::qt_example_extension*>(const_cast< CustomExtension*>(this));
    return QWaylandCompositorExtensionTemplate<CustomExtension>::qt_metacast(_clname);
}

int QtWayland::CustomExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWaylandCompositorExtensionTemplate<CustomExtension>::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QtWayland::CustomExtension::requestReceived(const QString & _t1, uint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
