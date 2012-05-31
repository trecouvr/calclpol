#include <QtGui/QApplication>
#include "mainwindow.h"

#include <iostream>
#include "complex.h"
#include "logger.h"


int main(int argc, char *argv[])
{
    Logger log = Logger(0, std::cout);
    log.d("TEST","test de debug");
    Complex c;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
