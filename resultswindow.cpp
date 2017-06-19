#include "resultswindow.h"
#include "ui_resultswindow.h"
#include <math.h>

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

    /*
    ui->tableWidget->setRowCount(results.count());
    ui->tableWidget->setColumnCount(2);

    for(int i=0; i<2; i++)
    {
      for(int j=0; j<results.count(); j++)
      {
       ui->tableWidget->setItem( i, j, new QTableWidgetItem() );
      }
    }

    ui->tableWidget->horizontalHeaderItem(0)->setText("distance");
    ui->tableWidget->horizontalHeaderItem(1)->setText("Temps réel");

    */
   ui->listWidget->addItem("Temps pris - Temps théorique ");


    for(int i = 0; i<results.count()-1; i++){
        //this->ui->tableWidget->item(i, 0)->setText(QString::number(results.at(i+1).theoTime));
        //this->ui->tableWidget->item(i, 1)->setText(QString::number(results.at(i+1).realTime));
        //this->ui->tableWidget->item(i, 2)->setText(QString::number(results.at(i).distance));
        //ui->label->setText( ui->label->text() + "  \n  " + QString::number(results.at(i+1).realTime)+ "  " + QString::number(results.at(i+1).theoTime));
        ui->listWidget->addItem(QString::number(results.at(i+1).realTime) + " - " + QString::number(results.at(i+1).theoTime));
    }

}

void ResultsWindow::on_pushButton_3_clicked()
{
    recalculateAB();
}

void ResultsWindow::recalculateAB(){
    ui->listWidget->clear(); // erasing previous data
    ui->listWidget->addItem("Temps pris - Temps théorique ");
    for(int i = 0; i<results.count()-1; i++){

        double theoricTime = 1000 * (ui->doubleSpinBox->value() + ui->doubleSpinBox_2->value() * log(1+((double)results.at(i+1).distance / (double)results.at(i+1).size)));
        ui->listWidget->addItem(QString::number(results.at(i+1).realTime) + " - " + QString::number(theoricTime));
        results.at(i+1).theoTime = (int)theoricTime;
    }
    ui->label->setText("erreur moyenne : " + QString::number(calculateStatistics()) + "ms");
}


void ResultsWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    recalculateAB();
}

void ResultsWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    recalculateAB();
}


double ResultsWindow::calculateStatistics(){
    int wid,hei;
    int currentErr;
    wid = ui->label_4->geometry().width();
    hei = ui->label_4->geometry().height();
    QPixmap pixmap(wid,hei);
    pixmap.fill(QColor("white"));
    QPainter painter(&pixmap);


    double baseError = 0;
    for(int i = 0; i<results.count()-1; i++){
        currentErr = abs(results.at(i+1).theoTime - results.at(i+1).realTime);
        baseError =+ currentErr;
        painter.setBrush(QBrush(Qt::green));
        painter.drawEllipse( results.at(i+1).distance*2, results.at(i+1).realTime/5, results.at(i+1).size/10, results.at(i+1).size/10);
        painter.setBrush(QBrush(QColor(currentErr,0,255-currentErr)));
        painter.drawEllipse( results.at(i+1).distance*2, results.at(i+1).theoTime/5, results.at(i+1).size/10, results.at(i+1).size/10);
        painter.drawLine(0,hei/2,wid,hei/2);
        painter.drawLine(wid/2,0,wid/2,hei);
        painter.drawText(wid-50,hei/2-4, "distance");
        painter.drawText(wid/2+2,10, "temps");
    }
    baseError = baseError / (results.count());



    ui->label_4->setPixmap(pixmap);


    return baseError;
}
