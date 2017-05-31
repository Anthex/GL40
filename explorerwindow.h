#ifndef EXPLORERWINDOW_H
#define EXPLORERWINDOW_H
#include <QWidget>
#include <QFileSystemModel>
#include <QDir>
#include <QString>

namespace Ui {
class explorerWindow;
}

class explorerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit explorerWindow(QWidget *parent = 0);
    ~explorerWindow();


public slots:
    void setTarget(QString);
    void setStart(QString);
    bool checkIfFound(QModelIndex);

private:
    Ui::explorerWindow *ui;
    QFileSystemModel *model ;
    QString target="null", start="null";
};

#endif // EXPLORERWINDOW_H
