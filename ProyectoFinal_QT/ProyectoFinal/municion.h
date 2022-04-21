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
    int posx0;
    int posy0;
public:
    municion();
    municion(int x, int y, int lado);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getPosx0() const;
    int getPosy0() const;
};

#endif // MUNICION_H
