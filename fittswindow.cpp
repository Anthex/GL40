#include "fittswindow.h"
#include "ui_fittswindow.h"
#include "resultswindow.h"
//#include <QtCore/qmath.h>
#include <math.h>

int xa,ya,x_,y_,dim;
int count;

QTime t;

fittsWindow::fittsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fittsWindow)
{
    ui->setupUi(this);
}

fittsWindow::~fittsWindow()
{
    delete ui;
}

void fittsWindow::on_label_2_clicked()
{
    /* get mouse position and convert it into global data */
    x_ = ui->label_2->mapFromGlobal(QCursor::pos()).x();
    y_ = ui->label_2->mapFromGlobal(QCursor::pos()).y();
    int elapsedTime = t.elapsed();
    ui->label->setText("■");


    QLineF line = QLineF(x_, y_, xa, ya);

    double theoricTime = this->a + this->b * log(1+(line.length()/dim))/log(2); //log base 2

    fittsResult *res = new fittsResult(elapsedTime,theoricTime*1000,line.length(),dim);

    if(line.length() > dim && elapsedTime > 0){
        ui->label->setStyleSheet("QLabel { color: red }"); /* hors cible */
        /* Off target : discard the result don't increment*/
    }else{
        ui->label->setStyleSheet("QLabel { color: lime }");/* sur cible  */
        results.append(*res);   /* On target : save the result*/
        count++;
    }

    if(count > n){
        ResultsWindow *fittsRes = new ResultsWindow();
        fittsRes->setFittsResults(this->results);
        fittsRes->show();
        this->close();
    }
    displayScene();
}

void fittsWindow::displayScene(){
    int wid,hei;
    t.start();
    wid = ui->label_2->geometry().width();
    hei = ui->label_2->geometry().height();
    QPixmap pixmap(wid,hei);
    pixmap.fill(QColor("white"));
    QPainter painter(&pixmap);
    painter.setBrush(QBrush(Qt::green));
    dim = rand() % (max-min) + min;
    xa = rand() % (wid - dim*2)+dim; /* make sure the circle isn't cropped and is in an accessible zone */
    ya = rand() % (hei - dim*2)+dim;
    painter.drawEllipse( xa, ya, dim, dim);
    ui->label_2->setPixmap(pixmap);
}

void fittsWindow::setData(int n_, int min_, int max_){
    count = 0;
    n = n_;
    min = min_;
    max = max_;
    results = * new QList<fittsResult>();
}

void fittsWindow::setConstants(double a_,double b_){
    this->a = a_;
    this->b = b_;
}
