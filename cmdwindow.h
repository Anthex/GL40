#ifndef CMDWINDOW_H
#define CMDWINDOW_H
#include <QWidget>

namespace Ui {
class cmdWindow;
}

class cmdWindow : public QWidget
{
    Q_OBJECT

public:
    explicit cmdWindow(QWidget *parent = 0);
    ~cmdWindow();

private:
    Ui::cmdWindow *ui;
};

#endif // CMDWINDOW_H
