/********************************************************************************
** Form generated from reading UI file 'finjuego.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINJUEGO_H
#define UI_FINJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_finJuego
{
public:
    QGraphicsView *graphicsView;
    QPushButton *btnNuevaPartida;
    QPushButton *btnCerrar;

    void setupUi(QWidget *finJuego)
    {
        if (finJuego->objectName().isEmpty())
            finJuego->setObjectName(QString::fromUtf8("finJuego"));
        finJuego->resize(300, 200);
        graphicsView = new QGraphicsView(finJuego);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 30, 260, 90));
        btnNuevaPartida = new QPushButton(finJuego);
        btnNuevaPartida->setObjectName(QString::fromUtf8("btnNuevaPartida"));
        btnNuevaPartida->setGeometry(QRect(30, 130, 100, 50));
        QFont font;
        font.setPointSize(11);
        btnNuevaPartida->setFont(font);
        btnCerrar = new QPushButton(finJuego);
        btnCerrar->setObjectName(QString::fromUtf8("btnCerrar"));
        btnCerrar->setGeometry(QRect(170, 130, 100, 50));
        btnCerrar->setFont(font);

        retranslateUi(finJuego);

        QMetaObject::connectSlotsByName(finJuego);
    } // setupUi

    void retranslateUi(QWidget *finJuego)
    {
        finJuego->setWindowTitle(QApplication::translate("finJuego", "Form", nullptr));
        btnNuevaPartida->setText(QApplication::translate("finJuego", "Nueva Partida", nullptr));
        btnCerrar->setText(QApplication::translate("finJuego", "Cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class finJuego: public Ui_finJuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINJUEGO_H
