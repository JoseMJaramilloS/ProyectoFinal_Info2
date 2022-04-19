#include "desplegarinfo.h"

int desplegarInfo::getPosx() const
{
    return posx;
}

desplegarInfo::desplegarInfo()
{

}

desplegarInfo::desplegarInfo(int posx_, int posy_, QString texto_)
{
    posx=posx_;
    posy=posy_;
    alto=60;
    ancho=200;
    texto=texto_;
    setPos(posx,posy);
//    timer= new QTimer();
//    connect(timer,&QTimer::timeout,this,&desplegarInfo::actualizar);
//    timer->start(33);
}

QRectF desplegarInfo::boundingRect() const
{
    //return QRectF(posx,0-posy,ancho,alto);
    return QRectF(0,0,ancho,alto);
}

void desplegarInfo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QFont font=painter->font();
    font.setPointSize(30);
    painter->setFont(font);
    painter->setPen(Qt::black);
    //painter->setBrush(Qt::white);
    painter->drawText(boundingRect(),texto);
    //painter->drawRect(boundingRect());

}

void desplegarInfo::cambiarTexto(QString nuevoTexto)
{
    texto=nuevoTexto;
    update(boundingRect());
}

void desplegarInfo::actualizar()
{
    update(boundingRect());
}

void desplegarInfo::moverTexto(int x, int y)
{
    posx=x;
    posy=y;
    setPos(posx,posy);
}


