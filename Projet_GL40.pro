#-------------------------------------------------
#
# Project created by QtCreator 2017-05-15T17:02:55
#
#-------------------------------------------------

QT       += core gui


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
    fittsresult.cpp \
    explorerresultswindow.cpp \
    explorerresult.cpp \
    textresult.cpp \
    textresultwindow.cpp

HEADERS  += mainwindow.h \
    clickablelabel.h \
    explorerwindow.h \
    cmdwindow.h \
    textinputwindow.h \
    fittswindow.h \
    resultswindow.h \
    fittsresult.h \
    explorerresultswindow.h \
    explorerresult.h \
    textresult.h \
    textresultwindow.h

FORMS    += mainwindow.ui \
    explorerwindow.ui \
    cmdwindow.ui \
    textinputwindow.ui \
    fittswindow.ui \
    resultswindow.ui \
    explorerresultswindow.ui \
    textresultwindow.ui
