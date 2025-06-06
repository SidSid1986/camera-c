/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "UpdatePixmap"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "ScannerConnect"
QT_MOC_LITERAL(4, 40, 17), // "ScannerDisconnect"
QT_MOC_LITERAL(5, 58, 7), // "onTimer"
QT_MOC_LITERAL(6, 66, 18), // "showSettingsWindow"
QT_MOC_LITERAL(7, 85, 19), // "resetPictureCounter"
QT_MOC_LITERAL(8, 105, 12), // "resetDllFifo"
QT_MOC_LITERAL(9, 118, 13), // "RefreshPixmap"
QT_MOC_LITERAL(10, 132, 12), // "SaveProfiles"
QT_MOC_LITERAL(11, 145, 16), // "GetPropertyValue"
QT_MOC_LITERAL(12, 162, 10), // "closeEvent"
QT_MOC_LITERAL(13, 173, 12), // "QCloseEvent*"
QT_MOC_LITERAL(14, 186, 5), // "event"
QT_MOC_LITERAL(15, 192, 14), // "StopResetStart"
QT_MOC_LITERAL(16, 207, 19), // "SaveProfilesAsExcel"
QT_MOC_LITERAL(17, 227, 12), // "onScreenshot"
QT_MOC_LITERAL(18, 240, 16), // "SetMeasuringRate"
QT_MOC_LITERAL(19, 257, 12), // "rebootCamera"
QT_MOC_LITERAL(20, 270, 7), // "setMode"
QT_MOC_LITERAL(21, 278, 24) // "syncCameraModeFromDevice"

    },
    "MainWindow\0UpdatePixmap\0\0ScannerConnect\0"
    "ScannerDisconnect\0onTimer\0showSettingsWindow\0"
    "resetPictureCounter\0resetDllFifo\0"
    "RefreshPixmap\0SaveProfiles\0GetPropertyValue\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "StopResetStart\0SaveProfilesAsExcel\0"
    "onScreenshot\0SetMeasuringRate\0"
    "rebootCamera\0setMode\0syncCameraModeFromDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  107,    2, 0x08 /* Private */,
       4,    0,  108,    2, 0x08 /* Private */,
       5,    0,  109,    2, 0x08 /* Private */,
       6,    0,  110,    2, 0x08 /* Private */,
       7,    0,  111,    2, 0x08 /* Private */,
       8,    0,  112,    2, 0x08 /* Private */,
       9,    1,  113,    2, 0x08 /* Private */,
      10,    0,  116,    2, 0x08 /* Private */,
      11,    0,  117,    2, 0x08 /* Private */,
      12,    1,  118,    2, 0x08 /* Private */,
      15,    0,  121,    2, 0x08 /* Private */,
      16,    0,  122,    2, 0x08 /* Private */,
      17,    0,  123,    2, 0x08 /* Private */,
      18,    0,  124,    2, 0x08 /* Private */,
      19,    0,  125,    2, 0x08 /* Private */,
      20,    0,  126,    2, 0x08 /* Private */,
      21,    0,  127,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdatePixmap((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->ScannerConnect(); break;
        case 2: _t->ScannerDisconnect(); break;
        case 3: _t->onTimer(); break;
        case 4: _t->showSettingsWindow(); break;
        case 5: _t->resetPictureCounter(); break;
        case 6: _t->resetDllFifo(); break;
        case 7: _t->RefreshPixmap((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 8: _t->SaveProfiles(); break;
        case 9: _t->GetPropertyValue(); break;
        case 10: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 11: _t->StopResetStart(); break;
        case 12: _t->SaveProfilesAsExcel(); break;
        case 13: _t->onScreenshot(); break;
        case 14: _t->SetMeasuringRate(); break;
        case 15: _t->rebootCamera(); break;
        case 16: _t->setMode(); break;
        case 17: _t->syncCameraModeFromDevice(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UpdatePixmap)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
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
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::UpdatePixmap(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
