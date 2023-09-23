
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <QIcon>
#include <QMouseEvent>
#include <QBrush>

#include "color.h"
#include "gradient.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Color cl;
    Ui::MainWindow *ui;

    Gradient* gr;
    QImage im;
    bool check (QString);
    void SetSliders (int);
    void SetNumbers();
    void GradientPick(QMouseEvent*);
    void mousePressEvent(QMouseEvent* ev)
        {
            GradientPick(ev);
        }
    void mouseMoveEvent(QMouseEvent* ev)
        {
            GradientPick(ev);
    }

private slots:
    void changeCl();
    void changeSlidClRgb(int);
    void changeSlidClCmyk(int);
    void changeSlidClHls(int);
    void changeClButt();

};

#endif // MAINWINDOW_H
