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
    constants/complex.cpp \
    cast.cpp \
    operateurs/operateurcosinus.cpp \
    operateurs/operateurtangente.cpp \
    operateurs/operateurfactorielle.cpp \
    operateurs/operateursinh.cpp \
    operateurs/operateurcosh.cpp \
    operateurs/operateurtanh.cpp \
    operateurs/operateurln.cpp \
    operateurs/operateurlog.cpp \
    operateurs/operateursqrt.cpp \
    operateurs/operateurinv.cpp \
    operateurs/operateursqr.cpp \
    operateurs/operateurcube.cpp \
    operateurs/operateurdiv.cpp \
    operateurs/operateurmult.cpp

HEADERS  += mainwindow.h \
    pilewidget.h \
    clavierwidget.h \
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
    cast.h \
    operateurs/operateurcosinus.h \
    operateurs/operateurtangente.h \
    operateurs/operateurfactorielle.h \
    operateurs/operateursinh.h \
    operateurs/operateurcosh.h \
    operateurs/operateurtanh.h \
    operateurs/operateurln.h \
    operateurs/operateurlog.h \
    operateurs/operateursqrt.h \
    operateurs/operateurinv.h \
    operateurs/operateursqr.h \
    operateurs/operateurcube.h \
    operateurs/operateurdiv.h \
    operateurs/operateurmult.h \
    constants/complex.h \
    constants/rationnel.h \
    constants/basictype.h \
    constants/constants.h

FORMS    += mainwindow.ui \
    pilewidget.ui
