/****************************************************************************
** Meta object code from reading C++ file 'fenprincipale.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../zNavigo/fenprincipale.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenprincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FenPrincipale_t {
    QByteArrayData data[22];
    char stringdata[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FenPrincipale_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FenPrincipale_t qt_meta_stringdata_FenPrincipale = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 10),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 8),
QT_MOC_LITERAL(4, 35, 4),
QT_MOC_LITERAL(5, 40, 10),
QT_MOC_LITERAL(6, 51, 7),
QT_MOC_LITERAL(7, 59, 7),
QT_MOC_LITERAL(8, 67, 12),
QT_MOC_LITERAL(9, 80, 12),
QT_MOC_LITERAL(10, 93, 16),
QT_MOC_LITERAL(11, 110, 5),
QT_MOC_LITERAL(12, 116, 11),
QT_MOC_LITERAL(13, 128, 15),
QT_MOC_LITERAL(14, 144, 12),
QT_MOC_LITERAL(15, 157, 13),
QT_MOC_LITERAL(16, 171, 3),
QT_MOC_LITERAL(17, 175, 15),
QT_MOC_LITERAL(18, 191, 17),
QT_MOC_LITERAL(19, 209, 11),
QT_MOC_LITERAL(20, 221, 17),
QT_MOC_LITERAL(21, 239, 2)
    },
    "FenPrincipale\0precedente\0\0suivante\0"
    "stop\0actualiser\0acceuil\0aPropos\0"
    "nouvelOnglet\0fermerOnglet\0changementOnglet\0"
    "index\0chargerPage\0changementTitre\0"
    "titreComplet\0changementUrl\0url\0"
    "chargementDebut\0chargementEnCours\0"
    "pourcentage\0chargementTermine\0ok\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenPrincipale[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08,
       3,    0,   90,    2, 0x08,
       4,    0,   91,    2, 0x08,
       5,    0,   92,    2, 0x08,
       6,    0,   93,    2, 0x08,
       7,    0,   94,    2, 0x08,
       8,    0,   95,    2, 0x08,
       9,    0,   96,    2, 0x08,
      10,    1,   97,    2, 0x08,
      12,    0,  100,    2, 0x08,
      13,    1,  101,    2, 0x08,
      15,    1,  104,    2, 0x08,
      17,    0,  107,    2, 0x08,
      18,    1,  108,    2, 0x08,
      20,    1,  111,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QUrl,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool,   21,

       0        // eod
};

void FenPrincipale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FenPrincipale *_t = static_cast<FenPrincipale *>(_o);
        switch (_id) {
        case 0: _t->precedente(); break;
        case 1: _t->suivante(); break;
        case 2: _t->stop(); break;
        case 3: _t->actualiser(); break;
        case 4: _t->acceuil(); break;
        case 5: _t->aPropos(); break;
        case 6: _t->nouvelOnglet(); break;
        case 7: _t->fermerOnglet(); break;
        case 8: _t->changementOnglet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->chargerPage(); break;
        case 10: _t->changementTitre((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->changementUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 12: _t->chargementDebut(); break;
        case 13: _t->chargementEnCours((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->chargementTermine((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FenPrincipale::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FenPrincipale.data,
      qt_meta_data_FenPrincipale,  qt_static_metacall, 0, 0}
};


const QMetaObject *FenPrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenPrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenPrincipale.stringdata))
        return static_cast<void*>(const_cast< FenPrincipale*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FenPrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
