/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_inicio
{
public:
    QPushButton *btnRegistrar;
    QPushButton *btnIngresar;
    QLineEdit *lineUser;
    QLineEdit *linePassword;
    QGraphicsView *graphicsView;
    QPushButton *btnNuevaPartida;
    QPushButton *btnCargarPartida;

    void setupUi(QDialog *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->resize(300, 300);
        btnRegistrar = new QPushButton(inicio);
        btnRegistrar->setObjectName(QString::fromUtf8("btnRegistrar"));
        btnRegistrar->setGeometry(QRect(40, 220, 100, 50));
        QFont font;
        font.setPointSize(11);
        btnRegistrar->setFont(font);
        btnIngresar = new QPushButton(inicio);
        btnIngresar->setObjectName(QString::fromUtf8("btnIngresar"));
        btnIngresar->setGeometry(QRect(160, 220, 100, 50));
        btnIngresar->setFont(font);
        lineUser = new QLineEdit(inicio);
        lineUser->setObjectName(QString::fromUtf8("lineUser"));
        lineUser->setGeometry(QRect(40, 140, 221, 25));
        QFont font1;
        font1.setPointSize(13);
        lineUser->setFont(font1);
        linePassword = new QLineEdit(inicio);
        linePassword->setObjectName(QString::fromUtf8("linePassword"));
        linePassword->setGeometry(QRect(40, 180, 221, 25));
        linePassword->setFont(font1);
        graphicsView = new QGraphicsView(inicio);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 30, 260, 76));
        graphicsView->setStyleSheet(QString::fromUtf8("Background-image: url(:/mapa/Alien Invasion_Last Hope.png)"));
        btnNuevaPartida = new QPushButton(inicio);
        btnNuevaPartida->setObjectName(QString::fromUtf8("btnNuevaPartida"));
        btnNuevaPartida->setGeometry(QRect(90, 150, 123, 51));
        btnNuevaPartida->setFont(font);
        btnCargarPartida = new QPushButton(inicio);
        btnCargarPartida->setObjectName(QString::fromUtf8("btnCargarPartida"));
        btnCargarPartida->setGeometry(QRect(90, 220, 123, 51));
        btnCargarPartida->setFont(font);

        retranslateUi(inicio);

        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QDialog *inicio)
    {
        inicio->setWindowTitle(QApplication::translate("inicio", "Alien Invasion: Last Hope", nullptr));
        btnRegistrar->setText(QApplication::translate("inicio", "Registrar", nullptr));
        btnIngresar->setText(QApplication::translate("inicio", "Ingresar", nullptr));
        btnNuevaPartida->setText(QApplication::translate("inicio", "Nueva Partida", nullptr));
        btnCargarPartida->setText(QApplication::translate("inicio", "Cargar Partida", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
