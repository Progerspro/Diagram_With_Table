#-------------------------------------------------
#
# Project created by QtCreator 2014-04-06T19:13:59
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Diagram_program
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    form.cpp \
    data.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    form.h \
    data.h

FORMS    += mainwindow.ui \
    form.ui
