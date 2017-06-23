#include "textinputwindow.h"
#include "ui_textinputwindow.h"
#include "textresultwindow.h"

QTime text_timer;

textInputWindow::textInputWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::textInputWindow)
{
    ui->setupUi(this);
}

textInputWindow::~textInputWindow()
{
    delete ui;
}

void textInputWindow::on_textEdit_textChanged()
{
    changeLetter();
}

void textInputWindow::changeLetter()
{
    if(index > 0 ){ /* && ui->textEdit->toPlainText().at(index) == corpus.at(index) */
        textResult *res = new textResult(text_timer.elapsed(),corpus.at(index-1));
        result.append(*res);
    }

    if(index < length){
        ui->textEdit_2->setText(corpus.at(index));
        index++;
    }else{
       TextResultWindow * newTextResultWindow = new TextResultWindow();
       newTextResultWindow->setResult(this->result);
       newTextResultWindow->show();
       newTextResultWindow->showResult();
       this->close();
    }



    text_timer.start();
}

void textInputWindow::setlength(int l){
    if(l>corpus.length()){
        l = corpus.length();
    }else{
        this->length = l;
    }
}

void textInputWindow::setcorpus(QString c){
    this->corpus = c;
    setlength(c.length());
}
