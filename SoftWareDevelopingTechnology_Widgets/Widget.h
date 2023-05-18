#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QtCore5Compat/QTextCodec>
#include <QValidator>
#include <QVBoxLayout>
#include <QMessageBox>


class Widget : public QWidget //  Класс окна
{
    Q_OBJECT

public:
    Widget();

protected:
    QTextCodec *codec;
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход
    QPushButton *calculate;

public slots:
    void begin(); // Метод начальной настройки интерфейса
    void calc(); // Метод реализации вычислений
};


#endif // WIDGET_H
