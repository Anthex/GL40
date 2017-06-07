#include "textinputwindow.h"
#include "ui_textinputwindow.h"

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

}

void textInputWindow::changeLetter()
{
    //ui->textEdit_2->setText(corpus.);//TODO
}
