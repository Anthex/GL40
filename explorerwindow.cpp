#include "explorerwindow.h"
#include "ui_explorerwindow.h"
#include "explorerresult.h"
#include "explorerresultswindow.h"
#include <QTime>

QTime timer;

explorerWindow::explorerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::explorerWindow)
{
    ui->setupUi(this);
    timer.start();
}

explorerWindow::~explorerWindow()
{
    delete ui;
}

void explorerWindow::setTarget(QString newTarget){
    target = newTarget;
    ui->label->setText("Chemin du fichier : " + target);
}

void explorerWindow::setStart(QString newStart){
    start = newStart;
    model = new QFileSystemModel;
    model->setRootPath(QDir::homePath());
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->setRootPath(start));
}

bool explorerWindow::checkIfFound(QModelIndex index){
    QString currentPath = model->filePath(index);
    ui->label_2->setText("Chemin actuel : "  + currentPath);
    if (currentPath == target){

        /* Testing - To implement */
        ui->label_2->setStyleSheet("QLabel { background-color : #999999; color : red; }");
        ui->label_2->setText("TROUVE");
        int realtime = timer.elapsed();
        result->realTime = realtime;
        ExplorerResultsWindow *reswindow = new ExplorerResultsWindow();
        reswindow->result = this->result;
        reswindow->show();
        reswindow->updateInfo();
        this->close();
        return true;
    }
    else{
        return false;
    }
}

void explorerWindow::setResult(double tk, double tp, double tm, double th){
    explorerResult * newRes = new explorerResult();
    result = newRes;
    result->tk = tk;
    result->tp = tp;
    result->tm = tm;
    result->th = th;
}

void explorerWindow::setnk(int nk){
    this->result->nbK = nk;
}

void explorerWindow::setnp(int np){
    this->result->nbP = np;
}

void explorerWindow::setnm(int nm){
    this->result->nbM = nm;
}

void explorerWindow::setnh(int nh){
    this->result->nbH = nh;
}

