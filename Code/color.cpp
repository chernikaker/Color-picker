
#include "color.h"

Color::Color()
{
    r=10;
    g=10;
    b=150;

}

QString Color::SetColor()
{
    return "background-color: rgb(" + QString::number(r)+','+ QString::number(g)+','+ QString::number(b)+')';
}


void Color::RgbToCmyk()
{
    k = (std::min(std::min(1-(double)r/255,1-(double)g/255),1-(double)b/255));
    c = ((1-(double)r/255-(double)k)/(1-(double)k));
    m = ((1-(double)g/255-(double)k)/(1-(double)k));
    y = ((1-(double)b/255-(double)k)/(1-(double)k));
    if(r==0&&g==0&&b==0)
    {
        c=0;
        m= 0;
        y=0;
    }

}

void Color::CmykToRgb()
{
    r = (int)((1-c)*255*(1-k));
    g = (int)((1-m)*255*(1-k));
    b = (int)((1-y)*255*(1-k));
}

void Color::RgbToHls()
{
    double newr = ((double) r)/255;
    double newg = ((double) g)/255;
    double newb = ((double) b)/255;
    double max = std::max(std::max(newr,newg), newb);
    double min = std::min(std::min(newr,newg), newb);
   double val= (max+min)/2;
    l = val;
    if(max==min)
    {
        h =0;
        s=0;
    }
    else
    {
        double d = max-min;
        s = val>0.5 ? d/(2-max-min) : d/(max+min);
        if (max == newr) h = (newg - newb) / d + (newg < newb ? 6 : 0);
        if (max == newg) h = (newb - newr) / d + 2;
        if (max == newb) h = (newr - newg) / d + 4;
        h /= 6;
    }
}



void Color::HlsToRgb()
{

    if(s==0)
    {
        r =(int)(255*l);
        g =(int)(255*l);
        b =(int)(255*l);
    }
     else
    {
        double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        double p = 2 * l - q;

        double newr = hueToRgb(p, q, (h + 1.0/3));

        double newg = hueToRgb(p, q, h);
        double newb = hueToRgb(p, q, (h - 1.0/3));

        r =(255*newr);
        g =(255*newg);
        b =(255*newb);

    }
}
double Color::hueToRgb(double p, double q, double t)
{
    if (t < 0) t += 1.0;
    if (t > 1) t -= 1.0;
    if (t < 1.0/6) return p + (q - p) * 6.0 * t;
    if (t < 1.0/2) return q;
    if (t < 2.0/3) return p + (q - p) * (2.0/3 - t) * 6.0;
    return p;
}
