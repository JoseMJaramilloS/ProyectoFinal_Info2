#include "pausa.h"
#include "ui_pausa.h"

pausa::pausa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pausa)
{
    ui->setupUi(this);
}

pausa::~pausa()
{
    delete ui;
}

void pausa::on_btnGuardar_clicked()
{
    emit guardar();
    close();
}

void pausa::on_btnCerrar_clicked()
{
    this->close();
}
