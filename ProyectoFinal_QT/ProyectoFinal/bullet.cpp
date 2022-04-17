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
    this->posx=0;
    this->posy=0;
    this->lado=25;
    this->vel=10;
    setPos(posx,posy);
}

bullet::bullet(int x, int y, bool sentido, QGraphicsScene *scene_, QList <bullet*> bullets_)
{
    this->posx=x;
    this->posy=y;
    this->sentidoBala=sentido;
    this->scene=scene_;
    this->bullets=bullets_;
    setPos(posx,posy);
    balaActiva=true;
    if (sentidoBala==false) {
        vel=-vel;
    }
    timer = new QTimer;
    connect(timer,&QTimer::timeout,this,&bullet::Movimiento);
    timer->start(10);


}

QRectF bullet::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/personaje/Bullet.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

bool bullet::getBalaActiva() const
{
    return balaActiva;
}

void bullet::setBalaActiva(bool value)
{
    balaActiva = value;
}

void bullet::Movimiento()
{
    this->posx += vel;
    dist+=abs(vel);
    setPos(posx,posy);
    if (dist>=400) { // Si no hay impacto y se cumple distancia maxima
        timer->stop();
        dist=0;
        balaActiva=false;
        scene->removeItem(this);
        bullets.removeOne(this);
    }
}
