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

void personaje::setVely(float value)
{
    vely = value;
}

personaje::personaje()
{

}

personaje::personaje(int x, int y)
{
    this->posx=x;
    this->posy=y;
    setPos(x,y);

    timer = new QTimer;
    connect(timer,&QTimer::timeout,this,&personaje::gravedad);
}

QRectF personaje::boundingRect() const
{
    return QRectF(0,0,lado,lado); // Provisional
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/personaje/Idle_000.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

void personaje::MovDerecha()
{
    posx+=velx;
    setPos(posx,posy);
}

void personaje::MovIzquierda()
{
    posx-=velx;
    setPos(posx,posy);
}

void personaje::gravedad()
{
    dt+=0.01;
    vely = -(vely0-g*dt);
    posy += -(vely0*dt - 0.5*g*pow(dt,2)); // el SR esta invertido rpcto al eje y
    setPos(posx,posy);
    cout<<"vely: "<<vely<<" posy: "<<posy<<" "<<0.5*g*pow(dt,2)<<endl;

    if(posy>720-90-90) { // Restriccion del piso (temporal)
        dt=0;
        timer->stop();
        posy=720-90-90;
        setPos(posx,posy);
    }

}

void personaje::saltar()
{
    vely0=8;
    timer->start(10);

}
