#ifndef TEXTINPUTWINDOW_H
#define TEXTINPUTWINDOW_H
#include <QWidget>
#include "textresult.h"
#include <QList>
#include <QTime>

namespace Ui {
class textInputWindow;
}

class textInputWindow : public QWidget
{
    Q_OBJECT
public:
    explicit textInputWindow(QWidget *parent = 0);
    void setlength(int l);
    void setcorpus(QString c);
    ~textInputWindow();
private slots:
    void on_textEdit_textChanged();
    void changeLetter();
private:
    Ui::textInputWindow *ui;
    QString corpus = "aliquamutlacusinmaurisgravidacursus";
    int index = 0;
    int length = 8;
    QList<textResult> result;
};

#endif // TEXTINPUTWINDOW_H
