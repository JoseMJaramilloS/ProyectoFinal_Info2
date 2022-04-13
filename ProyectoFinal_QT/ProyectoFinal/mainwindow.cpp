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
    generarMapa();

    timer= new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(movimientoAlien()));
    timer->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generarMapa()
{
    bool flag=false;
    for (int i=0,j=0;i<=(dim_x*10);i+=90) {

        // Generacion de suelo
        if (!((90*6<=i && i<=90*7) || (90*23<=i && i<=90*24) || (90*36<=i && i<=90*37) || (90*51<=i && i<=90*52) || (90*81<=i && i<=90*82))) {
            bloques.push_back(new bloque(i,720-90,90));
            scene->addItem(bloques.back());
        }
        else {

            // Generacion de aliens1
            aliens1.push_back(new alien1(i,360,90,300,0.01,M_PI/2*(rand()%2)));
            scene->addItem(aliens1.back());



        }
        // Plataformas
        if(rand()%5==1){
            flag=true;
            j=0;
        }
        if(flag && j<2 && i!=0){
            bloques.push_back(new bloque(i,720-90*4,90));
            scene->addItem(bloques.back());
            j++;
        }


    }

}

void MainWindow::movimientoAlien()
{
    for (iter_aliens1=aliens1.begin();iter_aliens1!=aliens1.end();iter_aliens1++) {
        (*iter_aliens1)->Movimiento();
    }
}

