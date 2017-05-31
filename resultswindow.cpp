#include "resultswindow.h"
#include "ui_resultswindow.h"

ResultsWindow::ResultsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultsWindow)
{
    ui->setupUi(this);
}

ResultsWindow::~ResultsWindow()
{
    delete ui;
}

void ResultsWindow::setFittsResults(QList<fittsResult> res){
    this->results = res;
    ui->label->setText(QString::number(results.at(1).realTime)+ "ms -  " + QString::number(results.at(1).distance) + "pix");
}
