#include "resultswindow.h"
#include "ui_resultswindow.h"
#include <math.h>
#include <stdlib.h>
#include <QMessageBox>

ResultsWindow::ResultsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultsWindow)
{
    ui->setupUi(this);
    ui->toolButton->hide();
}

ResultsWindow::~ResultsWindow()
{
    delete ui;
}

void ResultsWindow::setFittsResults(QList<fittsResult> res){
    this->results = res;

   ui->listWidget->addItem("T réel \t T théorique \t différence (ms)");


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
    ui->listWidget->addItem("T réel \t T théorique \t différence (ms)");
    for(int i = 0; i<results.count()-1; i++){

        double theoricTime = 1000 * (ui->doubleSpinBox->value() + ui->doubleSpinBox_2->value() * log(1+((double)results.at(i+1).distance / (double)results.at(i+1).size)));
        ui->listWidget->addItem(QString::number(results.at(i+1).realTime) + " \t " + QString::number((int)theoricTime) + " \t " + QString::number(results.at(i+1).realTime - (int)theoricTime));
        results.at(i+1).theoTime = (int)theoricTime;
    }
    ui->label->setText("erreur moyenne : " + QString::number(calculateStatistics()) + "ms");
}


void ResultsWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    arg1; /* avoid warning */
    recalculateAB();
}

void ResultsWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    arg1;
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
        /* Create and display Axes*/
        painter.setPen(QPen(QColor(220,220,220)));
        painter.drawLine(0,hei/2,wid,hei/2);
        painter.drawLine(wid/2,0,wid/2,hei);
        painter.drawText(wid-50,hei/2-4, "distance");
        painter.drawText(wid/2+2,10, "temps");

        /* Display error lines if needed */
        if(ui->checkBox->checkState()){
            painter.setPen(QPen(QColor(currentErr,255-currentErr,0)));
            painter.drawLine(results.at(i+1).distance*2+results.at(i+1).size/16,results.at(i+1).realTime/5,results.at(i+1).distance*2+results.at(i+1).size/16,results.at(i+1).theoTime/5);
        }


        currentErr = abs(results.at(i+1).theoTime - results.at(i+1).realTime);
        baseError += currentErr;

        ui->listWidget->item(i+1)->setBackgroundColor(QColor(255, 255-currentErr, 255-currentErr));

        painter.setPen(Qt::black);
        painter.setBrush(QBrush(QColor(0,100,255)));
        painter.drawEllipse( results.at(i+1).distance*2, results.at(i+1).realTime/5, results.at(i+1).size/8, results.at(i+1).size/8);
        painter.setBrush(QBrush(QColor(currentErr,255-currentErr,0)));
        painter.drawEllipse( results.at(i+1).distance*2, results.at(i+1).theoTime/5, results.at(i+1).size/8, results.at(i+1).size/8);


    }

    /*highlight the selected item */
    if(currentrow >= 0){
        painter.setBrush(QBrush(QColor(255,100,0)));
        painter.setPen(QPen(QColor(255,100,0)));
        painter.drawEllipse( results.at(currentrow).distance*2, results.at(currentrow).realTime/5, results.at(currentrow).size/8, results.at(currentrow).size/8);
        painter.drawEllipse( results.at(currentrow).distance*2, results.at(currentrow).theoTime/5, results.at(currentrow).size/8, results.at(currentrow).size/8);
        painter.drawLine(results.at(currentrow).distance*2+results.at(currentrow).size/16,results.at(currentrow).realTime/5,results.at(currentrow).distance*2+results.at(currentrow).size/16,results.at(currentrow).theoTime/5);
    }

    /* legend */
    painter.setPen(QPen(QColor(0,0,0)));
    painter.setBrush(QBrush(QColor(0,100,255)));
    painter.drawEllipse( wid - 60, hei - 10, 5, 5);
    painter.drawText(wid - 50, hei - 3, "réel");
    painter.setBrush(QBrush(QColor(75,180,0)));
    painter.drawEllipse( wid - 60, hei - 20, 5, 5);
    painter.drawText(wid - 50, hei - 13, "théorique");

    double finalError = baseError / (results.count()-1);

    ui->label_4->setPixmap(pixmap);

    return finalError;
}

void ResultsWindow::on_checkBox_clicked()
{
    calculateStatistics();
}

void ResultsWindow::on_toolButton_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer résultat", "Voulez-vous supprimer le résultat sélectionné?", QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          if(currentrow>0){
              this->results.removeAt(currentrow);
              ui->listWidget->setCurrentRow(currentrow - 1); /* avoid crash */
              calculateStatistics();
              recalculateAB();
              ui->toolButton->hide();
          }
          else{QMessageBox::information(this, "Opération illégale", "Vous ne pouvez pas supprimer cette ligne, ce n'est pas un résultat");


          }
      }
}

void ResultsWindow::on_listWidget_currentRowChanged(int currentRow)
{
    ui->toolButton->show();
    this->currentrow = currentRow;
    calculateStatistics();
}
