#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    return a.exec();
}
