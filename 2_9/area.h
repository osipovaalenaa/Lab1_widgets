#ifndef AREA_H
#define AREA_H

#include "figura.h"
#include <QWidget>
#include <QTimerEvent>

class Area : public QWidget                 //виджет, содержащий вращающийся прямоугольник и отрезок
{
    int myTimer;                            // идентификатор таймера
    float alpha;                            // угол поворота в радианах

public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;
    MyRect *myrect;

protected:
    // обработчики событий
    void paintEvent(QPaintEvent *event);    // обработчик события отрисовки виджета
    void timerEvent(QTimerEvent *event);    // обработчик события срабатывания таймера
    void showEvent(QShowEvent *event);      // обработчик события, когда виджет стал виден
    void hideEvent(QHideEvent *event);      // обработчик события, когда виджет стал скрыт
};

#endif // AREA_H
