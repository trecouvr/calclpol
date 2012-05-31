#include <QtGui/QApplication>
#include "mainwindow.h"

#include "complex.h"

int main(int argc, char *argv[])
{
    Complex c;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
