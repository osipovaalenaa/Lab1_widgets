#ifndef WINDOW_H
#define WINDOW_H

#include "area.h"
#include<QPushButton>

class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area;        // область отображения рисунка
    QPushButton * exitButton;  // кнопка закрытия виджета

public:
    Window();
};

#endif // WINDOW_H
