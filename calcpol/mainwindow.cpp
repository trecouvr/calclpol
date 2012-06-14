#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Logger::v("MainWindow","constructor called");
    ui->setupUi(this);

    ui->tabWidget->clear();
    ui->tabWidget->addTab(new PileWidget(), "First");
    connect(this->currentPile(), SIGNAL(error(QString)), this, SLOT(showError(QString)));
    ui->tabWidget->setMovable(true);

    this->loadState();

   _optionDialog = new OptionDialog(this);
   //connect(ui->pb_eval, SIGNAL(released()), this->currentPile(), SLOT(on_input_returnPressed()));
   QList<QPushButton*> pList = this->findChildren<QPushButton*>(QRegExp(".*"));
   for (QList<QPushButton*>::iterator it=pList.begin(); it!=pList.end(); ++it) {
       QPushButton * b = *it;
       connect(b, SIGNAL(released()), this, SLOT(on_pb_pressed()));
   }
}

MainWindow::~MainWindow() {
    Logger::v("MainWindow","destructor called");
    this->saveState();
    delete ui;
}

void MainWindow::saveState() {
    Logger::v("MainWindow","saveState");
    QString state = this->currentPile()->stateToString();
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
        this->currentPile()->stateFromString(state);
        this->currentPile()->refreshScreen();
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
        this->currentPile()->on_input_returnPressed();
    }
    else if (value == "space") {
        this->currentPile()->addInput(" ");
    }
    else {
        this->currentPile()->addInput(value);
    }
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close();
}

void MainWindow::on_actionRetablir_triggered()
{
    Logger::v("MainWindow","ctrl+y triggered");
    this->currentPile()->retablir();
}

void MainWindow::on_actionAnnuler_triggered()
{
    Logger::v("MainWindow","ctrl+z triggered");
    this->currentPile()->annuler();
}

void MainWindow::showError(const QString & s) {
    this->statusBar()->showMessage(s, 2000);
}

PileWidget* MainWindow::currentPile() const {
    return (PileWidget*) ui->tabWidget->currentWidget();
}

void MainWindow::on_actionNouvel_onglet_triggered() {
    int index = rand() % NB_FUNNY_NAMES;
    ui->tabWidget->addTab(new PileWidget(), FUNNY_NAMES[index]);

    connect(this->currentPile(), SIGNAL(error(QString)), this, SLOT(showError(QString)));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}

void MainWindow::on_actionFerme_l_onglet_triggered() {
    ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}


const char* FUNNY_NAMES[NB_FUNNY_NAMES] = {
    "Ball",
    "Bell",
    "Booth",
    "Bubble",
    "Button",
    "Curtain",
    "Hammer",
    "House",
    "Bang",
    "Bent",
    "Burn",
    "Dent",
    "Cancel",
    "Chase",
    "Close",
    "Cook",
    "Cutlip",
    "Fry",
    "Guess",
    "Hunt",
    "Keeping",
    "Loop",
    "Hook",
    "Mask",
    "Penny",
    "Pant",
    "Page",
    "Pill",
    "Shower",
    "Shoemaker",
    "Stone",
    "Snowball",
    "Train",
    "Vigil",
    "Wall",
    "Apple",
    "Berry",
    "Cherry",
    "Maples",
    "Mango",
    "Milk",
    "Rose",
    "Rice",
    "Flowers",
    "Wheat",
    "Black",
    "Blue",
    "Gray",
    "Green",
    "White"
};

