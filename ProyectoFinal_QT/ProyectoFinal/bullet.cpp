#include "bullet.h"

int bullet::getPosx() const
{
    return posx;
}

int bullet::getPosy() const
{
    return posy;
}

bullet::bullet()
{
    this->posx=50;
    this->posy=25;
    this->lado=25;
    this->vel=10;
    setPos(posx,posy);
}

bullet::bullet(int x, int y, int lado)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    this->vel=vel;
    setPos(posx,posy);
}

QRectF bullet::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/mapa/Bullet.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

void bullet::Movimiento()
{
    this->posx += vel;
    setPos(posx,posy);
}
