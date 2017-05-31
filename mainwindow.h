#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fittswindow.h"
#include "explorerwindow.h"
#include "cmdwindow.h"
#include "textinputwindow.h"
#include <QFileSystemModel>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    fittsWindow * newFittsWindow;
    explorerWindow * newExplorerWindow;
    cmdWindow * newCmdWindow;
    textInputWindow * newTextWindow;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
