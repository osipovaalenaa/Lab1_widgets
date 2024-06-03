#include "area.h"

Area::Area(QWidget *parent):QWidget(parent)     // конструктор виджета
{
    setFixedSize(QSize(300,200));               // установка фиксированного размера виджета
    myline=new MyLine(80,100,50);               // создание фигуры линии (x,y,halfLen)
    myrect=new MyRect(220,100,50);              // создание фигуры прямоугольник
    alpha=0;                                    // инициализация угла
}

void Area::showEvent(QShowEvent *)              // обработчик события, когда виджет стал виден
{
    myTimer=startTimer(50);                     // создание таймера
}

void Area::paintEvent(QPaintEvent *)            // обработчик события отрисовки виджета
{
    QPainter painter(this);                     // создание объекта рисования
    painter.setPen(Qt::red);                    // красного цвета
    myline->move(alpha,&painter);               // движение линии и отрисовка
    myrect->move(alpha*(-0.5),&painter);        // движение прямоугольника и отрисовка
}

void Area::timerEvent(QTimerEvent *event)       // обработчик события срабатывания таймера
{
    if (event->timerId() == myTimer)            // если наш таймер,
    {
        alpha=alpha+0.2;                        // то изменить угол,
        update();                               // обновить внешний вид
    }
    else
        QWidget::timerEvent(event);             // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *)              // обработчик события когда виджет стал скрыт
{
    killTimer(myTimer);                         // уничтожить таймер
}

Area::~Area()                                   // деструктор виджета
{
    delete myline;
    delete myrect;
}

