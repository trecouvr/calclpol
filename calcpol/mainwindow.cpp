#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Logger::v("MainWindow","constructor called");
    ui->setupUi(this);

    this->loadState();

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

MainWindow::~MainWindow() {
    Logger::v("MainWindow","destructor called");
    this->saveState();
    delete ui;
}

void MainWindow::saveState() {
    Logger::v("MainWindow","saveState");
    QString state = ui->pile_widget->stateToString();
    std::ofstream file;
    file.open("save.txt", ios::trunc);
    if (file.is_open()) {
        file << state.toStdString();
        file.close();
    }
    else {
        Logger::e("MainWindow", "impossible d'ouvrir le fichier");
    }
}

void MainWindow::loadState() {
    Logger::v("MainWindow","loadState");
    std::ifstream file;
    std::string line;
    QString state = "";
    file.open ("save.txt");
    if (file.is_open()) {
        while ( file.good() ) {
            getline (file,line);
            state += (line+"\n").c_str();
        }
        file.close();
        ui->pile_widget->stateFromString(state);
        ui->pile_widget->refreshScreen();
    }
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
    ui->pile_widget->setConstantMode(IConstant::RATIONNEL);
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close();
}

void MainWindow::on_actionRetablir_triggered()
{
    Logger::v("MainWindow","ctrl+y triggered");
    ui->pile_widget->retablir();
}

void MainWindow::on_actionAnnuler_triggered()
{
    Logger::v("MainWindow","ctrl+z triggered");
    ui->pile_widget->annuler();
}
