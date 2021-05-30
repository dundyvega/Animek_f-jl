/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Project/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[52];
    char stringdata0[380];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "contentAded"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 2), // "id"
QT_MOC_LITERAL(27, 4), // "cont"
QT_MOC_LITERAL(32, 14), // "ContentDialog*"
QT_MOC_LITERAL(47, 2), // "dl"
QT_MOC_LITERAL(50, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(72, 10), // "menuAction"
QT_MOC_LITERAL(83, 1), // "b"
QT_MOC_LITERAL(85, 11), // "nameChanged"
QT_MOC_LITERAL(97, 9), // "getByName"
QT_MOC_LITERAL(107, 12), // "getByContent"
QT_MOC_LITERAL(120, 19), // "on_listView_clicked"
QT_MOC_LITERAL(140, 11), // "QModelIndex"
QT_MOC_LITERAL(152, 5), // "index"
QT_MOC_LITERAL(158, 25), // "on_listView_doubleClicked"
QT_MOC_LITERAL(184, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(208, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(234, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(259, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(282, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(307, 25), // "on_actionSave_2_triggered"
QT_MOC_LITERAL(333, 26), // "on_actionContent_triggered"
QT_MOC_LITERAL(360, 10), // "allEnabled"
QT_MOC_LITERAL(371, 8) // "activate"

    },
    "MainWindow\0contentAded\0\0id\0cont\0"
    "ContentDialog*\0dl\0on_pushButton_clicked\0"
    "menuAction\0b\0nameChanged\0getByName\0"
    "getByContent\0on_listView_clicked\0"
    "QModelIndex\0index\0on_listView_doubleClicked\0"
    "on_actionOpen_triggered\0"
    "on_actionDelete_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionNew_triggered\0on_actionAbout_triggered\0"
    "on_actionSave_2_triggered\0"
    "on_actionContent_triggered\0allEnabled\0"
    "activate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  110,    2, 0x0a,    0 /* Public */,
       7,    0,  117,    2, 0x08,    4 /* Private */,
       8,    1,  118,    2, 0x08,    5 /* Private */,
      10,    0,  121,    2, 0x08,    7 /* Private */,
      11,    0,  122,    2, 0x08,    8 /* Private */,
      12,    0,  123,    2, 0x08,    9 /* Private */,
      13,    1,  124,    2, 0x08,   10 /* Private */,
      16,    1,  127,    2, 0x08,   12 /* Private */,
      17,    0,  130,    2, 0x08,   14 /* Private */,
      18,    0,  131,    2, 0x08,   15 /* Private */,
      19,    0,  132,    2, 0x08,   16 /* Private */,
      20,    0,  133,    2, 0x08,   17 /* Private */,
      21,    0,  134,    2, 0x08,   18 /* Private */,
      22,    0,  135,    2, 0x08,   19 /* Private */,
      23,    0,  136,    2, 0x08,   20 /* Private */,
      24,    1,  137,    2, 0x08,   21 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->contentAded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ContentDialog*(*)>(_a[3]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->menuAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->nameChanged(); break;
        case 4: _t->getByName(); break;
        case 5: _t->getByContent(); break;
        case 6: _t->on_listView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_listView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_actionOpen_triggered(); break;
        case 9: _t->on_actionDelete_triggered(); break;
        case 10: _t->on_actionClose_triggered(); break;
        case 11: _t->on_actionNew_triggered(); break;
        case 12: _t->on_actionAbout_triggered(); break;
        case 13: _t->on_actionSave_2_triggered(); break;
        case 14: _t->on_actionContent_triggered(); break;
        case 15: _t->allEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ContentDialog* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<ContentDialog *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
