#include "canevas.h"

#include <QPainter>

Canevas::Canevas(QWidget *parent)
    : QWidget{parent}
{
    setFocusPolicy(Qt::StrongFocus);
}

void Canevas::keyPressEvent(QKeyEvent *event)
{

}

void Canevas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage background(":/ressources/background/winter_battle_background.jpg");
    painter.drawImage(0, 0, background);
    QPen pen = QPen(QColor(100, 100, 100));
    painter.setBrush(QBrush(QColor(240, 240, 240)));
    int widthRect = 6;
    pen.setWidth(widthRect);
    painter.setPen(pen);
    painter.drawRect(widthRect/2, 414+widthRect/2, 621-widthRect, 100-widthRect);
}
