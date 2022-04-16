#ifndef VIDA_H
#define VIDA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <math.h>
#include <iostream>

class vida:public QObject, public QGraphicsPixmapItem
{
    float posx,posy,posx0,posy0;
    float dt=0;
    int lado;
    int signoAleatorio;

public slots:
    void Movimiento();


public:
    vida();
    vida(int x, int y, int lado);

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getPosx() const;
    int getPosy() const;

};
#endif // VIDA_H
