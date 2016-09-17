#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T23:11:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
    head.cpp \
    food.cpp \
    game.cpp \
    sbody.cpp \
    menudialog.cpp

HEADERS  += \
    head.h \
    food.h \
    game.h \
    sbody.h \
    menudialog.h

FORMS    += \
    game.ui \
    menudialog.ui
