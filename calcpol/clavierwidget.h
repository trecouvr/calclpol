#ifndef CLAVIERWIDGET_H
#define CLAVIERWIDGET_H

#include <QWidget>

namespace Ui {
    class ClavierWidget;
}

class ClavierWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClavierWidget(QWidget *parent = 0);
    ~ClavierWidget();

private:
    Ui::ClavierWidget *ui;
};

#endif // CLAVIERWIDGET_H
