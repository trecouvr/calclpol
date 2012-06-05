#ifndef PILEWIDGET_H
#define PILEWIDGET_H

#include <QWidget>

#include <QStringListModel>
#include <QStringList>

#include "calculator.h"

namespace Ui {
    class PileWidget;
}

class PileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PileWidget(QWidget *parent = 0);
    ~PileWidget();
    void eval();
    void addInput(const QString&);

public slots:
    void on_input_returnPressed();
    void setComplexMode(bool);

private:
    Ui::PileWidget *ui;
    Calculator _calculator;
    QStringListModel _listModel;
};

#endif // PILEWIDGET_H
