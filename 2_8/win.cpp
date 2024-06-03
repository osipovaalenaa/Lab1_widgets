#include "win.h"
#include <QTextCodec>
#include <QBoxLayout>

Win::Win(QWidget *parent):QWidget(parent)                           // конструктор создания виджета (получает родительский виджет, если он есть)
{
     codec = QTextCodec::codecForName("UTF-8");                     // устанавливаем кодека для русификации виджета
     this->setWindowTitle(codec->toUnicode("Счетчик"));             // устанавливаем заголовка виджета

     labelByOne = new QLabel(codec->toUnicode("Cчет по 1"),this);   // создаем лейбла над счетчиком, который считает по 1
     labelByFive = new QLabel(codec->toUnicode("Cчет по 5"),this);  // создаем лейбла над счетчиком, который считает по 5

     counterByOne = new Counter("0",this);                          // создаем 2-х счетчиков - для счета по 1
     counterByFive = new Counter("0",this);                         // и по 5

     addOneButton=new QPushButton("+1",this);                       // создаем кнопки для добавления 1
     exitButton=new QPushButton(codec->toUnicode("Выход"),this);    // создаем кнопки для выхода

     QHBoxLayout *layout1 = new QHBoxLayout();                      // создаем горизонтальной разметки для лейблов
     layout1->addWidget(labelByOne);                                // и добавляем туда лейблы счетчиков по 1
     layout1->addWidget(labelByFive);                               // и по 5

     QHBoxLayout *layout2 = new QHBoxLayout();                      // создаем горизонтальной разметки для счетчиков
     layout2->addWidget(counterByOne);                              // и добавляем туда сами счетчики по 1
     layout2->addWidget(counterByFive);                             // и по 5

     QHBoxLayout *layout3 = new QHBoxLayout();                      // создаем разметки для кнопок
     layout3->addWidget(addOneButton);                              // и добавляем их туда
     layout3->addWidget(exitButton);

     QVBoxLayout *layout4 = new QVBoxLayout(this);                  // создаем вертикальную разметку для виджета
     layout4->addLayout(layout1);                                   // и добавляем туда ранее созданные разметки с объектами
     layout4->addLayout(layout2);
     layout4->addLayout(layout3);

     // связь сигнала нажатия кнопки и слота закрытия окна
     connect(addOneButton,SIGNAL(clicked(bool)),counterByOne,SLOT(add_one()));
     connect(counterByOne,SIGNAL(multiplicityFive_signal()),counterByFive,SLOT(add_one()));
     connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}
