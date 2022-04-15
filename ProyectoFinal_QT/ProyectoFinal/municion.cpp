#include "municion.h"

municion::municion()
{
//    this->posx=50;
//    this->posy=25;
//    this->lado=60;
//    setPos(posx,posy);
}

municion::municion(int x, int y, int lado)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    setPos(posx,posy);
}

QRectF municion::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void municion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/mapa/Ammo.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
