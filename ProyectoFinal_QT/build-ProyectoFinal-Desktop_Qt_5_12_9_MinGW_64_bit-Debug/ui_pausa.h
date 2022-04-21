/********************************************************************************
** Form generated from reading UI file 'pausa.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSA_H
#define UI_PAUSA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pausa
{
public:
    QGraphicsView *graphicsView;
    QPushButton *btnGuardar;
    QPushButton *btnCerrar;

    void setupUi(QWidget *pausa)
    {
        if (pausa->objectName().isEmpty())
            pausa->setObjectName(QString::fromUtf8("pausa"));
        pausa->resize(300, 200);
        graphicsView = new QGraphicsView(pausa);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 260, 76));
        graphicsView->setStyleSheet(QString::fromUtf8("Background-image: url(:/mapa/Alien Invasion_Last Hope.png)"));
        btnGuardar = new QPushButton(pausa);
        btnGuardar->setObjectName(QString::fromUtf8("btnGuardar"));
        btnGuardar->setGeometry(QRect(30, 120, 100, 50));
        QFont font;
        font.setPointSize(13);
        btnGuardar->setFont(font);
        btnCerrar = new QPushButton(pausa);
        btnCerrar->setObjectName(QString::fromUtf8("btnCerrar"));
        btnCerrar->setGeometry(QRect(170, 120, 100, 50));
        btnCerrar->setFont(font);

        retranslateUi(pausa);

        QMetaObject::connectSlotsByName(pausa);
    } // setupUi

    void retranslateUi(QWidget *pausa)
    {
        pausa->setWindowTitle(QApplication::translate("pausa", "Form", nullptr));
        btnGuardar->setText(QApplication::translate("pausa", "Guardar", nullptr));
        btnCerrar->setText(QApplication::translate("pausa", "Cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pausa: public Ui_pausa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSA_H
