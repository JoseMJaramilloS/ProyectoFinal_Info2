#include "personaje.h"

int personaje::getPosx() const
{
    return posx;
}

void personaje::setPosx(int value)
{
    posx = value;
}

int personaje::getPosy() const
{
    return posy;
}

void personaje::setPosy(int value)
{
    posy = value;
}

int personaje::getVidas() const
{
    return vidas;
}

void personaje::setVidas(int value)
{
    vidas = value;
}

int personaje::getBalas() const
{
    return balas;
}

void personaje::setBalas(int value)
{
    balas = value;
}

int personaje::getGranadas() const
{
    return granadas;
}

void personaje::setGranadas(int value)
{
    granadas = value;
}

bool personaje::getSalto() const
{
    return salto;
}

void personaje::setSalto(bool value)
{
    salto = value;
}

bool personaje::getCaer() const
{
    return caer;
}

void personaje::setCaer(bool value)
{
    caer = value;
}

bool personaje::getSentidoPersonaje() const
{
    return sentidoPersonaje;
}

void personaje::setSentidoPersonaje(bool value)
{
    sentidoPersonaje = value;
}

personaje::personaje()
{

}

personaje::personaje(int x, int y)
{
    this->posx=x;
    this->posy=y;
    setPos(x,y);
    pixmap= new QPixmap(":/personaje/Idle_000.png");

    timer = new QTimer;
    connect(timer,&QTimer::timeout,this,&personaje::gravedad);
}

QRectF personaje::boundingRect() const
{
    return QRectF(0,0,lado,lado); // Provisional
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect());
}

void personaje::MovDerecha()
{
    posx+=velx;
    setPos(posx,posy);
    pixmap->load(":/personaje/Idle_000.png");
    sentidoPersonaje=true;
}

void personaje::MovIzquierda()
{
    posx-=velx;
    setPos(posx,posy);
    pixmap->load(":/personaje/Idle_000_Left.png");
    sentidoPersonaje=false;
}

void personaje::gravedad()
{
    dt+=0.01;
    vely = -(vely0-g*dt);
    posy += -(vely0*dt - 0.5*g*pow(dt,2)); // el SR esta invertido rpcto al eje y
    setPos(posx,posy);
    //cout<<"vely0: "<<vely0<<" vely: "<<vely<<" posy: "<<posy<<endl;

}

void personaje::saltar(int vely0_)
{
    vely0=vely0_;
    timer->start(10);
    salto=true;

}

void personaje::caida()
{
    vely0=0;
    timer->start(10);
}

void personaje::sinCaida(int posyBloque)
{
    if(posy+90<=posyBloque+20){
        timer->stop();
        dt=0;
        vely0=0;
        posy=posyBloque-90;
        setPos(posx,posy);
    }
}

void personaje::fueraMapa()
{
    vidas--;
    timer->stop();
    dt=0;
    vely0=0;
    vely=0;
    posx=0;
    posy=720-90-90;
    setPos(posx,posy);
}

void personaje::personajePausa(bool pauseActive)
{
    if (pauseActive) {
        timer->stop();
    }
    else timer->start(10);
}



