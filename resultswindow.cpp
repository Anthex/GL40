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
    //ui->label->setText(QString::number(results.at(1).realTime)+ "ms -  " + QString::number(results.at(1).distance) + "pix");

    ui->label->setText("Taille de l'échantillon : " + QString::number(results.length()));

    ui->tableWidget->setRowCount(results.count());
    ui->tableWidget->setColumnCount(2);

    for(int i=0; i<2; i++)
    {
      for(int j=0; j<results.count(); j++)
      {
       ui->tableWidget->setItem( i, j, new QTableWidgetItem() );
      }
    }

    //ui->tableWidget->horizontalHeaderItem(0)->setText("distance");
    //ui->tableWidget->horizontalHeaderItem(1)->setText("Temps réel");

    ui->label->setText(QString::number(results.count()));


    for(int i = 0; i<results.count()-2; i++){
        this->ui->tableWidget->item(i, 0)->setText(QString::number(results.at(i+1).theoTime));
        this->ui->tableWidget->item(i, 1)->setText(QString::number(results.at(i+1).realTime));
        //this->ui->tableWidget->item(i, 2)->setText(QString::number(results.at(i).distance));
    }

}
