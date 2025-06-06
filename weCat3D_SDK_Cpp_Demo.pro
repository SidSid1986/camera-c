#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T09:10:19
#
#-------------------------------------------------
include(QXlsx/QXlsx.pri)
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = weCat3D_SDK_Windows_Cpp
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
        src/cimage.cpp \
        src/settingswindow.cpp \
        src/tinyxml2.cpp \
        src/pevents.cpp \
        src/win32.cpp

HEADERS  += src/mainwindow.h \
        src/cimage.h \
        src/settingswindow.h \
        src/tinyxml2.h \
        src/pevents.h

FORMS += \
        src/mainwindow.ui \
        src/settingswindow.ui

RC_FILE = src/myapp.rc

LIBS += -L$$PWD/EthernetScanner/ -lEthernetScanner
INCLUDEPATH += $$PWD/EthernetScanner
DEPENDPATH += $$PWD/EthernetScanner

VERSION_FROM_FILE = "$$cat(version.txt)"
VERSION_FROM_FILE = $$split(VERSION_FROM_FILE, .)

C_MAJOR=$$member(VERSION_FROM_FILE,0,0)
C_MINOR=$$member(VERSION_FROM_FILE,1,1)
C_BUILD=$$member(VERSION_FROM_FILE,2,2)


DEFINES += "C_MAJOR=$$C_MAJOR"
DEFINES += "C_MINOR=$$C_MINOR"
DEFINES += "C_BUILD=$$C_BUILD"

VERSION = $${C_MAJOR}.$${C_MINOR}.$${C_BUILD}


