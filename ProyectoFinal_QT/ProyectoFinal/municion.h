#ifndef MUNICION_H
#define MUNICION_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class municion : public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
public:
    municion();
    municion(int x, int y, int lado);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // MUNICION_H
