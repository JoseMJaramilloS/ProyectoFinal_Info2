#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class bullet : public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
    int vel;
public:
    bullet();
    bullet(int x, int y, int lado, int vel);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void Movimiento();

    int getPosx() const;
    int getPosy() const;
};

#endif // BULLET_H