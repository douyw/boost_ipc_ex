
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

DESTDIR = $$PWD/bin

SRC_PATH=$$PWD/src

INCLUDEPATH += $$PWD/include

macx: {
#    INCLUDEPATH += /Users/mac/devel/boost
    INCLUDEPATH += /usr/local/include
}
