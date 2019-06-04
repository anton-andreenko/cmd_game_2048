# cmd_game_2048.pro

TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    aux_header.hpp \
    functions.hpp

SOURCES += \
    main.cpp \
    functions.cpp
