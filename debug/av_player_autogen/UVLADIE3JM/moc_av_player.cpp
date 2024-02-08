/****************************************************************************
** Meta object code from reading C++ file 'av_player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/av_player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'av_player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_medex__av_player__av_player_t {
    QByteArrayData data[16];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_medex__av_player__av_player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_medex__av_player__av_player_t qt_meta_stringdata_medex__av_player__av_player = {
    {
QT_MOC_LITERAL(0, 0, 27), // "medex::av_player::av_player"
QT_MOC_LITERAL(1, 28, 12), // "start_signal"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 30), // "notify_interval_changed_signal"
QT_MOC_LITERAL(4, 73, 20), // "seek_finished_signal"
QT_MOC_LITERAL(5, 94, 7), // "int64_t"
QT_MOC_LITERAL(6, 102, 5), // "value"
QT_MOC_LITERAL(7, 108, 27), // "media_status_changed_signal"
QT_MOC_LITERAL(8, 136, 17), // "QtAV::MediaStatus"
QT_MOC_LITERAL(9, 154, 30), // "buffer_progress_changed_signal"
QT_MOC_LITERAL(10, 185, 12), // "error_signal"
QT_MOC_LITERAL(11, 198, 13), // "QtAV::AVError"
QT_MOC_LITERAL(12, 212, 11), // "stop_signal"
QT_MOC_LITERAL(13, 224, 13), // "paused_signal"
QT_MOC_LITERAL(14, 238, 20), // "speed_changed_signal"
QT_MOC_LITERAL(15, 259, 23) // "position_changed_signal"

    },
    "medex::av_player::av_player\0start_signal\0"
    "\0notify_interval_changed_signal\0"
    "seek_finished_signal\0int64_t\0value\0"
    "media_status_changed_signal\0"
    "QtAV::MediaStatus\0buffer_progress_changed_signal\0"
    "error_signal\0QtAV::AVError\0stop_signal\0"
    "paused_signal\0speed_changed_signal\0"
    "position_changed_signal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_medex__av_player__av_player[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    1,   66,    2, 0x06 /* Public */,
       7,    1,   69,    2, 0x06 /* Public */,
       9,    1,   72,    2, 0x06 /* Public */,
      10,    1,   75,    2, 0x06 /* Public */,
      12,    0,   78,    2, 0x06 /* Public */,
      13,    1,   79,    2, 0x06 /* Public */,
      14,    1,   82,    2, 0x06 /* Public */,
      15,    1,   85,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void medex::av_player::av_player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<av_player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start_signal(); break;
        case 1: _t->notify_interval_changed_signal(); break;
        case 2: _t->seek_finished_signal((*reinterpret_cast< int64_t(*)>(_a[1]))); break;
        case 3: _t->media_status_changed_signal((*reinterpret_cast< QtAV::MediaStatus(*)>(_a[1]))); break;
        case 4: _t->buffer_progress_changed_signal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->error_signal((*reinterpret_cast< QtAV::AVError(*)>(_a[1]))); break;
        case 6: _t->stop_signal(); break;
        case 7: _t->paused_signal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->speed_changed_signal((*reinterpret_cast< int64_t(*)>(_a[1]))); break;
        case 9: _t->position_changed_signal((*reinterpret_cast< int64_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QtAV::MediaStatus >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QtAV::AVError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (av_player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::start_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (av_player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::notify_interval_changed_signal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (av_player::*)(int64_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::seek_finished_signal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (av_player::*)(QtAV::MediaStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::media_status_changed_signal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (av_player::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::buffer_progress_changed_signal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (av_player::*)(QtAV::AVError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::error_signal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (av_player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::stop_signal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (av_player::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::paused_signal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (av_player::*)(int64_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::speed_changed_signal)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (av_player::*)(int64_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&av_player::position_changed_signal)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject medex::av_player::av_player::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_medex__av_player__av_player.data,
    qt_meta_data_medex__av_player__av_player,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *medex::av_player::av_player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *medex::av_player::av_player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_medex__av_player__av_player.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int medex::av_player::av_player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void medex::av_player::av_player::start_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void medex::av_player::av_player::notify_interval_changed_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void medex::av_player::av_player::seek_finished_signal(int64_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void medex::av_player::av_player::media_status_changed_signal(QtAV::MediaStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void medex::av_player::av_player::buffer_progress_changed_signal(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void medex::av_player::av_player::error_signal(QtAV::AVError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void medex::av_player::av_player::stop_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void medex::av_player::av_player::paused_signal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void medex::av_player::av_player::speed_changed_signal(int64_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void medex::av_player::av_player::position_changed_signal(int64_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
