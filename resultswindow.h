#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QWidget>
#include "fittsresult.h"

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

private:
    Ui::ResultsWindow *ui;
    QList<fittsResult> results;
};

#endif // RESULTSWINDOW_H
