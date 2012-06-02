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
    complex.cpp \
    iexpression.cpp \
    ioperateur.cpp \
    logger.cpp \
    operateurs/operateurplus.cpp \
    operateurs/operateurminus.cpp \
    calculator.cpp \
    expressionfactory.cpp \
    basictype.cpp \
    operateurs/operateursinus.cpp \
    iconstant.cpp \
    rationnel.cpp

HEADERS  += mainwindow.h \
    pilewidget.h \
    clavierwidget.h \
    optiondialog.h \
    iexpression.h \
    ioperateur.h \
    logger.h \
    operateurs/operateurplus.h \
    operateurs/operateurminus.h \
    calculator.h \
    expressionfactory.h \
    include_all_operateurs.h \
    include_all_expressions.h \
    operateurs/operateursinus.h \
    iconstant.h \
    include_all_constant.h

FORMS    += mainwindow.ui \
    pilewidget.ui \
    clavierwidget.ui \
    optiondialog.ui
