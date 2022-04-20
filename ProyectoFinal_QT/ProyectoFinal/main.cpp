#include "mainwindow.h"
#include "inicio.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    inicio w;
    w.show();
    return a.exec();
}
