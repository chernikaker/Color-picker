
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->color->setStyleSheet(cl.SetColor());
    setFixedSize(width(),height());

    setWindowIcon(QIcon(":/gradient/icon1.png"));
    setWindowTitle("Color Picker");

    ui->gradient->setText( (QString::number(ui->gradient->geometry().width())+" "+QString::number(ui->gradient->geometry().height())));
   ui->slider1->setRange(0, 255);
    ui->slider2->setRange(0, 255);
    ui->slider3->setRange(0, 255);
    ui->slider4->setRange(0,100);
    ui->slider5->setRange(0,100);
    ui->slider6->setRange(0,100);
    ui->slider7->setRange(0,100);
    ui->slider8->setRange(0,360);
    ui->slider9->setRange(0,360);
    ui->slider10->setRange(0,360);

    cl.RgbToCmyk();
    cl.RgbToHls();
    SetSliders(1);
    SetSliders(2);
    SetNumbers();


    QPixmap Grad(ui->gradient->width(), ui->gradient->height());
   // Grad.load(":/gradient/grad4.png");
    Grad.load(":/gradient/grad4.jpg");
    ui->gradient->setPixmap(Grad);

    QWidget::connect(ui->param3, SIGNAL(editingFinished()), this, SLOT(changeCl()));
    QWidget::connect(ui->param2, SIGNAL(editingFinished()), this, SLOT(changeCl()));
    QWidget::connect(ui->param1, SIGNAL(editingFinished()), this, SLOT(changeCl()));
    QWidget::connect(ui->param4, SIGNAL(editingFinished()), this, SLOT(changeCl()));
    QWidget::connect(ui->param5, SIGNAL(editingFinished()), this, SLOT(changeCl()));
    QWidget::connect(ui->param6, SIGNAL(editingFinished()), this, SLOT(changeCl()));
    QWidget::connect(ui->param7, SIGNAL(editingFinished()), this, SLOT(changeCl()));

    QWidget::connect(ui->slider1, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClRgb(int)));
    QWidget::connect(ui->slider2, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClRgb(int)));
    QWidget::connect(ui->slider3, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClRgb(int)));

    QWidget::connect(ui->slider4, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClCmyk(int)));
    QWidget::connect(ui->slider5, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClCmyk(int)));
    QWidget::connect(ui->slider6, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClCmyk(int)));
    QWidget::connect(ui->slider7, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClCmyk(int)));

    QWidget::connect(ui->slider8, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClHls(int)));
    QWidget::connect(ui->slider9, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClHls(int)));
    QWidget::connect(ui->slider10, SIGNAL(sliderMoved(int)), this, SLOT(changeSlidClHls(int)));

    QWidget::connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_3, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_4, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_5, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_6, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_7, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_8, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_9, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_10, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_11, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_12, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_13, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_14, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_15, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_16, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_17, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_18, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_19, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_20, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_21, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_22, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_23, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_24, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_25, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_26, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_27, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_28, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_29, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_30, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_31, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_32, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_33, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_34, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_35, SIGNAL(pressed()), this, SLOT(changeClButt()));
    QWidget::connect(ui->pushButton_36, SIGNAL(pressed()), this, SLOT(changeClButt()));
}


void MainWindow::GradientPick(QMouseEvent* ev)
{
    double mouseX = ev->pos().x();
    double mouseY = ev->pos().y();
    if(mouseX < ui->gradient->x() || mouseX > ui->gradient->x() + ui->gradient->width()-1) return;
    if(mouseY < ui->gradient->y() || mouseY > ui->gradient->y() + ui->gradient->height()-1) return;

    QColor temp = grab(QRect(mouseX, mouseY, 1, 1)).toImage().pixelColor(0,0);
    cl.SetR(temp.red());
    cl.SetG(temp.green());
    cl.SetB(temp.blue());
    ui->color->setStyleSheet(cl.SetColor());
    cl.RgbToCmyk();
    cl.RgbToHls();
    SetSliders(1);
    SetSliders(2);
    SetNumbers();

}

bool MainWindow::check (QString str)
{
    if (str.isEmpty()) return 0;
    for(int i =0;i<str.length();i++)
    {
        if(str[i]<48||str[i]>57) return 0;
    }
    return 1;
}

void MainWindow::SetSliders(int a)
{
    if(a!=1)
    {
        ui->slider1->setValue(cl.GetR());
        ui->slider2->setValue(cl.GetG());
        ui->slider3->setValue(cl.GetB());

    }
    if (a!=2)
    {
        ui->slider4->setValue((int)(cl.GetC()*100));
        ui->slider5->setValue((int)(cl.GetM()*100));
        ui->slider6->setValue((int)(cl.GetY()*100));
        ui->slider7->setValue((int)(cl.GetK()*100));
    }
    if(a!=3)
    {
        ui->slider8->setValue((int)(cl.GetH()*360));
        ui->slider9->setValue((int)(cl.GetL()*360));
        ui->slider10->setValue((int)(cl.GetS()*360));
    }


}




void MainWindow::SetNumbers()
{

    ui->param1->setText(QString::number(cl.GetR()));
    ui->param2->setText(QString::number(cl.GetG()));
    ui->param3->setText(QString::number(cl.GetB()));


    ui->param4->setText(QString::number((int)(cl.GetC()*100)));
    ui->param5->setText(QString::number((int)(cl.GetM()*100)));
    ui->param6->setText(QString::number((int)(cl.GetY()*100)));
    ui->param7->setText(QString::number((int)(cl.GetK()*100)));

    ui->param8->setText(QString::number((int)(cl.GetH()*360)));
    ui->param9->setText(QString::number((int)(cl.GetL()*360)));
    ui->param10->setText(QString::number((int)(cl.GetS()*360)));



}
void MainWindow::changeCl()
{
    int comp;
    bool ok;
    int md;
    if(this->sender()==ui->param3)
    {
        comp = ui->param3->text().toInt();

        md =1;
        if(check(ui->param3->text())) ok = this->cl.SetB(comp);
        else ok =0;
    }
    else if(this->sender()==ui->param2)
    {
        comp = ui->param2->text().toInt();
        md =1;

        if(check(ui->param2->text())) ok = this->cl.SetG(comp);
        else ok =0;
    }
    else if(this->sender()==ui->param4)
    {
        md =2;
        comp = ui->param4->text().toInt();

        if(check(ui->param4->text())) ok = this->cl.SetC(((double)comp)/100);
         else ok =0;


    }
    else if(this->sender()==ui->param5)
    {
         md =2;
        comp = ui->param5->text().toInt();

        if(check(ui->param5->text())) ok = this->cl.SetM(((double)comp)/100);
         else ok =0;

    }
    else if(this->sender()==ui->param6)

    {
         md =2;
        comp = ui->param6->text().toInt();

        if(check(ui->param6->text())) ok = this->cl.SetY(((double)comp)/100);
          else ok =0;


    }
    else if(this->sender()==ui->param7)
    {
          md = 2;
        comp = ui->param7->text().toInt();

        if(check(ui->param7->text())) ok = this->cl.SetK(((double)comp)/100);
         else ok =0;


    }

    else
    {
         md =1;
        comp = ui->param1->text().toInt();

        if(check(ui->param1->text()))  ok = this->cl.SetR(comp);
        else ok = 0;
    }
    if(ok)
    {
        if(md == 1)
        {
            cl.RgbToCmyk();
            cl.RgbToHls();
        }
        else if (md==2)
        {
            cl.CmykToRgb();
            cl.CmykToHls();
        }
        ui->color->setStyleSheet(this->cl.SetColor());

        SetSliders(1);
        SetSliders(2);
        SetNumbers();
    }
    else
    {
        if(this->sender()==ui->param3)
        {
            ui->param3->setText(QString::number(cl.GetB()));
        }
        else if(this->sender()==ui->param2)
        {
            ui->param2->setText(QString::number(cl.GetG()));
        }
        else if(this->sender()==ui->param4)
        {
            ui->param4->setText(QString::number((int)(cl.GetC()*100)));
        }
        else if(this->sender()==ui->param5)
        {
            ui->param5->setText(QString::number((int)(cl.GetM()*100)));
        }
        else if(this->sender()==ui->param6)
        {
            ui->param6->setText(QString::number((int)(cl.GetY()*100)));
        }
        else if(this->sender()==ui->param7)
        {
            ui->param7->setText(QString::number((int)(cl.GetK()*100)));
        }
        else
        {
            ui->param1->setText(QString::number(cl.GetR()));
        }
    }



}

void MainWindow::changeSlidClRgb(int val)
{
    if(this->sender()==ui->slider3) this->cl.SetB(val);
    else if(this->sender()==ui->slider2) this->cl.SetG(val);
    else this->cl.SetR(val);
    ui->color->setStyleSheet(this->cl.SetColor());
    cl.RgbToCmyk();
    cl.RgbToHls();
    SetNumbers();
    SetSliders(1);
}

void MainWindow::changeSlidClCmyk(int val)
{
    if(this->sender()==ui->slider4) this->cl.SetC(((double)val)/100);
    else if(this->sender()==ui->slider5) this->cl.SetM(((double)val)/100);
    else if(this->sender()==ui->slider6) this->cl.SetY(((double)val)/100);
    else this->cl.SetK(((double)val)/100);
    cl.CmykToHls();
    ui->color->setStyleSheet(this->cl.SetColor());
    SetNumbers();
    SetSliders(2);
}

void MainWindow::changeSlidClHls(int val)
{
    if(this->sender()==ui->slider8) this->cl.SetH(((double)val)/360);
    else if(this->sender()==ui->slider9) this->cl.SetL(((double)val)/360);
    else this->cl.SetS(((double)val)/360);
    cl.HlsToCmyk();
    ui->color->setStyleSheet(this->cl.SetColor());
    SetNumbers();
    SetSliders(3);
}

void MainWindow::changeClButt()
{
    QPushButton* bt = (QPushButton*) this->sender();

    QColor c = bt->palette().color(QPalette::Window);
    cl.SetR(c.red());
    cl.SetG(c.green());
    cl.SetB(c.blue());

    ui->color->setStyleSheet(cl.SetColor());
    cl.RgbToCmyk();
    cl.RgbToHls();
    SetSliders(1);
    SetSliders(2);
    SetNumbers();
}

MainWindow::~MainWindow()
{

    delete ui;
}


