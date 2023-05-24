#include "Widget.h"
#include "ui_Widget.h"


Widget::Widget()
{
    this -> setWindowTitle("Обработка событий");

    try{
        area = new Area(this);
        btn = new QPushButton("Завершить", this);
    } catch (std::bad_alloc&) { qDebug() << "Memory error!"; exit(0);}

    QVBoxLayout * layout = new QVBoxLayout(this);
    layout -> addWidget(area);
    layout -> addWidget(btn);

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(close()));
};


