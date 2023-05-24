#include "Widget.h"
#include "ui_Widget.h"


Widget::Widget(QWidget * parent):
    QWidget    { parent },
    label1     { new QLabel("Cчет по 1", this)},
    label2     { new QLabel("Cчет по 5", this)},
    edit1      { new Counter("0", this) },
    edit2      { new Counter("0", this) },
    calcButton { new QPushButton("+1", this) },
    exitButton { new QPushButton("Выход", this) }
{
  this -> setWindowTitle("Счетчик");

  QHBoxLayout * layout1 = new QHBoxLayout();
  QHBoxLayout * layout2 = new QHBoxLayout();
  QHBoxLayout * layout3 = new QHBoxLayout();
  QVBoxLayout * layout4 = new QVBoxLayout(this);

  layout1 -> addWidget(label1);
  layout1 -> addWidget(label2);

  layout2 -> addWidget(edit1);
  layout2 -> addWidget(edit2);

  layout3 -> addWidget(calcButton);
  layout3 -> addWidget(exitButton);

  layout4 -> addLayout(layout1);
  layout4 -> addLayout(layout2);
  layout4 -> addLayout(layout3);

  connect(calcButton,   SIGNAL(clicked(bool)),  edit1,   SLOT(add_one()));   //  Установка слотово-сигнальных соединений
  connect(edit1,        SIGNAL(tick_signal()),  edit2,   SLOT(add_one()));
  connect(exitButton,   SIGNAL(clicked(bool)),  this,    SLOT(close()));
}


