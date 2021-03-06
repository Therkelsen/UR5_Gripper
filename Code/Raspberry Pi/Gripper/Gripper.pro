TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        xmlrpc.cpp \
    motorcontrol.cpp \
    tcp_server.cpp

LIBS += -lwiringPi
LIBS += -lpthread
LIBS += -Lusr/local/lib/ -lxmlrpc++
LIBS += -Lusr/local/lib/ -lxmlrpc_util++
LIBS += -Lusr/local/lib/ -lxmlrpc_server++
LIBS += -Lusr/local/lib/ -lxmlrpc_server_abyss++
LIBS += -lopen62541

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

HEADERS += \
        xmlrpc.h \
    motorcontrol.h \
    tcp_server.h

QT += network
