#-------------------------------------------------
#
# Project created by QtCreator 2012-05-11T16:14:08
#
#-------------------------------------------------

QT       += core gui

TARGET = calcpol
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    pilewidget.cpp \
    clavierwidget.cpp \
    optiondialog.cpp \
    idonnee.cpp \
    complex.cpp \
    iexpression.cpp \
    ioperateur.cpp \
    entier.cpp \
    logger.cpp \
    operateurs/operateurplus.cpp \
    operateurs/operateurminus.cpp

HEADERS  += mainwindow.h \
    pilewidget.h \
    clavierwidget.h \
    optiondialog.h \
    idonnee.h \
    complex.h \
    iexpression.h \
    ioperateur.h \
    include_all_donnees.h \
    entier.h \
    logger.h \
    operateurs/operateurplus.h \
    operateurs/operateurminus.h

FORMS    += mainwindow.ui \
    pilewidget.ui \
    clavierwidget.ui \
    optiondialog.ui
