#-------------------------------------------------
#
# Project created by QtCreator 2017-05-15T17:02:55
#
#-------------------------------------------------

QT       += core gui
QT       += charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_GL40
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clickablelabel.cpp \
    explorerwindow.cpp \
    cmdwindow.cpp \
    textinputwindow.cpp \
    fittswindow.cpp \
    resultswindow.cpp \
    fittsresult.cpp

HEADERS  += mainwindow.h \
    clickablelabel.h \
    explorerwindow.h \
    cmdwindow.h \
    textinputwindow.h \
    fittswindow.h \
    resultswindow.h \
    fittsresult.h

FORMS    += mainwindow.ui \
    explorerwindow.ui \
    cmdwindow.ui \
    textinputwindow.ui \
    fittswindow.ui \
    resultswindow.ui
