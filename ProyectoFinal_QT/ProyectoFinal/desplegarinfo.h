#ifndef DESPLEGARINFO_H
#define DESPLEGARINFO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QObject>

class desplegarInfo : public QObject, public QGraphicsItem
{
    int posx;
    int posy;
    int alto;
    int ancho;
    QString texto;
    QPainter painter;
    QTimer *timer;
public:
    desplegarInfo();
    desplegarInfo(int posx_, int posy_, QString texto);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void cambiarTexto(QString nuevoTexto);
    void actualizar();
    void moverTexto(int x, int y);
    int getPosx() const;
};

#endif // DESPLEGARINFO_H
