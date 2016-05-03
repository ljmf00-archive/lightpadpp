#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T20:29:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lightpadpp
TEMPLATE = app
CONFIG += c++11


SOURCES += src/main.cpp\
        src/mainWindow/mainwindow.cpp \
    src/helpDialog/helpdialog.cpp \
    src/notepad/notepad.cpp \
    src/notepad/methods/fstream.cpp \
    src/notepad/methods/create.cpp \
    src/notepad/methods/destroy.cpp \
    src/notepad/slots/edit.cpp \
    src/notepad/slots/file.cpp \
    src/notepad/syntax/syntax.cpp \
    src/notepad/syntax/highlightblock.cpp \
    src/notepad/syntax/lang/c_cpp.cpp \
    src/notepad/styles/ceditor.cpp \
    src/config/check.cpp \
    src/config/files.cpp

HEADERS  += src/mainWindow/mainwindow.h \
    src/helpDialog/helpdialog.h \
    src/config/directives.h \ 
    src/notepad/syntax/syntax.h \
    src/notepad/styles/ceditor.h \
    src/config/check.h

FORMS    += src/mainWindow/mainwindow.ui \
    src/helpDialog/helpdialog.ui

RESOURCES += \
    assets/assets.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/bin/debug/release/ -llightpadlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/bin/debug/debug/ -llightpadlib
else:unix: LIBS += -L$$PWD/lib/bin/debug/ -llightpadlib

INCLUDEPATH += $$PWD/lib/bin/debug
DEPENDPATH += $$PWD/lib/bin/debug
