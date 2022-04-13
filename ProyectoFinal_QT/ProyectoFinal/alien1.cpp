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
    this->lado=25;
    this->a=100;
    this->w=0.2;
    this->u=3.1416;
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
    return QRectF(0,0,25,25);
}

void alien1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/mapa/Drakir6.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
void alien1::Movimiento()
{
    for(float i=0; i<200; i++){
        posx=a*sin(w*i+u);
    }
    setPos(posx,posy);
}
