#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "optiondialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void saveState();
    void loadState();

private slots:
    void on_actionPreferences_triggered();
    void on_pb_pressed();
    void setEntierMode();
    void setReelMode();
    void setRationnelMode();
    void on_actionQuitter_triggered();
    void on_actionRetablir_triggered();
    void on_actionAnnuler_triggered();

private:
    Ui::MainWindow *ui;
    OptionDialog *_optionDialog;
};

#endif // MAINWINDOW_H
