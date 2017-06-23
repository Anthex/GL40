#include "explorerresultswindow.h"
#include "ui_explorerresultswindow.h"

ExplorerResultsWindow::ExplorerResultsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExplorerResultsWindow)
{
    ui->setupUi(this);
}

ExplorerResultsWindow::~ExplorerResultsWindow()
{
    delete ui;
}

void ExplorerResultsWindow::on_pushButton_clicked()
{

}

void ExplorerResultsWindow::updateInfo(){
    ui->Mlab->setText(QString::number(result->nbM));
    ui->Plab->setText(QString::number(result->nbP));
    ui->Klab->setText(QString::number(result->nbK));
    ui->Hlab->setText(QString::number(result->nbH));

    theoricTime = 1000 * (result->nbH*result->th + result->nbK*result->tk + result->nbP*result->tp + result->nbM*result->tm);

    ui->label_12->setText(QString::number(theoricTime) + "ms");
    ui->label_13->setText(QString::number(result->realTime) + "ms");
    ui->label_15->setText(QString::number(100*abs(theoricTime-result->realTime)/theoricTime) + "%");
}
