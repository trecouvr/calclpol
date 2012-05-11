#include "pilewidget.h"
#include "ui_pilewidget.h"

PileWidget::PileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PileWidget)
{
    ui->setupUi(this);
}

PileWidget::~PileWidget()
{
    delete ui;
}
