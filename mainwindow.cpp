#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

QDir *directory;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /* ui setup */
    ui->setupUi(this);
    ui->textEdit->hide();
    ui->label_5->setText(QString::number(ui->horizontalSlider->value()));
    ui->label_6->setText(QString::number(ui->horizontalSlider_2->value()));
    ui->label_7->setText(QString::number(ui->horizontalSlider_3->value()));

    /* Defining starting and target paths arbitrarily */
    QFileSystemModel *model = new QFileSystemModel;
    directory = new QDir;

    directory->setPath(QDir::homePath());
    model->setRootPath(directory->absolutePath());

    ui->lineEdit->setText(model->rootPath()+"/test.file");
    //directory->cdUp(); //TODO : failsafe (see return value)

    ui->lineEdit_2->setText(directory->absolutePath());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int SelectedTab = ui->tabWidget->currentIndex(); //Each test has a dedicated tab
    switch(SelectedTab){
    case 0:
        newFittsWindow = new fittsWindow();
        newFittsWindow->setData(ui->horizontalSlider->value(), ui->horizontalSlider_2->value(), ui->horizontalSlider_3->value());
        newFittsWindow->show();
        break;
    case 1:
        newTextWindow = new textInputWindow();
        newTextWindow->show();
        break;
    case 2:
        newExplorerWindow = new explorerWindow();
        newExplorerWindow->setStart(ui->lineEdit_2->text());
        newExplorerWindow->setTarget(ui->lineEdit->text());
        newExplorerWindow->show();
        break;
    case 3:
        newCmdWindow = new cmdWindow();
        newCmdWindow->show();
        break;
    }

}
