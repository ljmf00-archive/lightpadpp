#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T22:05:57
#
#-------------------------------------------------

QT       -= gui

TARGET = lightpadlib
TEMPLATE = lib

DEFINES += LIGHTPADLIB_LIBRARY

SOURCES += src/core/lightpadlib.cpp \

HEADERS +=\
        lightpadlib_global.h \
    src/core/lightpadlib.h \
    src/core/lightpadlib_global.h \

unix {
    target.path = /usr/lib
    INSTALLS += target
}
