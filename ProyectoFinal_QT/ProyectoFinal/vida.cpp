#include "vida.h"

float vida::getPosx() const
{
    return posx;
}

float vida::getPosy() const
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
    signoAleatorio=pow(-1,1+rand()%2);
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
    //painter->drawRect(boundingRect());
}

void vida::Movimiento()
{

    if(dt>=2*M_PI) dt=0;
    posx = posx0 + 80*cos(dt);
    posy = posy0 + signoAleatorio*80*sin(dt); // signoAleatorio permite obtener un movimienteo horario o antihorario aleatoriamente
    dt+=0.1;
    //cout<<posy<<endl;
    setPos(posx,posy);

}
