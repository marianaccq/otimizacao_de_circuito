TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        parser.cpp \
        util.cpp

HEADERS += \
    numericalrecipes.h \
    parser.h \
    util.h
