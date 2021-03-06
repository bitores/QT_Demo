#-------------------------------------------------
#
# Project created by QtCreator 2014-09-04T10:06:41
#
#-------------------------------------------------

QT       += core gui
QT += qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Eazy3dXStudio
TEMPLATE = app


DEFINES += LIB_LIBRARY
CONFIG += debug_and_release
CONFIG(debug, debug|release) {
    LIBS += -L../../bin_win_debug/lib
    DESTDIR = ../../bin_win_debug/bin
    TARGET = E3dxStudio_debug
 } else {
    LIBS += -L../../bin_win_release/lib
    DESTDIR = ../../bin_win_release/bin
    LIBS += -lmylog
    LIBS += -lmycfg
    TARGET = E3dxStudio
 }




SOURCES += main.cpp\
        mainwindow.cpp \
    scenewidget.cpp \
    propertiespane.cpp \
    DragListWidget.cpp \
    particlewidget.cpp

HEADERS  += mainwindow.h \
    scenewidget.h \
    propertiespane.h \
    DragListWidget.h \
    particlewidget.h

FORMS    += mainwindow.ui \
    scenewidget.ui \
    propertiespane.ui \
    particlewidget.ui

OTHER_FILES += \
    qml/logic.js \
    qml/DragSprite.qml \
    qml/main.qml

RESOURCES += \
    src.qrc
