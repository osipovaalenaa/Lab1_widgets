#include <math.h>
#include "figura.h"

void Figura::move(float Alpha,QPainter *Painter)    // функция движения фугуры (изменения угла наклона)
{
     dx=halfLen*cos(Alpha);                         // расчет вектора (dx, dy), задающего угол наклона через тригонометрические функции
     dy=halfLen*sin(Alpha);
     draw(Painter);                                 // отрисовка фигуры с новыми параметрами
}

void MyLine::draw(QPainter *Painter)                // функция отрисовки линии, принимает объект для рисования
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);         // отрисовывает в объекте линию с центром в (x, y), параллельную вектору (dx, dy)
}

void MyRect::draw(QPainter *Painter)                // функция отрисовки прямоугольника, принимает объект для рисования
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);         // отрисовка граней прямоугольника с центром в (x, y)
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);         // и диагональю, параллельной вектору (dx, dy)
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);         // (другая диагональ перепендикулярна этому вектору)
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}


