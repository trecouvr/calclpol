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
    _list << ui->input->text();
    ui->input->clear();
    _listModel.setStringList(_list);
}

void PileWidget::on_input_returnPressed()
{
    eval();
}
