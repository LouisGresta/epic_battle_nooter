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
}
