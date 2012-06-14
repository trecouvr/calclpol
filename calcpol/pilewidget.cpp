#include "pilewidget.h"
#include "ui_pilewidget.h"


PileWidget::PileWidget(QWidget *parent) :
    QWidget(parent),
	ui(new Ui::PileWidget),
	_saveIndex(0)
{
    ui->setupUi(this);
    ui->listView->setModel(&_listModel);

    connect(ui->cb_complex, SIGNAL(toggled(bool)), this, SLOT(setComplexMode(bool)));
    connect(ui->rb_entier, SIGNAL(clicked()), this, SLOT(onChooseEntier()));
    connect(ui->rb_reel, SIGNAL(clicked()), this, SLOT(onChooseReel()));
    connect(ui->rb_rationnel, SIGNAL(clicked()), this, SLOT(onChooseRationnel()));
}

void PileWidget::onChooseEntier() { this->setConstantMode(IConstant::ENTIER); }
void PileWidget::onChooseReel() { this->setConstantMode(IConstant::REEL); }
void PileWidget::onChooseRationnel() { this->setConstantMode(IConstant::RATIONNEL); }

PileWidget::~PileWidget()
{
    delete ui;
}

void PileWidget::refreshScreen() {
	QStringList list;
	for (Calculator::const_reverse_iterator it=_calculator.rbegin(); it!=_calculator.rend(); ++it) {
		list << (*it)->toString();
	}
	_listModel.setStringList(list);
}

void PileWidget::eval() {
    QString input = ui->input->text();
    try {
        _calculator.eval(input);
        ui->input->clear();
	refreshScreen();
	// Gestion de la pile pour avancer/reculer (ctrl+Z, ctrl+y)
	while(_saveIndex != _save.size())
		_save.pop_back();
	_save.push_back(_calculator.stateToString());
	_saveIndex++;
    }
    catch (exception &ex) {
        emit error(QString(ex.what()));
    }
}

void PileWidget::annuler() {
	Logger::v("PileWidget", "annuler() called");
	if(_saveIndex > 0) {
		Logger::d("PileWidget", "string is :"+_save[_saveIndex - 1]);
		_calculator.stateFromString(_save[_saveIndex - 1]);
		_saveIndex--;
	}
	refreshScreen();
}

void PileWidget::retablir() {
	Logger::v("PileWidget", "retablir() called");
	if(_saveIndex < _save.size()) {
		Logger::d("PileWidget", "string is :"+_save[_saveIndex]);
		_calculator.stateFromString(_save[_saveIndex]);
		_saveIndex++;
	}
	refreshScreen();
}

void PileWidget::on_input_returnPressed() {
    eval();
}

void PileWidget::setComplexMode(bool b) {_calculator.complex(b); }
void PileWidget::setConstantMode(IConstant::T_CONSTANT t) {_calculator.t_constant(t);}

void PileWidget::addInput(const QString& s) {
    QString current = ui->input->text();
    ui->input->setText(ui->input->text()+s);
}

QString PileWidget::stateToString() const {
    return _calculator.stateToString();
}

void PileWidget::stateFromString(const QString & state) {
    _calculator.stateFromString(state);
}


/*
void MainWindow::setEntierMode() {
    this->currentPile()->setConstantMode(IConstant::ENTIER);
}

void MainWindow::setReelMode() {
    this->currentPile()->setConstantMode(IConstant::REEL);
}

void MainWindow::setRationnelMode() {
    this->currentPile()->setConstantMode(IConstant::RATIONNEL);
}
*/
