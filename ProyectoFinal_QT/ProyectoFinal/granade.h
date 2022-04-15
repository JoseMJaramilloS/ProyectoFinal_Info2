#ifndef GRANADE_H
#define GRANADE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class granade: public QGraphicsItem
{    
    int posx, posy;
    int lado;
    float dt=0.5;
    float velx, vely;
    float ax, ay;

public slots:
    void Movimiento();


public:
    granade();
    granade(int x, int y, int lado);

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getPosx() const;
    int getPosy() const;

};

#endif // GRANADE_H
