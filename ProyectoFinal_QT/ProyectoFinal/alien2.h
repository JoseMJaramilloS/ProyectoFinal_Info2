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

public:
    //alien2();
    //alien2(int x, int y, int lado);
    explicit alien2(QObject *parent=nullptr);

    QTimer *timer;
    QPixmap *pixmap;
    //int posx=0,posy=0,tam=0;
    float filas, columnas,ancho,alto;
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

public slots:
    void Actualizar();
};

#endif // ALIEN2_H
