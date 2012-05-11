#include "clavierwidget.h"
#include "ui_clavierwidget.h"

ClavierWidget::ClavierWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClavierWidget)
{
    ui->setupUi(this);
}

ClavierWidget::~ClavierWidget()
{
    delete ui;
}
