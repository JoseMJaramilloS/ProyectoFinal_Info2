#ifndef PAUSA_H
#define PAUSA_H

#include <QWidget>

namespace Ui {
class pausa;
}

class pausa : public QWidget
{
    Q_OBJECT

public:
    explicit pausa(QWidget *parent = nullptr);
    ~pausa();

private slots:
    void on_btnGuardar_clicked();
    void on_btnCerrar_clicked();

signals:
    void guardar();

private:
    Ui::pausa *ui;
};

#endif // PAUSA_H
