#include "Widget.h"


Widget::Widget()
{
    codec = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codec->toUnicode("Возведение в квадрат"));//Header of form
        frame = new QFrame(this);
        frame->setFrameShadow(QFrame::Raised);
        frame->setFrameShape(QFrame::Panel);//creating and add some attributes to frame (рамка)
        inputLabel = new QLabel(codec->toUnicode("Введите число:"),this);//add lable before the editline to widget
        inputEdit = new QLineEdit("",this);//add edit line to widget
        outputLabel = new QLabel(codec->toUnicode("Результат:"),this);//add lable for output header
        outputEdit = new QLineEdit("",this);// add edit line to output result of calculation
        nextButton = new QPushButton(codec->toUnicode("Следующее"),this);//add button for next culculation
        exitButton = new QPushButton(codec->toUnicode("Выход"),this);//add close button
        calculate = new QPushButton(codec->toUnicode("Вычислить"),this);//add calculate button
        QVBoxLayout *vLayout1 = new QVBoxLayout(frame);//create first Box wich will contain next Widgets...
        vLayout1->addWidget(inputLabel);
        vLayout1->addWidget(inputEdit);
        vLayout1->addWidget(outputLabel);
        vLayout1->addWidget(outputEdit);
        vLayout1->addStretch();//add stretch to unite few widgets like column
        QVBoxLayout *vLayout2 = new QVBoxLayout();//create second Box with will contain next and close buttons
        vLayout2->addWidget(calculate);
        vLayout2->addWidget(nextButton);
        vLayout2->addWidget(exitButton);
        vLayout2->addStretch();//add stretch to unite few widgets like column
        QHBoxLayout *hLayout = new QHBoxLayout(this);//add one more Box
        hLayout->addWidget(frame);
        hLayout->addLayout(vLayout2);
        begin();
        connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));//connect exit button with slot close()
        connect(nextButton,SIGNAL(clicked(bool)),this,SLOT(begin()));//connect next button with begin() funcion
        connect(inputEdit,SIGNAL(returnPressed()),this,SLOT(calc()));//connect enter key with calc() function
        connect(calculate,SIGNAL(clicked(bool)),this,SLOT(calc()));
}


void Widget::begin()
{
}

void Widget::calc()
{
}


