#-------------------------------------------------
#
# Project created by QtCreator 2017-10-05T20:40:26
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Shrek
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        mainwindow.cpp \
    character.cpp \
    command.cpp \
    commandwords.cpp \
    item.cpp \
    parser.cpp \
    room.cpp \
    zorkul.cpp

HEADERS += \
        mainwindow.h \
    character.h \
    command.h \
    commandwords.h \
    item.h \
    parser.h \
    room.h \
    zorkul.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res.qrc
