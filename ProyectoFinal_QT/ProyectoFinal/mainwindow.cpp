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
    connect(timer, SIGNAL(timeout()),this,SLOT(colisionBloques()));
    connect(timer, SIGNAL(timeout()),this,SLOT(colisionAliens()));
    connect(timer, SIGNAL(timeout()),this,SLOT(efectoCaida()));
    connect(timer, SIGNAL(timeout()),this,SLOT(movimientoVida()));
    timer->start(10);

    soldado= new personaje(0,720-90-90);
    scene->addItem(soldado);

    //vidas = new vida(100,0,90);
    //scene->addItem(vidas);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generarMapa()
{
    int ultimaAmmo=0,ultimaVida=0;
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
            if(rand()%10==1 && i>(90*7)){
                municiones.push_back(new municion(i,301,60));
                scene->addItem(municiones.back());
            }
            j++;
        }

        if(rand()%9==1 && i>(90*7) && (i-ultimaAmmo)>=400){
            // Generacion de municion
            ultimaAmmo=i;
            municiones.push_back(new municion(i,571,60));
            scene->addItem(municiones.back());
        }

        if(rand()%9==1 && i>(90*7) && (i-ultimaVida)>=500){
            // Generacion de vidas
            //cout<<"se crea vida en "<<i<<endl;
            ultimaVida=i;
            vidas.push_back(new vida(i,200,60));
            scene->addItem(vidas.back());
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
    if(tiempoAlien2==2){ // Se puede controlar la velocidad de movimiento
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

void MainWindow::movimientoVida()
{
    tiempoVidas++;
    if (tiempoVidas==2) { // Se puede controlar la velocidad de movimiento
        for (iter_vidas=vidas.begin();iter_vidas!=vidas.end();iter_vidas++) {
            (*iter_vidas)->Movimiento();
        }
        tiempoVidas=0;
    }

}

bool MainWindow::colisionBloques()
{
    for (int i=0;i<bloques.length();i++) {
        if (bloques.at(i)->collidesWithItem(soldado)) {
            //cout<<"Colision"<<endl;
            bloqueColisionado=bloques.at(i);
            return true;
        }
    }
    return false;
}

bool MainWindow::colisionAliens()
{
    tiempoDanio++;
    if (tiempoDanio==80) {// Divisor de reloj
        tiempoDanio=0;
        if (danio==true) {
            countDanio++;
            if (countDanio==3) { // Conteo de danio, para no bajar tantas vidas con un solo impacto de alien
                countDanio=0;
                danio=false;
            }
        }
        else{
            for (int i=0;i<aliens1.length();i++) {
                if (aliens1.at(i)->collidesWithItem(soldado)) { // Colision con aliens1
                    cout<<"Colision con alien1"<<endl;
                    soldado->setVidas(soldado->getVidas()-1);
                    cout<<"vidas: "<<soldado->getVidas()<<endl;
                    danio=true;
                }
            }
            for (int i=0;i<aliens2.length();i++) {
                if (aliens2.at(i)->collidesWithItem(soldado)) { // Colision con aliens2
                    cout<<"Colision con alien2"<<endl;
                    soldado->setVidas(soldado->getVidas()-1);
                    cout<<"vidas: "<<soldado->getVidas()<<endl;
                    danio= true;
                }
            }
            return false;
        }
    }
    return false;
}

void MainWindow::efectoCaida()
{

    //cout<<"x: "<<int(soldado->getPosx())<<" y: "<<int(soldado->getPosy())<<endl;

    if(!colisionBloques() && !(soldado->getSalto()) && !(soldado->getCaer())){//colision: FALSE, salto: FALSE, caer: FALSE;
        soldado->caida();
        soldado->setCaer(true);
        //cout<<"Cae"<<endl;
    }
    else if (colisionBloques() && !(soldado->getSalto())) { //colision: TRUE, salto: FALSE
        soldado->sinCaida(bloqueColisionado->getPosy());
        soldado->setCaer(false);
        //cout<<"No Cae1"<<endl;
    }
    else if (colisionBloques() && soldado->getSalto()) { //colision: TRUE, salto: TRUE
        soldado->sinCaida(bloqueColisionado->getPosy());
        soldado->setSalto(false);
        soldado->setCaer(false);
        //cout<<"No Cae2"<<endl;
    }
    else if (!colisionBloques() && soldado->getPosy()>720) { //colision: FALSE, fuera de mapa
        soldado->fueraMapa();
        ui->graphicsView->centerOn(soldado->getPosx(),0);
        soldado->setSalto(false);
        soldado->setCaer(false);
    }

}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    switch (evento->key()) {
    case Qt::Key_D:{
        soldado->MovDerecha();
        ui->graphicsView->centerOn(soldado->getPosx(),0);
        break;
    }
    case Qt::Key_A:{
        soldado->MovIzquierda();
        ui->graphicsView->centerOn(soldado->getPosx(),0);
        break;
    }
    case Qt::Key_W:{
        soldado->saltar();
        ui->graphicsView->centerOn(soldado->getPosx(),0);
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
