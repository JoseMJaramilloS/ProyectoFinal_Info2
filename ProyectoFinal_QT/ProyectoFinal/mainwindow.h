#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QDebug>
#include <QTimer>
#include "bloque.h"
#include "alien1.h"
#include "alien2.h"
#include <cstdlib> //Para generacion de numeros aleatorios

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
    void movimientoAlien();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    int dim_x=0, dim_y=0;
    QList <bloque*>bloques;
    QList <bloque*>::Iterator iter_bloq;
    QList <alien1*>aliens1;
    QList <alien1*>::Iterator iter_aliens1;
    bloque *bloqTest;
    QTimer *timer;
    alien2 *enemy2;

};
#endif // MAINWINDOW_H
