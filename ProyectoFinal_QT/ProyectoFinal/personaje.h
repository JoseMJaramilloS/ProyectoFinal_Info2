#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class personaje : public QObject, public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
    int vel=10;
    int vidas=3;
    int balas=0;
    int granadas=0;
    
public:
    personaje();
    personaje(int x, int y, int lado);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    
    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);
    int getVidas() const;
    void setVidas(int value);
    int getBalas() const;
    void setBalas(int value);
    int getGranadas() const;
    void setGranadas(int value);
    
    QTimer *timer;
    QPixmap *pixmap;
    float filIm,colIm;
};

#endif // PERSONAJE_H
