#include "explorerwindow.h"
#include "ui_explorerwindow.h"

explorerWindow::explorerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::explorerWindow)
{
    ui->setupUi(this);
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

        /* Juste pour test */
        ui->label_2->setStyleSheet("QLabel { background-color : #999999; color : red; }");
        ui->label_2->setText("TROUVE");

        return true;
    }
    else{
        return false;
    }
}
