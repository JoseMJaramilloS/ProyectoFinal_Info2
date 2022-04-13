#include "alien1.h"

int alien1::getPosx() const
{
    return posx;
}

int alien1::getPosy() const
{
    return posy;
}

alien1::alien1()
{
    this->posx=50;
    this->posy=25;
    this->lado=90;
    this->a=200;
    this->w=0.2;
    this->u=0;
    setPos(posx,posy);

}
alien1::alien1(int x, int y, int lado, float a, float w, float u)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    this->a=a;
    this->w=w;
    this->u=u;
    setPos(posx,posy);
}
QRectF alien1::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void alien1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/mapa/Drakir6.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
void alien1::Movimiento()
{
    dt++;
    if(dt==5*M_PI) dt=0;
    posy = a*pow(sin(w*dt+u),2);
    cout<<posy<<endl;
    setPos(posx,posy);

}
