#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T20:29:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lightpadpp
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainWindow/mainwindow.cpp \
    src/helpDialog/helpdialog.cpp \
    src/notepad/notepad.cpp

HEADERS  += src/mainWindow/mainwindow.h \
    src/helpDialog/helpdialog.h \
    src/config/directives.h

FORMS    += src/mainWindow/mainwindow.ui \
    src/helpDialog/helpdialog.ui
