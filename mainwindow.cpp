#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QPixmap>
#include <QFileInfo>
#include <QMessageBox>
#include <QFileDialog>

QDir *directory;
int complexity; /* number of levels */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /* ui setup */
    ui->setupUi(this);
    ui->label_5->setText(QString::number(ui->horizontalSlider->value()));
    ui->label_6->setText(QString::number(ui->horizontalSlider_2->value()));
    ui->label_7->setText(QString::number(ui->horizontalSlider_3->value()));

    ui->lineEdit_3->hide();

    /* Display Fitts equation image */
    QPixmap image("fittsEquation.png");
    ui->label_22->setPixmap(image);

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
        newFittsWindow->setConstants(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value());
        newFittsWindow->show();
        break;
    case 1:
        newTextWindow = new textInputWindow();
        if(ui->checkBox_2->checkState()){
            newTextWindow->setcorpus(ui->lineEdit_3->text());
        }else{
            newTextWindow->setlength(ui->spinBox->value());
        }
        newTextWindow->show();
        break;
    case 2:
        if(QDir(ui->lineEdit->text()).exists() || QFileInfo::exists(ui->lineEdit->text()))
        {
            complexity = ui->lineEdit->text().count(QLatin1Char('/')) -  ui->lineEdit_2->text().count(QLatin1Char('/'));
            newExplorerWindow = new explorerWindow();
            newExplorerWindow->setStart(ui->lineEdit_2->text());
            newExplorerWindow->setTarget(ui->lineEdit->text());
            newExplorerWindow->setResult(ui->doubleSpinBox_3->value(),ui->doubleSpinBox_4->value(),ui->doubleSpinBox_6->value(),ui->doubleSpinBox_5->value());
            newExplorerWindow->setnk(complexity);
            newExplorerWindow->setnm(1);
            if(ui->checkBox->checkState()){
                newExplorerWindow->setnh(1);
            }else{
                newExplorerWindow->setnh(0);
            }
            newExplorerWindow->setnp(complexity);
            newExplorerWindow->show();
        }else{
            QMessageBox::information(this, "Cible inexistante", "Le dossier ou fichier spécifié n'existe pas, merci de spécifier un chemin valide");
        }
        break;
    }

}

void MainWindow::on_toolButton_clicked()
{
    ui->lineEdit->setText(QFileDialog::getOpenFileName(this, "Sélectionner chemin "));
}

void MainWindow::on_checkBox_2_clicked()
{
    if (ui->checkBox_2->checkState()){
        ui->lineEdit_3->show();
        ui->spinBox->setEnabled(false);
    }else{
        ui->lineEdit_3->hide();
        ui->spinBox->setEnabled(true);
    }
}
