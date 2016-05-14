#-------------------------------------------------
#
# Project created by QtCreator 2014-06-27T21:21:04
#
#-------------------------------------------------

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = configure_lib
TEMPLATE = lib

DEFINES += CONFIGURE_LIB_LIBRARY
CONFIG(debug, debug|release) {
    LIBS += -L../../bin_win_debug/lib
    DESTDIR = ../../bin_win_debug/lib
    TARGET = mycfg_debug
 } else {
    LIBS += -L../../bin_win_release/lib
    DESTDIR = ../../bin_win_release/lib

    LIBS += -lmylog
    TARGET = mycfg
 }
SOURCES += \
    ccfg.cpp \
    cifapp.cpp \
    cinifilebase.cpp

HEADERS += \
    ../../01public/logout/log.h \
    ccfg.h \
    cifapp.h \
    cinifilebase.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
