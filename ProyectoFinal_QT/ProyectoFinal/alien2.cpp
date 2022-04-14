#include "alien2.h"
alien2::alien2(int x, int y)
{
        posx=x;
        posy=y;
        setPos(x,y);

        filas=0;
        columnas=0;
        alto=120;
        ancho=80;
        pixmap = new QPixmap(":/alien/alienRight.png");

        timer = new QTimer();
        timer->start(250);
        connect(timer,&QTimer::timeout,this,&alien2::Actualizar);

}

alien2::alien2(QObject *parent) : QObject(parent)
{
    filas=0;
    columnas=0;
    alto=120;
    ancho=80;
    pixmap = new QPixmap(":/alien/alienRight.png");

    timer = new QTimer();
    timer->start(250);
    connect(timer,&QTimer::timeout,this,&alien2::Actualizar);
}
void alien2::Actualizar()
{
    columnas+=80;
    if(columnas>=222)
        columnas=0;
    //this->update(-ancho/2,-alto/2,ancho,alto);
    this->update(0,0,ancho,alto);
}


QRectF alien2::boundingRect() const
{

    //return QRectF(-ancho/2*f,-alto/2*f,ancho*f,alto*f);
    return QRectF(0,0,ancho,alto);
}

void alien2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawPixmap(-ancho/2*f,-alto/2*f,*pixmap,columnas*f,0,ancho*f,alto*f);
    painter->drawPixmap(0,0,*pixmap,columnas,0,ancho,alto);
}

void alien2::MovDerecha()
{
    posx += vel;
    setPos(posx, posy);
    pixmap->load(":/alien/alienRight.png");
}

void alien2::MovIzquierda()
{
    posx -= vel;
    setPos(posx, posy);
    pixmap->load(":/alien/alienLeft.png");
}
