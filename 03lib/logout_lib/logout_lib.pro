#-------------------------------------------------
#
# Project created by QtCreator 2014-06-27T08:00:36
#
#-------------------------------------------------

QT      += core
QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = logout_lib
TEMPLATE = lib

DEFINES += LOGOUT_LIB_LIBRARY
CONFIG += debug_and_release
CONFIG(debug, debug|release) {
    DESTDIR = ../../bin_win_debug/lib
    TARGET = mylog_debug
 } else {
    DESTDIR = ../../bin_win_release/lib
    TARGET = mylog
 }
SOURCES += log.cpp

HEADERS += log.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
