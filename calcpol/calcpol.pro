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
    iexpression.cpp \
    logger.cpp \
    calculator.cpp \
    expressionfactory.cpp \
    operateurs/operateursinus.cpp \
    operateurs/operateurplus.cpp \
    operateurs/operateurminus.cpp \
    operateurs/ioperateur.cpp \
    constants/rationnel.cpp \
    constants/iconstant.cpp \
    constants/complex.cpp

HEADERS  += mainwindow.h \
    pilewidget.h \
    clavierwidget.h \
    optiondialog.h \
    iexpression.h \
    logger.h \
    calculator.h \
    expressionfactory.h \
    include_all_expressions.h \
    operateurs/operateursinus.h \
    operateurs/operateurplus.h \
    operateurs/operateurminus.h \
    operateurs/operateurs.h \
    operateurs/ioperateur.h \
    constants/iconstant.h \
    constants/constants.h

FORMS    += mainwindow.ui \
    pilewidget.ui \
    clavierwidget.ui \
    optiondialog.ui
