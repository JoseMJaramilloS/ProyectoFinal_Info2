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
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include "bloque.h"
#include "alien1.h"
#include "alien2.h"
#include "vida.h"
#include "personaje.h"
#include "municion.h"
#include "bullet.h"
#include "desplegarinfo.h"
#include "pausa.h"

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
    void guardarArchivo();
    QString getUsuarioGlobal() const;
    void setUsuarioGlobal(const QString &value);

public slots:
    void movimientoAlien1();
    void movimientoAlien2();
    void movimientoVida();
    bool colisionBloques();
    bool colisionAliens();
    void colisionBonificaciones();
    void colisionBalas();
    void efectoCaida();
    void tiempoJuego();
    void guardarJuego();

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
    QList <alien2*>::Iterator iter_aliens2; // Movimiento
    QList <alien2*>::Iterator iter2_aliens2; // Colisiones
    QList <municion*>municiones;
    QList <municion*>::Iterator iter_muni;
    QList <vida*>vidas;
    QList <vida*>::Iterator iter_vidas;
    QList <vida*>::Iterator iter_vidas2; // Porque no se puede usar el mismo iterador al tiempo
    QList <bullet*>bullets;
    QList <bullet*>::Iterator iter_bullets;
    personaje *soldado;
    QTimer *timer;
    int tiempoAlien2=0, tiempoVidas=0, tiempoDanio=0,tiempoBonif=0, tiempoGlobal=0, tiempo=300; // Contadores de reloj
    int countDanio=0; // Para reducir vida del personaje
    bool danio=false; // Para reducir vida del personaje
    int mov=0; // Para el movimiento de alien2
    bool sentidoAlien2=true; // Para el movimiento de alien2
    bool pauseActive=false;
    void keyPressEvent(QKeyEvent *evento);
    bloque *bloqueColisionado;
    QString str,str2;
    desplegarInfo *textoVidas;
    desplegarInfo *textoBalas;
    desplegarInfo *textoTiempo;
    pausa *pause;
    QString usuarioGlobal;

};
#endif // MAINWINDOW_H
