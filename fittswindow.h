#ifndef FITTSWINDOW_H
#define FITTSWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QList>
#include "fittsresult.h"


namespace Ui {
class fittsWindow;
}

class fittsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit fittsWindow(QWidget *parent = 0);
    ~fittsWindow();

private slots:
    void on_label_2_clicked();

public slots:
    int displayScene();
    void setData(int,int,int);

private:
    Ui::fittsWindow *ui;
    /* Default values */
    int n=10, min=50, max=100;
    QList<fittsResult> results;
};



#endif // FITTSWINDOW_H
