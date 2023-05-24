#ifndef WIDGET_H
#define WIDGET_H


#include <QtWidgets>


class Counter: public QLineEdit {  // Однострочный текстовый редактор
    Q_OBJECT

public:
    Counter(const QString & contents, QWidget * parent = 0):
        QLineEdit(contents, parent) {}  //  Создание строки редактирования, содержащей текст contents и родителем parent

signals:
    void tick_signal();

public slots:
    void add_one() {
        QString str = text();
        int r = str.toInt();
        if (r != 0 && r % 5 == 0) emit tick_signal();
        r++;
        str.setNum(r);
        setText(str);
    }
};



class Widget: public QWidget {
    Q_OBJECT

protected:
    QLabel * label1, * label2;
    Counter * edit1, * edit2;
    QPushButton * calcButton;
    QPushButton * exitButton;

public:
    Widget(QWidget * parent);

};


#endif // WIDGET_H
