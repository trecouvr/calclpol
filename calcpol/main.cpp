#include <QtGui/QApplication>
#include "mainwindow.h"

#include <iostream>
#include "logger.h"
#include "expressionfactory.h"


int main(int argc, char *argv[])
{

    ExpressionFactory f = ExpressionFactory();
    IExpression * e = f.parse("42");

    Entier * x = new Entier(42);
    IConstant * p = x;
    Reel * y = new Reel(*p);
    Logger::d("TEST","test de debug");
    Logger::e("TEST ERROR","BOUH");
    Logger::i("TEST INFORMATION", "TETET");
    Logger::d("TEST","test de debug");
    Logger::v("TEST","test de verbose");
    Logger::w("TEST","test de warning");

    /*Complex c1(""), c2("");
    IDonnee *p1=&c1, *p2=&c2;
    p1->plus(p2);
    Logger::w("TEST","test de warning");*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
