#ifndef INICIO_H
#define INICIO_H

#include <QDialog>
#include <QFile>
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

private slots:
    void on_btnRegistrar_clicked();
    void on_btnIngresar_clicked();
    void on_btnNuevaPartida_clicked();
    void on_btnCargarPartida_clicked();

private:
    Ui::inicio *ui;
    QString user;
    QString password;
    MainWindow *game;
};

#endif // INICIO_H
