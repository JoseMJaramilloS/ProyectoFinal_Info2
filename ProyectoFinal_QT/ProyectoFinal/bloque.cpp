#include "bloque.h"

int bloque::getPosy() const
{
    return posy;
}

int bloque::getPosx() const
{
    return posx;
}

bloque::bloque()
{
    
}

bloque::bloque(int x, int y, int lado)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    setPos(posx,posy);
}

QRectF bloque::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void bloque::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/mapa/floor.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
