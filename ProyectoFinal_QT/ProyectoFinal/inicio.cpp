#include "inicio.h"
#include "ui_inicio.h"

inicio::inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
    ui->btnNuevaPartida->setVisible(false);
    ui->btnCargarPartida->setVisible(false);
}

inicio::~inicio()
{
    delete ui;
}

void inicio::on_btnRegistrar_clicked()
{
    ui->btnNuevaPartida->setVisible(true);
    ui->btnCargarPartida->setVisible(true);
    ui->btnRegistrar->setVisible(false);
    ui->btnIngresar->setVisible(false);
    ui->lineUser->setVisible(false);
    ui->linePassword->setVisible(false);
    user=ui->lineUser->text();
    password=ui->linePassword->text();
    //escibir archivo
}

void inicio::on_btnIngresar_clicked()
{
    ui->btnNuevaPartida->setVisible(true);
    ui->btnCargarPartida->setVisible(true);
    ui->btnRegistrar->setVisible(false);
    ui->btnIngresar->setVisible(false);
    ui->lineUser->setVisible(false);
    ui->linePassword->setVisible(false);
    user=ui->lineUser->text();
    password=ui->linePassword->text();
    //leer archivo
}

void inicio::on_btnNuevaPartida_clicked()
{
    game=new MainWindow();
    game->show();
    close();
}

void inicio::on_btnCargarPartida_clicked()
{

}
