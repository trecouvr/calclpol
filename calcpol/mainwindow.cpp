#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   _optionDialog = new OptionDialog(this);
   //connect(ui->pb_eval, SIGNAL(released()), ui->pile_widget, SLOT(on_input_returnPressed()));
   QList<QPushButton*> pList = this->findChildren<QPushButton*>(QRegExp(".*"));
   for (QList<QPushButton*>::iterator it=pList.begin(); it!=pList.end(); ++it) {
       QPushButton * b = *it;
       connect(b, SIGNAL(released()), this, SLOT(on_pb_pressed()));
   }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPreferences_triggered()
{
    _optionDialog->setModal(true);
    _optionDialog->show();
}

void MainWindow::on_pb_pressed() {
    QPushButton * emetteur = (QPushButton*) sender();
    QString value = emetteur->text();
    if (value == "eval") {
        ui->pile_widget->on_input_returnPressed();
    }
    else {
        ui->pile_widget->addInput(value);
    }
}

