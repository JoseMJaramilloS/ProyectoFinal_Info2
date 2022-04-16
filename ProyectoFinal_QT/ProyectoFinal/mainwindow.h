#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QDebug>
#include <QTimer>
#include <cstdlib> //Para generacion de numeros aleatorios
#include <QKeyEvent>
#include "bloque.h"
#include "alien1.h"
#include "alien2.h"
#include "vida.h"
#include "personaje.h"
#include "municion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void generarMapa();


public slots:
    void movimientoAlien1();
    void movimientoAlien2();
    void MovVida();
    bool colisionBloques();
    void efectoCaida();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    int dim_x=0, dim_y=0;
    QList <bloque*>bloques;
    QList <bloque*>::Iterator iter_bloq;
    QList <alien1*>aliens1;
    QList <alien1*>::Iterator iter_aliens1;
    QList <alien2*>aliens2;
    QList <alien2*>::Iterator iter_aliens2;
    personaje *soldado;
    QList <municion*>municiones;
    QList <municion*>::Iterator iter_muni;
    vida *vidas;
    //municion *muni;
    QTimer *timer;
    int tiempoAlien2=0, mov=0; // Para el movimiento de alien2
    bool sentidoAlien2=true; // Para el movimiento de alien2
    void keyPressEvent(QKeyEvent *evento);
    bloque *bloqueColisionado,*bloquePrueba;
    bool flag=false; //test
};
#endif // MAINWINDOW_H
