#ifndef ALIEN2_H
#define ALIEN2_H
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
using namespace std;

class alien2: public QObject, public QGraphicsItem
{
    int posx=0;
    int posy=0;
    int posx0;
    int posy0;
    int vel=1;

public:
    alien2(int x, int y);
    alien2(QObject *parent=nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas, ancho, alto;
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void MovDerecha();
    void MovIzquierda();
    float getX() const;
    void setX(float value);
    bool getMov() const;
    void setMov(bool value);
    float getY() const;
    void setY(float value);

    int getPosx0() const;
    int getPosy0() const;

public slots:
    void Actualizar();
};

#endif // ALIEN2_H
