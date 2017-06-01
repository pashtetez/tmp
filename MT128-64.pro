#-------------------------------------------------
#
# Project created by QtCreator 2017-05-28T21:27:58
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MT128-64
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lcd.cpp

HEADERS  += mainwindow.h \
    lcd.h

FORMS    += mainwindow.ui
