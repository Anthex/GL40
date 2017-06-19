#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H
#include <QWidget>
#include "fittsresult.h"
#include <QPainter>

namespace Ui {
class ResultsWindow;
}
class ResultsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ResultsWindow(QWidget *parent = 0);
    ~ResultsWindow();
    void setFittsResults(QList<fittsResult> res);
    void recalculateAB();
    double calculateStatistics();
private slots:
    void on_pushButton_3_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

private:
    Ui::ResultsWindow *ui;
    QList<fittsResult> results;
    double meanerror;
};

#endif // RESULTSWINDOW_H
