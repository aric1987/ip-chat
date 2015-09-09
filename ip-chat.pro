#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T23:52:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ip-chat
TEMPLATE = app


SOURCES += main.cpp\
        main_window.cpp \
    ipmsg_protocol.cpp \
    user_list_widget.cpp \
    chat_widget.cpp \
    user_info.cpp

HEADERS  += main_window.h \
    ipmsg_protocol.h \
    user_list_widget.h \
    chat_widget.h \
    user_info.h

RESOURCES += \
    ip-chat.qrc
