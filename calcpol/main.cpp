#include <QtGui/QApplication>
#include "mainwindow.h"

#include <iostream>
#include "logger.h"
#include "expressionfactory.h"
#include "calculator.h"


int main(int argc, char *argv[]) {
    QString s;
    Entier * x = new Entier(42);
    IExpression * exp = x;
    Calculator::castExp(IConstant::REEL, &exp);
    s = exp->toString();
    Calculator::castExp(IConstant::RATIONNELLE, &exp);
    s = exp->toString();
    Calculator::castExp(IConstant::COMPLEX, &exp);
    s = exp->toString();
    Calculator::castExp(IConstant::COMPLEX, &exp, false, IConstant::REEL);
    s = exp->toString();
    Entier * y = new Entier(45);
    Complex * c = new Complex(x,y);
    Entier * z = new Entier(*c);
    Rationnel * r = new Rationnel(*z);
    /*ExpressionFactory f = ExpressionFactory();
    IExpression * e = f.parse("42");
    Entier * x = new Entier(42);
    IConstant * p = x;
    Reel * y = new Reel(*p);*/
    Logger::d("TEST","test de debug");
    Logger::e("TEST ERROR","BOUH");
    Logger::i("TEST INFORMATION", "TETET");
    Logger::d("TEST","test de debug");
    Logger::v("TEST","test de verbose");
    Logger::w("TEST","test de warning");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
