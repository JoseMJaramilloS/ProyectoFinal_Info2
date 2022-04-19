#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>
#include <iostream>
#include "bloque.h"
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
    bool salto=false;
    bool caer=false;
    bool sentidoPersonaje=true; //true: DERECHA, false: IZQUIERDA
    int lado=90; //provisional
    int vidas=5;
    int balas=5;
    int granadas=0;    
    QTimer *timer;
    QPixmap *pixmap;

public slots:
    void gravedad();

public:
    personaje();
    personaje(QObject *parent=nullptr);
    personaje(int x, int y);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void MovDerecha();
    void MovIzquierda();
    void saltar(int vely0_);
    void caida();
    void sinCaida(int posyBloque);
    void fueraMapa();

    float filIm,colIm;
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
    bool getSalto() const;
    void setSalto(bool value);
    bool getCaer() const;
    void setCaer(bool value);
    bool getSentidoPersonaje() const;
    void setSentidoPersonaje(bool value);


};

#endif // PERSONAJE_H
