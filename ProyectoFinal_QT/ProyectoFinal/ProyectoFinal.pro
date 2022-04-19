QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alien1.cpp \
    alien2.cpp \
    bloque.cpp \
    bullet.cpp \
    desplegarinfo.cpp \
    granade.cpp \
    main.cpp \
    mainwindow.cpp \
    municion.cpp \
    personaje.cpp \
    vida.cpp

HEADERS += \
    alien1.h \
    alien2.h \
    bloque.h \
    bullet.h \
    desplegarinfo.h \
    mainwindow.h \
    municion.h \
    personaje.h \
    granade.h \
    mainwindow.h \
    vida.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    alien.qrc \
    mapa.qrc \
    personaje.qrc

DISTFILES += \
    personaje/Attack_000.png \
    personaje/Attack_000_Left.png \
    personaje/Attack_001.png \
    personaje/Attack_001_Left.png \
    personaje/Attack_002.png \
    personaje/Attack_002_Left.png \
    personaje/Bullet.png \
    personaje/Die_000.png \
    personaje/Die_000_Left.png \
    personaje/Die_001.png \
    personaje/Die_001_Left.png \
    personaje/Die_002.png \
    personaje/Die_002_Left.png \
    personaje/Die_003.png \
    personaje/Die_003_Left.png \
    personaje/Die_004.png \
    personaje/Die_004_Left.png \
    personaje/Die_005.png \
    personaje/Die_005_Left.png \
    personaje/Die_006.png \
    personaje/Die_006_Left.png \
    personaje/Hurt_000.png \
    personaje/Hurt_000_Left.png \
    personaje/Idle_000_Left.png \
    personaje/Jump_000.png \
    personaje/Jump_000_Left.png \
    personaje/Run_000.png \
    personaje/Run_000_Left.png \
    personaje/Run_001.png \
    personaje/Run_001_Left.png \
    personaje/Run_002.png \
    personaje/Run_002_Left.png \
    personaje/Run_003.png \
    personaje/Run_003_Left.png \
    personaje/Run_004.png \
    personaje/Run_004_Left.png \
    personaje/Run_005.png \
    personaje/Run_005_Left.png \
    personaje/Run_006.png \
    personaje/Run_006_Left.png \
    personaje/Run_007.png \
    personaje/Run_007_Left.png \
    personaje/Run_008.png \
    personaje/Run_008_Left.png \
    personaje/Run_009.png \
    personaje/Run_009_Left.png
