#include "resultswindow.h"
#include "ui_resultswindow.h"
#include <math.h>
#include <stdlib.h>

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

   ui->listWidget->addItem("Temps pris - Temps théorique ");


    for(int i = 0; i<results.count()-1; i++){
        ui->listWidget->addItem(QString::number(results.at(i+1).realTime) + " - " + QString::number(results.at(i+1).theoTime));
    }

    calculateStatistics();
    recalculateAB();
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
    double baseError = 0;
    wid = ui->label_4->geometry().width();
    hei = ui->label_4->geometry().height();
    QPixmap pixmap(wid,hei);
    pixmap.fill(QColor("white"));
    QPainter painter(&pixmap);


    for(int i = 0; i<results.count()-1; i++){
        currentErr = abs(results.at(i+1).theoTime - results.at(i+1).realTime);
        baseError += currentErr;
        painter.setBrush(QBrush(QColor(0,100,255)));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse( results.at(i+1).distance*2, results.at(i+1).realTime/5, results.at(i+1).size/8, results.at(i+1).size/8);
        painter.setBrush(QBrush(QColor(currentErr,255-currentErr,100)));
        painter.drawEllipse( results.at(i+1).distance*2, results.at(i+1).theoTime/5, results.at(i+1).size/8, results.at(i+1).size/8);
        painter.setPen(QPen(QColor(220,220,220)));
        painter.drawLine(0,hei/2,wid,hei/2);
        painter.drawLine(wid/2,0,wid/2,hei);
        painter.drawText(wid-50,hei/2-4, "distance");
        painter.drawText(wid/2+2,10, "temps");
    }
    double finalError = baseError / (results.count()-1);



    ui->label_4->setPixmap(pixmap);


    return finalError;
}
