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
    void refreshScreen();
    void eval();
    void addInput(const QString&);
    void annuler();
    void retablir();
    QString stateToString() const;
    void stateFromString(const QString&);
    void setConstantMode(IConstant::T_CONSTANT t);

signals:
    void error(QString);

public slots:
    void on_input_returnPressed();
    void setComplexMode(bool);
    void onChooseEntier();
    void onChooseReel();
    void onChooseRationnel();

private:
    Ui::PileWidget *ui;
    Calculator _calculator;
    QStringListModel _listModel;
    QVector<QString> _save;
    unsigned int _saveIndex;

};

#endif // PILEWIDGET_H
