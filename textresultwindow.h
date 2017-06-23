#ifndef TEXTRESULTWINDOW_H
#define TEXTRESULTWINDOW_H

#include <QWidget>
#include <QList>
#include <textresult.h>

namespace Ui {
class TextResultWindow;
}

class TextResultWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TextResultWindow(QWidget *parent = 0);
    ~TextResultWindow();
    void setResult(QList<textResult> res);
    void showResult();
private:
    Ui::TextResultWindow *ui;
    QList<textResult> result;
};

#endif // TEXTRESULTWINDOW_H
