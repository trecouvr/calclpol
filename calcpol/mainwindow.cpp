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
   connect(ui->cb_complex, SIGNAL(toggled(bool)), ui->pile_widget, SLOT(setComplexMode(bool)));
   connect(ui->rb_entier, SIGNAL(toggled(bool)), this, SLOT(setEntierMode()));
   connect(ui->rb_reel, SIGNAL(toggled(bool)), this, SLOT(setReelMode()));
   connect(ui->rb_rationnel, SIGNAL(toggled(bool)), this, SLOT(setRationnelMode()));
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
    else if (value == "space") {
        ui->pile_widget->addInput(" ");
    }
    else {
        ui->pile_widget->addInput(value);
    }
}

void MainWindow::setEntierMode() {
    ui->pile_widget->setConstantMode(IConstant::ENTIER);
}

void MainWindow::setReelMode() {
    ui->pile_widget->setConstantMode(IConstant::REEL);
}

void MainWindow::setRationnelMode() {
    ui->pile_widget->setConstantMode(IConstant::RATIONNELLE);
}

