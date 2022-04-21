#ifndef INICIO_H
#define INICIO_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <mainwindow.h>

namespace Ui {
class inicio;
}

class inicio : public QDialog
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();

    QString getUser() const;
    QString getPassword() const;

private slots:
    void on_btnRegistrar_clicked();
    void on_btnIngresar_clicked();
    void on_btnNuevaPartida_clicked();
    void on_btnCargarPartida_clicked();

private:
    Ui::inicio *ui;
    MainWindow *game;
    QString user;
    QString password;
    QString personaje;
    QString aliens2;
    QString vidas;
    QString municion;

};

#endif // INICIO_H
