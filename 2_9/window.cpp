#include "window.h"
#include<QTextCodec>
#include<QBoxLayout>

Window::Window() //конструктор виджета
{
    codec = QTextCodec::codecForName("UTF-8");                          // установка кодека для локализации

    this->setWindowTitle(codec->toUnicode("Обработка событий"));        // установка заголовка окна

    area = new Area( this );                                            // создание виджета area на текущем виджете
    exitButton = new QPushButton(codec->toUnicode("Завершить"),this );  // создание кнопки на текущем виджете

    QVBoxLayout *layout = new QVBoxLayout(this);                        // создание вертикальной разметки на текущем виджете
    layout->addWidget(area);                                            // добавление виджета area с фигурами на нее
    layout->addWidget(exitButton);                                      // и кнопки

    connect(exitButton, SIGNAL(clicked(bool)),this,SLOT(close()));      // подключение сигнала нажатия кнопки к слоту закрытия окна
};

