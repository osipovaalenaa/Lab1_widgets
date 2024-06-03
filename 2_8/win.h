#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>


class Counter:public QLineEdit                              // класс виджета строки счетчика(наследуется от QLineEdit)
{
     Q_OBJECT                                               // макрос подключения сигналов и слотов к классу

public:
     Counter(const QString & contents, QWidget *parent=0):  // конструктор класса Counter
     QLineEdit(contents,parent){}                           // с вызовом конструктора родительского класса

signals:
     void multiplicityFive_signal();                        // сигнал, который срабатывает, когда счетчик достигает числа кратного 5

public slots:
     void add_one()                                         // слот, добавляющий 1 к счетчику
     {
         QString str=text();                                // читаем текст из счетчика
         int count=str.toInt();                             // конвертация текста в число(!!!!!проверки нет, т к пользователь ничего не вводит туда)

         if (count!=0 && count%5 ==0)                       // если число счетчика кратно 5,
             emit multiplicityFive_signal();                // то вызывается соответсвующий сигнал
         count++;                                           // добавляем 1 к числу из счетчика
         str.setNum(count);                                 // конвертируем это число обратно в строку
         setText(str);                                      // устанавливаем строку в счетчик
     }
};

class Win: public QWidget                                   // класс виджета для счетчика
{
    Q_OBJECT

protected:
     QTextCodec *codec;
     QLabel *labelByOne,*labelByFive;                       // лейблы над счетчиками
     Counter *counterByOne,*counterByFive;                  // счетчики
     QPushButton *addOneButton;                             // кнопка добавления 1 к счетчику
     QPushButton *exitButton;                               // кнопка выхода

public:
    Win(QWidget *parent = 0);                               // конструктор создания виджета
};


#endif // WIN_H
