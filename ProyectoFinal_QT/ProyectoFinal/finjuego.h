#ifndef FINJUEGO_H
#define FINJUEGO_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class finJuego;
}

class finJuego : public QWidget
{
    Q_OBJECT

public:
    explicit finJuego(QWidget *parent = nullptr);
    ~finJuego();
    void gana();
    void pierde();

private slots:
    void on_btnNuevaPartida_clicked();
    void on_btnCerrar_clicked();
signals:
    void nuevaPartida();

private:
    Ui::finJuego *ui;
};

#endif // FINJUEGO_H
