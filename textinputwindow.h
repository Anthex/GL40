#ifndef TEXTINPUTWINDOW_H
#define TEXTINPUTWINDOW_H

#include <QWidget>

namespace Ui {
class textInputWindow;
}

class textInputWindow : public QWidget
{
    Q_OBJECT

public:
    explicit textInputWindow(QWidget *parent = 0);
    ~textInputWindow();

private slots:
    void on_textEdit_textChanged();
    void changeLetter();
private:
    Ui::textInputWindow *ui;
    QString corpus = "Aliquam ut lacus in mauris gravida cursus";
    int index = 0;
};

#endif // TEXTINPUTWINDOW_H
