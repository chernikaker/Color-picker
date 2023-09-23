#include "gradient.h"
#include "ui_gradient.h"

Gradient::Gradient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gradient)
{
    ui->setupUi(this);
}

Gradient::Gradient(QWidget *parent, Color col): Gradient(parent)
{
    cl = col;
}

void Gradient::ChangeCl(Color cl)
{
    this->cl=cl;
    setStyleSheet(cl.SetColor());
}


Gradient::~Gradient()
{
    delete ui;
}
