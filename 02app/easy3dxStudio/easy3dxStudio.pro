#-------------------------------------------------
#
# Project created by QtCreator 2014-06-26T17:24:54
#
#-------------------------------------------------

QT       += core gui declarative
QT       += xml network script

TARGET = qml_guess05
TEMPLATE = app

DEFINES += LIB_LIBRARY
CONFIG += debug_and_release
CONFIG(debug, debug|release) {
    LIBS += -L../../bin_win_debug/lib
    DESTDIR = ../../bin_win_debug/bin
#    LIBS += -llibgcc_s_dw2-1
    TARGET = E3dxStudio_debug
 } else {
    LIBS += -L../../bin_win_release/lib
    DESTDIR = ../../bin_win_release/bin
    LIBS += -lmylog
    LIBS += -lmycfg
    TARGET = E3dxStudio
 }


SOURCES +=\
    ../../01public/qtsingleapplication/qtlocalpeer.cpp \
    ../../01public/qtsingleapplication/qtlockedfile.cpp \
    ../../01public/qtsingleapplication/qtlockedfile_unix.cpp \
    ../../01public/qtsingleapplication/qtlockedfile_win.cpp \
    ../../01public/qtsingleapplication/qtsingleapplication.cpp \
    ../../01public/qtsingleapplication/qtsinglecoreapplication.cpp \
    main.cpp \
    mainwindow.cpp \
    json/json_internalarray.inl \
    json/json_internalmap.inl \
    json/json_reader.cpp \
    json/json_value.cpp \
    json/json_valueiterator.inl \
    json/json_writer.cpp \
    fontconvert.cpp

HEADERS  += \
    ../../01public/qtsingleapplication/qtlocalpeer.h \
    ../../01public/qtsingleapplication/qtlockedfile.h \
    ../../01public/qtsingleapplication/qtsingleapplication.h \
    ../../01public/qtsingleapplication/qtsinglecoreapplication.h \
    ../../01public/logout/log.h \
    ../../01public/config/ccfig.h \
    mainwindow.h \
    json/autolink.h \
    json/config.h \
    json/features.h \
    json/forwards.h \
    json/json.h \
    json/json_batchallocator.h \
    json/reader.h \
    json/value.h \
    json/writer.h \
    fontconvert.h

OTHER_FILES += \
    qml/main.qml \
    qml/DragImage.qml \
    qml/logic.js \
    json/sconscript

RESOURCES += \
    qrc.qrc

FORMS += \
    mainwindow.ui
