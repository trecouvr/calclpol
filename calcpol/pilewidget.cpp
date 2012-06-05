#include "pilewidget.h"
#include "ui_pilewidget.h"


PileWidget::PileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PileWidget)
{
    ui->setupUi(this);
    ui->listView->setModel(&_listModel);
}

PileWidget::~PileWidget()
{
    delete ui;
}

void PileWidget::eval() {
    QString input = ui->input->text();
    _calculator.eval(input);
    ui->input->clear();
    QStringList list;
    for (Calculator::const_iterator it=_calculator.begin(); it!=_calculator.end(); ++it) {
        list << (*it)->toString();
    }
    _listModel.setStringList(list);
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
