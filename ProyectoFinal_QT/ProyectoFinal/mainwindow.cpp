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
    connect(timer, SIGNAL(timeout()),this,SLOT(movimientoAlien1()));
    connect(timer, SIGNAL(timeout()),this,SLOT(movimientoAlien2()));
    timer->start(10);

    soldado= new personaje(0,720-90-90);
    scene->addItem(soldado);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generarMapa()
{
    bool flag=false,cond;
    for (int i=0,j=0;i<=(dim_x*10);i+=90) {

        // Condicion para acantilados
        cond=!((90*6<=i && i<=90*7) || (90*23<=i && i<=90*24) || (90*36<=i && i<=90*37) || (90*51<=i && i<=90*52) || (90*81<=i && i<=90*82));
        if (cond) {
            // Generacion de suelo
            bloques.push_back(new bloque(i,720-90,90));
            scene->addItem(bloques.back());

            // Generacion de aliens2
            if(rand()%10==1 && i>(90*7)){
                aliens2.push_back(new alien2(i,720-90-120));
                scene->addItem(aliens2.back());
            }
        }
        else {
            // Generacion de aliens1
            aliens1.push_back(new alien1(i,360,90,300,0.01,M_PI/2*(rand()%6)));
            scene->addItem(aliens1.back());
        }
        // Plataformas
        if(rand()%5==1){
            flag=true;
            j=0;
        }
        if(flag && j<2 && i!=0 && cond){
            bloques.push_back(new bloque(i,720-90*4,90));
            scene->addItem(bloques.back());
            j++;
        }

    }
}

void MainWindow::movimientoAlien1()
{
    for (iter_aliens1=aliens1.begin();iter_aliens1!=aliens1.end();iter_aliens1++) {
        (*iter_aliens1)->Movimiento();
    }
}

void MainWindow::movimientoAlien2()
{
    int dist=5000;
    tiempoAlien2++;
    if(tiempoAlien2==2){ // Se puede controlar la velocidad de moviemiento
        for (iter_aliens2=aliens2.begin();iter_aliens2!=aliens2.end();iter_aliens2++) {
            if (mov<dist && sentidoAlien2==true) {
                (*iter_aliens2)->MovDerecha();
                mov++;
                if(mov==dist){
                    mov=0;
                    sentidoAlien2=false;
                }
            }
            else if(mov<dist && sentidoAlien2==false) {
                (*iter_aliens2)->MovIzquierda();
                mov++;
                if(mov==dist){
                    mov=0;
                    sentidoAlien2=true;
                }
            }

        }
        tiempoAlien2=0;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    switch (evento->key()) {
    case Qt::Key_D:{
        soldado->MovDerecha();
        break;
    }
    case Qt::Key_A:{
        soldado->MovIzquierda();
        break;
    }
    case Qt::Key_W:{
        soldado->saltar();
        break;
    }
    case Qt::Key_I:{
        //disparar
        break;
    }
    case Qt::Key_O:{
        //lanzar granada
        break;
    }
    default:

        break;

    }
}
