#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

class bullet : public QObject, public QGraphicsItem
{
    int posx;
    int posy;
    int lado=15;
    int vel=10;
    int dist=0; // Distancia que recorre la bala
    bool sentidoBala=true;
    bool balaActiva=false;
    QTimer *timer;
    QGraphicsScene *scene; // Para quitar la bala de la escena y de la lista
    QList <bullet*> bullets;

public slots:
    void Movimiento();

public:
    bullet();
    bullet(int x, int y, bool sentido, QGraphicsScene *scene_, QList <bullet*> bullets_);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getPosx() const;
    int getPosy() const;
    bool getBalaActiva() const;
    void setBalaActiva(bool value);
};

#endif // BULLET_H
