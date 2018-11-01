TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


unix|win32: LIBS += -lboost_system -lpthread
