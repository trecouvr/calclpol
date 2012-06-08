#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QDialog>

namespace Ui {
    class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    enum T_CONSTANT {ENTIER, REEL, RATIONNEL};
    struct Options {
        T_CONSTANT t_constant;
        bool radian;
        bool complex;
        bool clavier;
    };
    explicit OptionDialog(QWidget *parent = 0);
    ~OptionDialog();

signals:
    void complexModeToggled(bool);

private:
    Ui::OptionDialog *ui;
};

#endif // OPTIONDIALOG_H
