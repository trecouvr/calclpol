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

void PileWidget::on_input_returnPressed()
{
    eval();
}
