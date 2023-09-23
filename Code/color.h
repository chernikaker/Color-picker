
#ifndef COLOR_H
#define COLOR_H

#include <QString>
#include <QLabel>


class Color
{


    double c;
    double m;
    double y;
    double k;

    double h;
    double l;
    double s;
public:
    int r;
    int g;
    int b;

    Color();
    QString SetColor();
    int GetR () {return r;}
    int GetB () {return b;}
    int GetG () {return g;}
    double GetC () {return c;}
    double GetM () {return m;}
    double GetY () {return y;}
    double GetK () {return k;}

    double GetH () {return h;}
    double GetL () {return l;}
    double GetS () {return s;}

    bool SetR(int r) {if(r>=0&&r<=255)
        {this->r=r;
            return 1;
        }
        return 0;}
    bool SetG(int g) {if(g>=0&&g<=255)
        {this->g=g;
        return 1;
    }
    return 0;}

    bool SetB(int b)
{
    if(b>=0&&b<=255)
    {
    this->b=b;
    return 1;
}
return 0;}
bool SetC(double c)
{
if(c>=0&&c<=1)
{
    this->c =c;
    return 1;
}
return 0;
}
bool SetM(double m)
{
    if(m>=0&&m<=1)
    {
        this->m =m;
        return 1;
    }
    return 0;
}
    bool SetY(double y)
{
    if(y>=0&&y<=1)
    {
        this->y =y;
        return 1;
    }
    return 0;
}
    bool SetK(double k)
{
    if(k>=0&&k<=100)
    {
        this->k =k;
        return 1;
    }
    return 0;
}

bool SetH(double h)
{
    if(h>=0&&h<=1)
    {
        this->h =h;
        return 1;
    }
    return 0;
}

bool SetL(double l)
{
    if(l>=0&&l<=1)
    {
        this->l =l;
        return 1;
    }
    return 0;
}

bool SetS(double s)
{
    if(s>=0&&s<=1)
    {
        this->s =s;
        return 1;
    }
    return 0;
}

double hueToRgb(double, double, double);

void RgbToCmyk();
void CmykToRgb();
void RgbToHls();
void HlsToRgb();
void HlsToCmyk()
{
    HlsToRgb();
    RgbToCmyk();
}

void CmykToHls()
    {
    CmykToRgb();
    RgbToHls();
    }

};

#endif // COLOR_H
