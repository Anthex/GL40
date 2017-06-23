#ifndef EXPLORERRESULTSWINDOW_H
#define EXPLORERRESULTSWINDOW_H

#include <QMainWindow>
#include "explorerresult.h"

namespace Ui {
class ExplorerResultsWindow;
}

class ExplorerResultsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExplorerResultsWindow(QWidget *parent = 0);
    ~ExplorerResultsWindow();
    explorerResult * result;
    void updateInfo();
private slots:
    void on_pushButton_clicked();

private:
    int theoricTime;
    Ui::ExplorerResultsWindow *ui;
};

#endif // EXPLORERRESULTSWINDOW_H
