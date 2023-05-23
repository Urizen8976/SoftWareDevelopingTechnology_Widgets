#ifndef WIDGET_H
#define WIDGET_H


#include <QtWidgets>            //  Подключение модуля классов для расширения Qt GUI виджетами C++.


class Widget : public QWidget
{
    Q_OBJECT

    QFrame *frame;                  //  Базовый класс виджетов, которые могут иметь рамку (для рамки)
    QLabel *inputLabel;             //  Отображение текста или изображения (для метки ввода)
    QLineEdit *inputEdit;           //  Однострочный текстовый редактор (для строчного редактора ввода)
    QLabel *outputLabel;            //  Отображение текста или изображения (для метки вывода)
    QLineEdit *outputEdit;          //  Однострочный текстовый редактор (для строчного редактора вывода)
    QPushButton *nextButton;        //  Кнопка управления (для кнопки "Следующее")
    QPushButton *exitButton;        //  Кнопка управления (для кнопки "Выход")

public:
    explicit Widget(QWidget *parent);        //  Конструктор с непустым родителем
    explicit Widget(): Widget {nullptr} {}   //  Конструктор без родителя

public slots:
    void begin();                   //  Метод начальной настройки интерфейса
    void calc();                    //  Метод реализации вычислений
};


//class StrValidator:public QValidator // Класс компонента проверки ввода
//{
//public:
//    StrValidator(QObject *parent):QValidator(parent){}
//    virtual State validate(QString &str,int &pos)const
//    {
//        return Acceptable; // Метод всегда принимает вводимую строку
//    }
//};


#endif // WIDGET_H
