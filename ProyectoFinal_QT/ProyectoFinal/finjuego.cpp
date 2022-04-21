#include "finjuego.h"
#include "ui_finjuego.h"

finJuego::finJuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::finJuego)
{
    ui->setupUi(this);
}

finJuego::~finJuego()
{
    delete ui;
}

void finJuego::gana()
{
    ui->graphicsView->setStyleSheet("Background-image: url(://mapa/you_win.png)");
}

void finJuego::pierde()
{
    ui->graphicsView->setStyleSheet("Background-image: url(://mapa/you_lose.png)");
}

void finJuego::on_btnNuevaPartida_clicked()
{
    emit nuevaPartida();
    //qDebug()<<"emito para nueva partida"<<endl;
    close();
}

void finJuego::on_btnCerrar_clicked()
{
    close();
}
