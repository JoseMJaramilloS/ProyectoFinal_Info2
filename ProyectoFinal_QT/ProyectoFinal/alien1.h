#ifndef ALIEN1_H
#define ALIEN1_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <math.h>
#include <iostream>
using namespace std;

class alien1: public QGraphicsItem
{
    int posx;
    int posy;
    int posy0;
    int lado;
    float dt=0.00001;
    float a,w,u;//amplitud, vel angular, desfase

public slots:
    void Movimiento();

public:
    alien1();
    alien1(int x, int y, int lado, float a, float w, float u);

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getPosx() const;
    int getPosy() const;
};

#endif // ALIEN1_H
