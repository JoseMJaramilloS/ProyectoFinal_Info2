#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dim_x=1024;
    dim_y=720;
    scene = new QGraphicsScene(this);
    //view = new QGraphicsView(this);
    //setGeometry(0,0,dim_x,dim_y);
    setWindowTitle("Alien Invasion: Last Hope");
    ui->graphicsView ->setGeometry(0,0,dim_x,dim_y);
    scene->setSceneRect(0,0,dim_x*10,dim_y);
    scene->setBackgroundBrush(QBrush(QImage(":/mapa/fondo1.jpeg")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(0,0);

    bloqTest = new bloque(0,0,90);
    scene->addItem(bloqTest);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generarMapa()
{

}

