#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,bool cargarPartida_, QString usuarioGlobal_)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dim_x=1024;
    dim_y=720;
    scene = new QGraphicsScene(this);
    //setGeometry(0,0,dim_x,dim_y); // DESCOMENTAR al final
    setWindowTitle("Alien Invasion: Last Hope");
    ui->graphicsView ->setGeometry(0,0,dim_x,dim_y);
    scene->setSceneRect(0,0,dim_x*10,dim_y);
    scene->setBackgroundBrush(QBrush(QImage(":/mapa/fondo1.jpeg")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(0,0);

    // Generacion de mapa y carga de partida
    usuarioGlobal=usuarioGlobal_;
    cargarPartida=cargarPartida_;
    if (cargarPartida==false) {
        generarMapa();
        soldado= new personaje(0,720-90-90);
        scene->addItem(soldado);
    } else {

        cargarMapa();
    }

    timer= new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(movimientoAlien1()));
    connect(timer, SIGNAL(timeout()),this,SLOT(movimientoAlien2()));
    connect(timer, SIGNAL(timeout()),this,SLOT(movimientoVida()));
    connect(timer, SIGNAL(timeout()),this,SLOT(colisionBloques()));
    connect(timer, SIGNAL(timeout()),this,SLOT(colisionAliens()));
    connect(timer, SIGNAL(timeout()),this,SLOT(colisionBonificaciones()));
    connect(timer, SIGNAL(timeout()),this,SLOT(colisionBalas()));
    connect(timer, SIGNAL(timeout()),this,SLOT(efectoCaida()));
    connect(timer, SIGNAL(timeout()),this,SLOT(tiempoJuego()));
    timer->start(10);

//    soldado= new personaje(0,720-90-90);
//    scene->addItem(soldado);

    textoVidas= new desplegarInfo(10,24,"Vidas: "+ str.setNum(soldado->getVidas()));
    scene->addItem(textoVidas);
    textoBalas= new desplegarInfo(800,24,"Balas: "+ str.setNum(soldado->getBalas()));
    scene->addItem(textoBalas);    
    textoTiempo= new desplegarInfo(450,24,str.setNum(tiempo));
    scene->addItem(textoTiempo);

    pause = new pausa;
    connect(pause,SIGNAL(guardar()),this,SLOT(guardarJuego()));

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

void MainWindow::cargarMapa()
{
    QString user, password, Str_personaje, Str_aliens2, Str_vidas, Str_municion, Str_tiempo;
    cout<<"Cargando mapa"<<endl;

    //leer archivo
    QFile archivo(usuarioGlobal);
    if(archivo.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream read(&archivo);
        QString clave;
        user= read.readLine(); //usuario
        password = read.readLine();
        Str_personaje = read.readLine();
        Str_aliens2 = read.readLine();
        Str_vidas = read.readLine();
        Str_municion = read.readLine();
        Str_tiempo = read.readLine();
        archivo.close();
    }
    else {
        QMessageBox::information(this,"Cargar","Error al leer archivo");
    }

    // Reconstruyendo mapa
    QString x,y,vidasP,balasP;
    bool flag=false,cond;
    for (int i=0,j=0;i<=(dim_x*10);i+=90) {

        // Condicion para acantilados
        cond=!((90*6<=i && i<=90*7) || (90*23<=i && i<=90*24) || (90*36<=i && i<=90*37) || (90*51<=i && i<=90*52) || (90*81<=i && i<=90*82));
        if (cond) {
            // Generacion de suelo
            bloques.push_back(new bloque(i,720-90,90));
            scene->addItem(bloques.back());

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
    // Cargando personaje
    for (int i=0,j=1;i<Str_personaje.length();i++) {
        if (Str_personaje[i]==",") {
            j++;
        }
        else{
            switch (j) {
            case 1:
                x+=Str_personaje[i];
                break;
            case 2:
                y+=Str_personaje[i];
                break;
            case 3:
                vidasP+=Str_personaje[i];
                break;
            case 4:
                balasP+=Str_personaje[i];
                break;
            default:
                qDebug()<<"Error en carga de personaje"<<endl;
                break;
            }
        }
    }
    soldado= new personaje(x.toInt(),y.toInt());
    scene->addItem(soldado);
    ui->graphicsView->centerOn(soldado->getPosx(),0);
    soldado->setVidas(vidasP.toInt());
    soldado->setBalas(balasP.toInt());
    tiempo=Str_tiempo.toInt();
    qDebug()<<"Personaje cargado en "<<x<<","<<y<<","<<vidasP<<","<<balasP<<endl;

    // Cargando aliens2
    x="";y="";
    for (int i=0,j=1;i<Str_aliens2.length();i++) {
        if (Str_aliens2[i]==",") {
            if (j==2) {
                j=1;
                aliens2.push_back(new alien2(x.toInt(),y.toInt()));
                qDebug()<<"Alien2 cargado en "<<x<<","<<y<<endl;
                scene->addItem(aliens2.back());
                x="";y="";
            }
            else {
                j++;
            }
        }
        else{
            switch (j) {
            case 1:
                x+=Str_aliens2[i];
                break;
            case 2:
                y+=Str_aliens2[i];
                break;
            default:
                qDebug()<<"Error en carga de alien2"<<endl;
                break;
            }
        }
    }

    // Cargando vidas
    x="";y="";
    for (int i=0,j=1;i<Str_vidas.length();i++) {
        if (Str_vidas[i]==",") {
            if (j==2) {
                j=1;
                vidas.push_back(new vida(x.toInt(),y.toInt(),60));
                qDebug()<<"Vida cargada en "<<x<<","<<y<<endl;
                scene->addItem(vidas.back());
                x="";y="";
            }
            else {
                j++;
            }
        }
        else{
            switch (j) {
            case 1:
                x+=Str_vidas[i];
                break;
            case 2:
                y+=Str_vidas[i];
                break;
            default:
                qDebug()<<"Error en carga de vida"<<endl;
                break;
            }
        }
    }

    // Cargando municiones
    x="";y="";
    for (int i=0,j=1;i<Str_municion.length();i++) {
        if (Str_municion[i]==",") {
            if (j==2) {
                j=1;
                municiones.push_back(new municion(x.toInt(),y.toInt(),60));
                qDebug()<<"Municion cargada en "<<x<<","<<y<<endl;
                scene->addItem(municiones.back());
                x="";y="";
            }
            else {
                j++;
            }
        }
        else{
            switch (j) {
            case 1:
                x+=Str_municion[i];
                break;
            case 2:
                y+=Str_municion[i];
                break;
            default:
                qDebug()<<"Error en carga de municion"<<endl;
                break;
            }
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
    if (tiempoDanio==80) {// Divisor de frecuencia
        tiempoDanio=0;
        if (danio==true) {
            countDanio++;
            if (countDanio==2) { // Conteo de danio, para no bajar tantas vidas con un solo impacto de alien
                countDanio=0;
                danio=false;
            }
        }
        else{
            for (int i=0;i<aliens1.length();i++) {
                if (aliens1.at(i)->collidesWithItem(soldado)) { // Colision con aliens1
                    //cout<<"Colision con alien1"<<endl;
                    soldado->setVidas(soldado->getVidas()-1);
                    textoVidas->cambiarTexto("Vidas: "+ str.setNum(soldado->getVidas()));
                    cout<<"vidas-: "<<soldado->getVidas()<<endl;
                    danio=true;
                }
            }
            for (int i=0;i<aliens2.length();i++) {
                if (aliens2.at(i)->collidesWithItem(soldado)) { // Colision con aliens2
                    //cout<<"Colision con alien2"<<endl;
                    soldado->setVidas(soldado->getVidas()-1);
                    textoVidas->cambiarTexto("Vidas: "+ str.setNum(soldado->getVidas()));
                    cout<<"vidas-: "<<soldado->getVidas()<<endl;
                    danio= true;
                }
            }
            return false;
        }
    }
    return false;
}

void MainWindow::colisionBonificaciones()
{
    tiempoBonif++;
    if (tiempoBonif==1) {// Divisor de frecuencia
        for (iter_muni=municiones.begin(); iter_muni!=municiones.end(); iter_muni++) {
            if ((*iter_muni) -> collidesWithItem(soldado)) {
                //cout<<"Colision con municion"<<endl;
                soldado->setBalas(soldado->getBalas()+1);
                textoBalas->cambiarTexto("Balas: "+ str.setNum(soldado->getBalas()));
                cout<<"balas+: "<<soldado->getBalas()<<endl;
                scene->removeItem(*iter_muni);
                municiones.erase(iter_muni);
            }
        }
        for (iter_vidas2=vidas.begin(); iter_vidas2!=vidas.end(); iter_vidas2++) {
            if ((*iter_vidas2)->collidesWithItem(soldado)) {
                //cout<<"Colision con vida"<<endl;
                soldado->setVidas(soldado->getVidas()+1);
                textoVidas->cambiarTexto("Vidas: "+ str.setNum(soldado->getVidas()));
                cout<<"vidas+: "<<soldado->getVidas()<<endl;
                scene->removeItem(*iter_vidas2);
                vidas.erase(iter_vidas2);
            }
        }
        tiempoBonif=0;
    }
}

void MainWindow::colisionBalas()
{
    if (!bullets.empty()) { // Si no esta vacio       
        for (iter2_aliens2=aliens2.begin();iter2_aliens2!=aliens2.end();iter2_aliens2++) {
            for (iter_bullets=bullets.begin();iter_bullets!=bullets.end();iter_bullets++) {
                if ((*iter2_aliens2)->collidesWithItem(*iter_bullets)) { // Colision con aliens1
                    cout<<"Impacto de bala con alien2"<<endl;
                    (*iter_bullets)->impacto();
                    scene->removeItem(*iter2_aliens2);
                    aliens2.erase(iter2_aliens2);
                }
            }
        }

    }
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
        textoVidas->cambiarTexto("Vidas: "+ str.setNum(soldado->getVidas()));
        textoVidas->moverTexto(10,24); // Movimiento texto: VIDAS
        textoBalas->moverTexto(800,24); // Movimiento texto: BALAS
        textoTiempo->moverTexto(450,24);
        ui->graphicsView->centerOn(soldado->getPosx(),0);
        soldado->setSalto(false);
        soldado->setCaer(false);
        //cout<<"Fuera de mapa"<<endl;
    }

}

void MainWindow::tiempoJuego()
{
    tiempoGlobal++;
    if (tiempoGlobal==100) {
        tiempo--;
        textoTiempo->cambiarTexto(str.setNum(tiempo));
        tiempoGlobal=0;
    }
}

void MainWindow::guardarJuego()
{
    QString user, password, Str_personaje, Str_aliens2, Str_vidas, Str_municion, Str_tiempo;
    cout<<"si"<<endl;

    //leer archivo
    QFile archivo(usuarioGlobal);
    if(archivo.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream read(&archivo);
        QString clave;
        user= read.readLine(); //usuario
        password = read.readLine();
        archivo.close();
    }
    else {
        QMessageBox::information(this,"Guardar","Error al leer archivo");
    }

    // Se obtienen los valores de la escena
    Str_personaje=QString::number(soldado->getPosx())+","+QString::number(soldado->getPosy())+","+QString::number(soldado->getVidas())+","+QString::number(soldado->getBalas());
    for (int i=0;i<aliens2.length();i++) {
        Str_aliens2+=QString::number(aliens2.at(i)->getPosx0())+",";
        Str_aliens2+=QString::number(aliens2.at(i)->getPosy0())+",";
    }
    for (int i=0;i<vidas.length();i++) {
        Str_vidas+=QString::number(vidas.at(i)->getPosx0())+",";
        Str_vidas+=QString::number(vidas.at(i)->getPosy0())+",";
    }
    for (int i=0;i<municiones.length();i++) {
        Str_municion+=QString::number(municiones.at(i)->getPosx0())+",";
        Str_municion+=QString::number(municiones.at(i)->getPosy0())+",";
    }

    Str_tiempo=QString::number(tiempo);
    qDebug()<<Str_personaje<<endl;
    qDebug()<<Str_aliens2<<endl;
    qDebug()<<Str_vidas<<endl;
    qDebug()<<Str_municion<<endl;
    qDebug()<<Str_tiempo<<endl;

    // Escribir archivo
    QFile cuenta(user);
    if ( cuenta.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"Guardar","Partida guardada exitosamente.");
        QTextStream out(&cuenta);
        out << user<<endl;
        out << password<<endl;
        out <<Str_personaje<< endl; // x,y,vidas,balas
        out <<Str_aliens2<<endl;
        out <<Str_vidas<<endl; // vidas
        out <<Str_municion<<endl; // balas
        out <<Str_tiempo<<endl;
        cuenta.close();
    }
    else
    {
        QMessageBox::information(this,"Guardar","Error al guardar la partida.");
    }

}

void MainWindow::setCargarPartida(bool value)
{
    cargarPartida = value;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    switch (evento->key()) {
    case Qt::Key_D:{
        soldado->MovDerecha();
        ui->graphicsView->centerOn(soldado->getPosx(),0);
        if (soldado->getPosx()>dim_x/2 && soldado->getPosx()<dim_x*10-dim_x/2) {
            textoVidas->moverTexto(textoVidas->getPosx()+10,24); // Movimiento texto: VIDAS
            textoBalas->moverTexto(textoBalas->getPosx()+10,24); // Movimiento texto: BALAS
            textoTiempo->moverTexto(textoTiempo->getPosx()+10,24);
        }
        break;
    }
    case Qt::Key_A:{
        soldado->MovIzquierda();
        ui->graphicsView->centerOn(soldado->getPosx(),0);
        if (soldado->getPosx()>dim_x/2 && soldado->getPosx()<dim_x*10-dim_x/2) {
            textoVidas->moverTexto(textoVidas->getPosx()-10,24); // Movimiento texto: VIDAS
            textoBalas->moverTexto(textoBalas->getPosx()-10,24); // Movimiento texto: BALAS
            textoTiempo->moverTexto(textoTiempo->getPosx()-10,24);
        }
        break;
    }
    case Qt::Key_W:{
        if (soldado->getPosy()>360) soldado->saltar(8); // Salta diferente si esta en plataforma o en el piso
        else soldado->saltar(6);
        ui->graphicsView->centerOn(soldado->getPosx(),0);
        break;
    }
    case Qt::Key_I:{
        //disparar
        if(soldado->getBalas()>0){ // Si tiene balas
            if (soldado->getSentidoPersonaje()==true) { // disparo a la derecha
                bullets.push_back(new bullet(soldado->getPosx()+90,soldado->getPosy()+50,true,scene,bullets));
                scene->addItem(bullets.back()); 

            }
            else if (soldado->getSentidoPersonaje()==false) { // disparo a la izquierda
                bullets.push_back(new bullet(soldado->getPosx(),soldado->getPosy()+50,false,scene,bullets));
                scene->addItem(bullets.back());
            }
            soldado->setBalas(soldado->getBalas()-1); // Se resta una bala
            textoBalas->cambiarTexto("Balas: "+ str.setNum(soldado->getBalas()));
            cout<<"balas-: "<<soldado->getBalas()<<endl;

        }
        break;
    }
    case Qt::Key_O:{
        //lanzar granada
        break;
    }
    case Qt::Key_P:{
        //pausa
        if (pauseActive==false) {
            pause->show();
            timer->stop();
            pauseActive=true;
            soldado->personajePausa(pauseActive);
        }
        else {
            timer->start(10);
            pause->close();
            pauseActive=false;
            soldado->personajePausa(pauseActive);
        }
        break;
    }
    default:

        break;

    }
}

QString MainWindow::getUsuarioGlobal() const
{
    return usuarioGlobal;
}

void MainWindow::setUsuarioGlobal(const QString &value)
{
    usuarioGlobal = value;
}
