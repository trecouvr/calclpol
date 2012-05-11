#ifndef PILEWIDGET_H
#define PILEWIDGET_H

#include <QWidget>

namespace Ui {
    class PileWidget;
}

class PileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PileWidget(QWidget *parent = 0);
    ~PileWidget();

private:
    Ui::PileWidget *ui;
};

#endif // PILEWIDGET_H
