TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CCFLAG += -std=c++11

SOURCES += main.cpp \
    basic_client.cpp \
    sync_tcp_client.cpp \
    basic_server.cpp \
    sync_tcp_server.cpp


unix|win32: LIBS += -lboost_system -lpthread

HEADERS += \
    basic_client.h \
    sync_tcp_client.h \
    basic_server.h \
    sync_tcp_server.h

unix|win32: LIBS += -lboost_thread
