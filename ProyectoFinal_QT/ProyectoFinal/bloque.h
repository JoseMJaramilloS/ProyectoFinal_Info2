#ifndef BLOQUE_H
#define BLOQUE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class bloque : public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
public:
    bloque();
    bloque(int x, int y, int lado);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getPosy() const;
    int getPosx() const;
};

#endif // BLOQUE_H
