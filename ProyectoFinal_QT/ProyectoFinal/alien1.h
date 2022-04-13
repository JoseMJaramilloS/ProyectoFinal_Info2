#ifndef ALIEN1_H
#define ALIEN1_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <math.h>

class alien1: public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
    float a,w,u;//amplitud, vel angular, desfase
public:
    alien1();
    alien1(int x, int y, int lado, float a, float w, float u);

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void Movimiento();

    int getPosx() const;
    int getPosy() const;
};

#endif // ALIEN1_H
