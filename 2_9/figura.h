#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura
{
protected:
    int x,y;                                    // координаты расположения центра фигуры
    int halfLen;                                // половина от длины фигуры
    int dx,dy;                                  // координаты вектора, указывающего наклон фигуры (длина вектора = halfLength)

    virtual void draw(QPainter *Painter)=0;     // чистая виртуальная функция для отрисовки фигуры

public:
     Figura(int X,int Y,int Halflen):           // конструктор определяет положение фигуры (X, Y) и размер (halfLen - половина длины)
        x(X),y(Y),halfLen(Halflen){}

     virtual ~Figura(){};
     void move(float Alpha, QPainter *Painter);  // функция движения фигуры (изменения угла наклона)

};

class MyLine:public Figura                      // класс линии, наследуется от класса Figura
{
protected:
    void draw(QPainter *Painter);               // объявление для определения чистой виртуальной функции draw из Figura

public:
     MyLine(int x,int y,int halflen):           // конструктор, который использует родительский конструктор
         Figura(x,y,halflen){}
     ~MyLine(){}
};

class MyRect:public Figura                      // класс прямоугольника, наследуется от класса Figura
{
protected:
    void draw(QPainter *Painter);               // объявление для определения чистой виртуальной функции draw из Figura

public:
    MyRect(int x,int y,int halflen):            // конструктор, который использует родительский конструктор
        Figura(x,y,halflen){}
    ~MyRect(){}

};

#endif // FIGURA_H
