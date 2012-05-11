#ifndef PILEWIDGET_H
#define PILEWIDGET_H

#include <QWidget>

#include <QStringListModel>
#include <QStringList>

namespace Ui {
    class PileWidget;
}

class PileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PileWidget(QWidget *parent = 0);
    ~PileWidget();

private slots:
        void on_input_returnPressed();

private:
    void eval();
    QStringListModel _listModel;
    QStringList _list;
    Ui::PileWidget *ui;
};

#endif // PILEWIDGET_H
