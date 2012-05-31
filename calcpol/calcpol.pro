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
    logger.cpp \
    operateurs/operateurplus.cpp \
    operateurs/operateurminus.cpp \
    calculator.cpp \
    expressionfactory.cpp \
    basictype.cpp

HEADERS  += mainwindow.h \
    pilewidget.h \
    clavierwidget.h \
    optiondialog.h \
    idonnee.h \
    complex.h \
    iexpression.h \
    ioperateur.h \
    include_all_donnees.h \
    logger.h \
    operateurs/operateurplus.h \
    operateurs/operateurminus.h \
    calculator.h \
    expressionfactory.h \
    include_all_operateurs.h \
    include_all_expressions.h \
    basictype.h

FORMS    += mainwindow.ui \
    pilewidget.ui \
    clavierwidget.ui \
    optiondialog.ui
