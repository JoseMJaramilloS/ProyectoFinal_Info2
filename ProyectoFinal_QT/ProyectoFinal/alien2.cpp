#include "alien2.h"

alien2::alien2(QObject *parent) : QObject(parent)//alien2(int x, int y, int lado)
{
//    posx=x;
//    posy=y;
//    tam=lado;
    filas=0;
    columnas=0;
    alto=726;
    ancho=452;
    pixmap = new QPixmap(":/alien/alienRight.png");
    timer = new QTimer();
    timer->start(250);

    connect(timer,&QTimer::timeout,this,&alien2::Actualizar);
}
void alien2::Actualizar()
{
    columnas+=452;
    if(columnas>=1356)
        columnas=0;
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF alien2::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void alien2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}
