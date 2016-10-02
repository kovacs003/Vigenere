TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    user_message.cpp \
    user_keyword.cpp \
    encoder.cpp \
    file_handler.cpp

QMAKE_CXXFLAGS_DEBUG = -g -Og
QMAKE_CXXFLAGS_RELEASE = -O3
QMAKE_CXXFLAGS += -std=c++11 -std=c++14

HEADERS += \
    user_message.h \
    user_keyword.h \
    encoder.h \
    file_handler.h \
    base_message.h

