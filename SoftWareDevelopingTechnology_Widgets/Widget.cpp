#include "Widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget * parent):
    QWidget     {parent},                                    //  Базовый класс всех объектов пользовательского интерфейса (для родителя)
    frame       {new QFrame {this}},                         //  Создание рамки
    inputLabel  {new QLabel (("Введите число:"),{this})},    //  Создание поля текста
    inputEdit   {new QLineEdit ((""),{this})},               //  Создание второго поля - поля ввода
    outputLabel {new QLabel (("Результат:"),{this})},        //  Создание объекта с полем текста: "Результат"
    outputEdit  {new QLineEdit ((""),{this})},               //  Создание поля ввода для получения результата
    nextButton  {new QPushButton (("Следующее"), {this})},   //  Созжание кнопки с текстом "Следующее"
    exitButton  {new QPushButton (("Вывод"), {this})}        //  Создание кнопки с текстом "Выход"
{
    setWindowTitle("Возведение в квадрат");                  //  Установка имени окна
    frame -> setFrameShadow(QFrame::Raised);                 //  Добавление тени и панельной рамки вокруг рамки
    frame -> setFrameShape(QFrame::Panel);                   //  Вызов QT необходимого деструктора, не допуская утечек памяти

    QVBoxLayout * vLayout1 = new QVBoxLayout(frame);         //  Класс для выстраивания виджетов вертикально (для вертикального контейнера с рамкой)
    QVBoxLayout * vLayout2 = new QVBoxLayout();              //  Создание вертикального контейнера
    QHBoxLayout * hLayout  = new QHBoxLayout(this);          //  Создание горизонтального контейнера

    vLayout1 -> addWidget(inputLabel);                       //  Добавление двух полей текста и двух полей с вводом:
    vLayout1 -> addWidget(inputEdit);
    vLayout1 -> addWidget(outputLabel);
    vLayout1 -> addWidget(outputEdit);
    vLayout1 -> addStretch();                                //  Добавление контейнеру свойства растяжения при растяжении окна

    vLayout2 -> addWidget(nextButton);                       //  Добавление кнопок: Следующее и Выход
    vLayout2 -> addWidget(exitButton);
    vLayout2 -> addStretch();                                //  Добавление контейнеру свойства растяжения при растяжении окна

    hLayout -> addWidget(frame);                             //  Добавление рамки и вертикального контейнера 2
    hLayout -> addLayout(vLayout2);

    begin();                                                 //  Вызов функции begin
    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(begin()));
    connect(inputEdit,  SIGNAL(returnPressed()),this, SLOT(calc()));
}
//                                 QWidget {parent}


void Widget::begin()
{
    inputEdit   -> clear();               //  Очистка поля ввода
    nextButton  -> setEnabled(false);     //  Деактивация кнопки "Следующее"
    nextButton  -> setDefault(false);     //  Деактивация дефолтного статуса "по умолчанию"
    inputEdit   -> setEnabled(true);      //  Активация окна ввода к пользованию
    outputLabel -> setVisible(false);     //  Деактивация видимости поля "Результат"
    outputEdit  -> setVisible(false);     //  Деактивация видимости поля ввода с ожидаемым в нём результатом
    outputEdit  -> setEnabled(false);     //  Деактивация поля ввода с результатом
    inputEdit   -> setFocus();            //  Установка курсора на поле ввода
}


void Widget::calc()
{
    bool Ok = true;                       //  Инициализация переменной для проверки преобразования
    float r, a;                           //  Инициализация переменных для расчетов
    QString str = inputEdit -> text();    //  Инициализация переменной с текстом из поля ввода
    a = str.toDouble(&Ok);                //  Конвертирование текста в число, меняя при этом значение Ok в случае неуспешной конвертации
    if (Ok) {
        r = a * a;                        //  Возведение в квадрат
        str.setNum(r);                    //  Конвертирование r в строку и передача в str
        outputEdit -> setText(str);       //  Изменение интерфейса для дальнейшего пользования
        inputEdit -> setEnabled(false);
        outputLabel-> setVisible(true);
        outputEdit -> setVisible(true);
        nextButton -> setDefault(true);
        nextButton -> setEnabled(true);
        nextButton -> setFocus();
    } else
        if (!str.isEmpty()) {                                    //  Случай некорректного прохождения проверки непустой строки
            QMessageBox msgBox(QMessageBox::Information,         //  Вывод окна с заголовком "Возведение в квадрат"
                               ("Возведение в квадрат."),        //  И текстом "Введено неверное значение".
                               ("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec();
        }
}
