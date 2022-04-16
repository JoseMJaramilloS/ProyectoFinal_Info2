#include "vida.h"

int vida::getPosx() const
{
    return posx;
}

int vida::getPosy() const
{
    return posy;
}

vida::vida()
{
    this->posx=50;
    this->posy=25;
    this->lado=80;
    setPos(posx,posy);

}

vida::vida(int x, int y, int lado)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    this->posx0=x;
    this->posy0=y;
    setPos(posx,posy);
}
QRectF vida::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void vida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/mapa/vida.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
void vida::MovimientoVida()
{

    for(int dt; dt<=500; dt++){
    posx =   80*cos(dt);
    posy =  80*sin(dt);
    }
    //cout<<posy<<endl;
    setPos(posx,posy);

}
