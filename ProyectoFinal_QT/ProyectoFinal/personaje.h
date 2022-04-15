#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>
#include <iostream>
using namespace std;

class personaje : public QObject, public QGraphicsItem
{
    float posx;
    float posy;
    float velx=10;
    float vely;
    float vely0=0;
    float dt=0; //tamanio de paso para movimiento parabolico
    float g=9.81; //gravedad
    bool moveInY;
    int lado=90; //provisional
    int vidas=3;
    int balas=0;
    int granadas=0;

public:
    personaje();
    personaje(QObject *parent=nullptr);
    personaje(int x, int y);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void MovDerecha();
    void MovIzquierda();
    void gravedad();
    void saltar();

    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);
    void setVely(float value);
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
