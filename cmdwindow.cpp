#include "cmdwindow.h"
#include "ui_cmdwindow.h"

cmdWindow::cmdWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cmdWindow)
{
    ui->setupUi(this);
}

cmdWindow::~cmdWindow()
{
    delete ui;
}
