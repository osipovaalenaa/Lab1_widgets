#include "win.h"
#include <QBoxLayout>
#include <QMessageBox>

Win::Win(QWidget *parent)
    : QWidget(parent)
{
     codec = QTextCodec::codecForName("UTF-8"); //Windows-1251
     setWindowTitle(codec->toUnicode("Возведение в квадрат"));

     frame = new QFrame(this);                  // создаем объект рамка
     frame->setFrameShadow(QFrame::Raised);     // декор внешнего вида рамки
     frame->setFrameShape(QFrame::Panel);

     inputLabel = new QLabel(codec->toUnicode("Введите число:"),this);  // создаем лейбл для строки ввода
     inputEdit = new QLineEdit("",this);                                // создаем саму строку ввода

     StrValidator *v=new StrValidator(inputEdit);                       // создаем объект проверки ввода для строки ввода
     inputEdit->setValidator(v);                                        // устанавливаем проверку для строки ввода

     outputLabel = new QLabel(codec->toUnicode("Результат:"),this);     // создаем лейбл над строкой вывода
     outputEdit = new QLineEdit("",this);                               // создаем саму строку вывода

     nextButton = new QPushButton(codec->toUnicode("Следующее"),this);  // создаем кнопку для очистки виджета от предыдущей операции
     exitButton = new QPushButton(codec->toUnicode("Выход"),this);      // создаем кнопку для закрытия виджета

     // компоновка приложения выполняется согласно рисунку 2.
     QVBoxLayout *vLayout1 = new QVBoxLayout(frame);    // создаем в рамке вертикальную разметку и помещаем в нее
     vLayout1->addWidget(inputLabel);                   // лейбл строки ввода
     vLayout1->addWidget(inputEdit);                    // и саму строку ввода
     vLayout1->addWidget(outputLabel);                  // лейбл строки вывода
     vLayout1->addWidget(outputEdit);                   // и саму строку вывода
     vLayout1->addStretch();                            // добавление пружины, чтобы виджеты оставались на своих местах при масштабировании

     QVBoxLayout *vLayout2 = new QVBoxLayout(frame);    // создаем в рамке еще одну вертикальную разметку и помещаем туда
     vLayout2->addWidget(nextButton);                   // кнопку ресета
     vLayout2->addWidget(exitButton);                   // и выхода
     vLayout2->addStretch();                            // добавляем пружину

     QHBoxLayout *hLayout = new QHBoxLayout(this);      // создаем горизонтальную разметку в виджете
     hLayout->addWidget(frame);                         // и добавляем туда рамку с строками и рамку с кнопками
     hLayout->addLayout(vLayout2);

     begin();                                           // вызов слота begin для подготовки виджета к вводу
     // подключение сигналов к слотам
     connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));
     connect(nextButton,SIGNAL(clicked(bool)),this,SLOT(begin()));
     connect(inputEdit,SIGNAL(returnPressed()),this,SLOT(calc()));  // нажатие клавиши enter вызывает функцию вычисления
}

void Win::begin()// метод начальной настройки интерфейса / ресета
{
     inputEdit->clear();               // очищение поля ввода

     nextButton->setEnabled(false);    // делаем кнопку "Следующее" недоступной
     nextButton->setDefault(false);    // делаем ее не дефолтной, чтобы при нажатии клавиши enter она не активировалась, но она и так недоступна

     inputEdit->setEnabled(true);      // делаем строку ввода доступной

     outputLabel->setVisible(false);   // скрываем лейбл над строкой вывода
     outputEdit->setVisible(false);    // и саму строку
     outputEdit->setEnabled(false);    // и делаем ее недоступной

     inputEdit->setFocus();            // устанавливаем фокус на вводе
}
void Win::calc()
{
     bool Ok = true;                     // флаг Ок на корректность ввода
     float res,num;                      // переменные результата и значения, введеного в строку ввода
     QString str = inputEdit->text();    // копируем текст из строки ввода в строку QString
     num = str.toDouble(&Ok);            // конвертация строки в число(с проверкой коректности строки для этого)

     if (Ok){                            // если ввод корректный,
         res = num * num;                // то вычисляем квадрат числа
         str.setNum(res);                // записываем результат в строку
         outputEdit->setText(str);       // выводим результат

         inputEdit->setEnabled(false);   // делаем недоступным поле ввода

         outputLabel->setVisible(true);  // показываем лейбл вывода
         outputEdit->setVisible(true);   // и саму строку вывода

         nextButton->setDefault(true);   // делаем дефолтной кнопку next (можно нажать на нее с помощью клавиши enter)
         nextButton->setEnabled(true);   // делаем ее доступной
         nextButton->setFocus();         // и фокусируемся на ней
     }
     else                                                    // иначе
        if (!str.isEmpty()){                                 // если строка ввода не пустая
             QMessageBox msgBox(QMessageBox::Information,    // создаем окно с ошибкой, где
             codec->toUnicode("Возведение в квадрат."),      // заголовок ошибки
             codec->toUnicode("Введено неверное значение."), // текст ошибки
             QMessageBox::Ok);                               // кнопка закрытия ошибки
             msgBox.exec();                                  // и выводим его
        }
}


