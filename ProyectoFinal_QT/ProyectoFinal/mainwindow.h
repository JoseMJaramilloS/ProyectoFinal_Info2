#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "bloque.h"
#include "alien1.h"
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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    int dim_x=0, dim_y=0;
    QList <bloque*>bloques;
    alien1 *enemy1;
    QList <bloque*>::Iterator iter;
    bloque *bloqTest;

};
#endif // MAINWINDOW_H
