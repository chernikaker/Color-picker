#ifndef GRADIENT_H
#define GRADIENT_H

#include <QWidget>
#include <QMainWindow>
#include <QRgb>
#include <qmath.h>
#include "color.h"


namespace Ui {
class Gradient;
}

class Gradient : public QWidget
{
    Q_OBJECT

public:
    explicit Gradient(QWidget *parent = nullptr);
    Gradient (QWidget *parent, Color);
    void ChangeCl(Color);

    ~Gradient();


private:
    Ui::Gradient *ui;
    Color cl;

};

#endif // GRADIENT_H
