#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T07:35:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YJNetwork
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    packetutil.cpp

HEADERS  += mainwindow.h \
    packetutil.h

FORMS    += mainwindow.ui \
    packetutil.ui

CONFIG += c++11
LIBS += -lpcap



