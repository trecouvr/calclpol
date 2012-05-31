#include <QtGui/QApplication>
#include "mainwindow.h"

#include <iostream>
#include "complex.h"
#include "logger.h"


int main(int argc, char *argv[])
{

    Logger log = Logger(0, std::cout);
    log.d("TEST","test de debug");

    Complex c1, c2;
    IDonnee *p1=&c1, *p2=&c2;
    p1->plus(p2);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
