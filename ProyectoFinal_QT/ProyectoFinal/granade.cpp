#include "granade.h"

int granade::getPosx() const
{
    return posx;
}

int granade::getPosy() const
{
    return posy;
}
granade::granade()
{
    this->posx=50;
    this->posy=25;
    this->lado=25;
    setPos(posx,posy);

}
granade::granade(int x, int y, int lado)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    setPos(posx,posy);
}

QRectF granade::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void granade::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/personaje/hand_grenade_01.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

void granade::Movimiento()
{
    velx=velx+ax*dt;
    posx=posx+velx*dt+(ax*dt*dt)/2;
    vely=vely+ay*dt;
    posy=posy+vely*dt+(ay*dt*dt)/2;
    setPos(posx,posy);
}

