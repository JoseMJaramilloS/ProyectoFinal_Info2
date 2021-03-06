#include "inicio.h"
#include "ui_inicio.h"

inicio::inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
    ui->btnNuevaPartida->setVisible(false);
    ui->btnCargarPartida->setVisible(false);
    ui->linePassword->setEchoMode(QLineEdit::Password);


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
    QFile cuenta(user);
    if ( cuenta.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"Menú","Cuenta creada con Éxito.");
        QTextStream out(&cuenta);
        out << user<<endl;
        out << password<<endl;
        out <<"0,540,3,5"<< endl; // x,y,vidas,balas
        cuenta.close();
    }
    else
    {
        QMessageBox::information(this,"Menú","Error, por favor vuelva a intentarlo.");
    }
}

void inicio::on_btnIngresar_clicked()
{

    user=ui->lineUser->text();
    password=ui->linePassword->text();

    //leer archivo
    QFile archivo(user);
    if(archivo.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream read(&archivo);
        QString clave;
        read.readLine(); //usuario
        clave = read.readLine();
        if( clave == ui->linePassword->text())
        {
            personaje=read.readLine();
            aliens2=read.readLine();
            vidas=read.readLine();
            municion=read.readLine();
            ui->btnNuevaPartida->setVisible(true);
            ui->btnCargarPartida->setVisible(true);
            ui->btnRegistrar->setVisible(false);
            ui->btnIngresar->setVisible(false);
            ui->lineUser->setVisible(false);
            ui->linePassword->setVisible(false);
            archivo.close();
        }
        else
        {
            QMessageBox::information(this,"Menú","La clave ingresada es incorrecta");
        }
    }
    else {
        QMessageBox::information(this,"Menú","El usuario ingresado no existe");
    }
}

void inicio::on_btnNuevaPartida_clicked()
{
    game=new MainWindow(nullptr,false,user);
    connect(game,SIGNAL(nuevaPartidaSgn()),this,SLOT(nuevaPartida()));
    game->show();
    close();
}

void inicio::on_btnCargarPartida_clicked()
{
    game=new MainWindow(nullptr,true,user);
    connect(game,SIGNAL(nuevaPartidaSgn()),this,SLOT(nuevaPartida()));
    game->show();
    close();
}

void inicio::nuevaPartida()
{
    //cout<<"Recibo par anueva partida"<<endl;
    game=new MainWindow(nullptr,false,user);
    game->show();
}

QString inicio::getPassword() const
{
    return password;
}

QString inicio::getUser() const
{
    return user;
}
