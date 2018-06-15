#-------------------------------------------------
#
# Project created by QtCreator 2018-06-13T16:10:45
#
#-------------------------------------------------
LIBS += -lpthread libwsock32 libws2_32
CONFIG += c++11
TARGET = tcpServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    server.cpp

HEADERS += \
    server.h
