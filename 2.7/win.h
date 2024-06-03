#ifndef WIN_H
#define WIN_H
//подключение необходимых библиотек
#include <QtGui>
#include <QWidget>    //Является базовым классом всех объектов пользовательского интерфейса.
#include <QFrame>     //Базовый класс виджетов, которые могут иметь рамку.
#include <QLabel>     //Обеспечивает отображение текста или изображения.
#include <QLineEdit>  //Виджет представляет собой однострочный текстовый редактор.
#include <QPushButton>//Виджет кнопка
#include <QValidator> //Класс обеспечивает проверку вводимого текста.


class Win : public QWidget      // класс окна
{
    Q_OBJECT                    // макрос Qt, обеспечивающий корректное создание сигналов и слотов

protected:
     QTextCodec *codec;
     QFrame *frame;                 // рамка
     QLabel *inputLabel;            // метка ввода
     QLineEdit *inputEdit;          // строчный редактор ввода
     QLabel *outputLabel;           // метка вывода
     QLineEdit *outputEdit;         // строчный редактор вывода
     QPushButton *nextButton;       // кнопка Следующее
     QPushButton *exitButton;       // кнопка Выход

public:
    Win(QWidget *parent = nullptr);

public slots:
     void begin();                  // метод начальной настройки интерфейса
     void calc();                   // метод реализации вычислений

};

class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
     StrValidator(QObject *parent):QValidator(parent){}
     virtual State validate(QString &str,int &pos)const{ // определение виртуальной функции проверки ввода
        return Acceptable; // метод всегда принимает вводимую строку
     }
};

#endif // WIN_H
