#include "textresultwindow.h"
#include "ui_textresultwindow.h"

TextResultWindow::TextResultWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextResultWindow)
{
    ui->setupUi(this);
}

TextResultWindow::~TextResultWindow()
{
    delete ui;
}

void TextResultWindow::setResult(QList<textResult> res){
    this->result = res;

}

void TextResultWindow::showResult(){
    int total = 0;
    ui->listWidget->addItem("Touche \t Temps (ms)");
    for(int i = 0; i<result.count(); i++){
        ui->listWidget->addItem(result.at(i).letter + "\t" + QString::number(result.at(i).time));
        total = total + result.at(i).time;
    }
    total = total / (result.count());
    ui->label->setText("Temps moyen : " +  QString::number(total) + "ms");
    ui->label_2->setText("Votre temps moyen de frappe est de " + QString::number(total/1000.0) + "s. Vous pouvez effectuer un test d'arborescence en utilisant cette valeur pour Tk.");
}
