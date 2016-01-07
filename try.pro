#-------------------------------------------------
#
# Project created by QtCreator 2015-02-14T13:05:41
#
#-------------------------------------------------

QT       += core gui \
            multimedia \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = try
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    start.cpp \
    data.cpp \
    superai.cpp

HEADERS  += mainwindow.h \
    start.h \
    data.h \
    superai.h

FORMS    += mainwindow.ui \
    start.ui

RESOURCES += \
    rs.qrc
