/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "handlePlaySlot",
    "",
    "handleModelSlot",
    "handleNextSlot",
    "handlePrevSlot",
    "handleListSlot",
    "handlePositionSlot",
    "position",
    "handleDurationSlot",
    "duration",
    "setPosition",
    "onVolumeChanged",
    "volume",
    "onMuteToggled"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[15];
    char stringdata5[15];
    char stringdata6[15];
    char stringdata7[19];
    char stringdata8[9];
    char stringdata9[19];
    char stringdata10[9];
    char stringdata11[12];
    char stringdata12[16];
    char stringdata13[7];
    char stringdata14[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 14),  // "handlePlaySlot"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 15),  // "handleModelSlot"
        QT_MOC_LITERAL(43, 14),  // "handleNextSlot"
        QT_MOC_LITERAL(58, 14),  // "handlePrevSlot"
        QT_MOC_LITERAL(73, 14),  // "handleListSlot"
        QT_MOC_LITERAL(88, 18),  // "handlePositionSlot"
        QT_MOC_LITERAL(107, 8),  // "position"
        QT_MOC_LITERAL(116, 18),  // "handleDurationSlot"
        QT_MOC_LITERAL(135, 8),  // "duration"
        QT_MOC_LITERAL(144, 11),  // "setPosition"
        QT_MOC_LITERAL(156, 15),  // "onVolumeChanged"
        QT_MOC_LITERAL(172, 6),  // "volume"
        QT_MOC_LITERAL(179, 13)   // "onMuteToggled"
    },
    "MainWindow",
    "handlePlaySlot",
    "",
    "handleModelSlot",
    "handleNextSlot",
    "handlePrevSlot",
    "handleListSlot",
    "handlePositionSlot",
    "position",
    "handleDurationSlot",
    "duration",
    "setPosition",
    "onVolumeChanged",
    "volume",
    "onMuteToggled"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x0a,    1 /* Public */,
       3,    0,   75,    2, 0x0a,    2 /* Public */,
       4,    0,   76,    2, 0x0a,    3 /* Public */,
       5,    0,   77,    2, 0x0a,    4 /* Public */,
       6,    0,   78,    2, 0x0a,    5 /* Public */,
       7,    1,   79,    2, 0x0a,    6 /* Public */,
       9,    1,   82,    2, 0x0a,    8 /* Public */,
      11,    1,   85,    2, 0x0a,   10 /* Public */,
      12,    1,   88,    2, 0x0a,   12 /* Public */,
      14,    0,   91,    2, 0x0a,   14 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'handlePlaySlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleModelSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleNextSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePrevSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleListSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePositionSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleDurationSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onVolumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onMuteToggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handlePlaySlot(); break;
        case 1: _t->handleModelSlot(); break;
        case 2: _t->handleNextSlot(); break;
        case 3: _t->handlePrevSlot(); break;
        case 4: _t->handleListSlot(); break;
        case 5: _t->handlePositionSlot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->handleDurationSlot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setPosition((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->onVolumeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->onMuteToggled(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
