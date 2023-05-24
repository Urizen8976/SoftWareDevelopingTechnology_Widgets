#ifndef WIDGET_H
#define WIDGET_H


#include "Area.h"


class Widget: public QWidget {
protected:
    Area * area;        // Область отображения рисунка
    QPushButton * btn;  // Кнопка

public:
    Widget();
};


#endif // WIDGET_H
