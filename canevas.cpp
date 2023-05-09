#include "canevas.h"

#include <QKeyEvent>
#include <QPainter>
#include <time.h>

void Canevas::updateSelectedCase()
{
    selected_case = &cases[selected_case_indexes[0]][selected_case_indexes[1]];
}

Canevas::Canevas(QWidget *parent)
    : QWidget{parent}
{
    setFocusPolicy(Qt::StrongFocus); // for key handle

    // Set layout
    grid_layout->setVerticalSpacing(6);
    grid_layout->setHorizontalSpacing(34);
    grid_layout->setAlignment(Qt::AlignRight);
    grid_layout->setContentsMargins(QMargins(0, 0, 34, 12));

    grid_layout->addItem(new QSpacerItem(621/2, 424), 0, 0);
    grid_layout->addWidget(&message, 1, 0, Qt::AlignLeft);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            grid_layout->addWidget(&cases[i][j], i+1, j+1);
        }
    }
    setLayout(grid_layout);
}

void Canevas::keyPressEvent(QKeyEvent *event)
{
    int key_code = event->key();
    switch (key_code) {
    case Qt::Key_Left:
        if (selected_case_indexes[1] == 1)
            selected_case_indexes[1] = 0;
        break;
    case Qt::Key_Right:
        if (selected_case_indexes[1] == 0)
            selected_case_indexes[1] = 1;
        break;
    case Qt::Key_Up:
        if (selected_case_indexes[0] == 1)
            selected_case_indexes[0] = 0;
        break;
    case Qt::Key_Down:
        if (selected_case_indexes[0] == 0)
            selected_case_indexes[0] = 1;
        break;
    }
    updateSelectedCase();
    repaint();
}

void Canevas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage background(":/ressources/background/winter_battle_background.jpg");
    //QPixmap noot(":/ressources/nooters/terminootor.png");
    painter.drawImage(0, 0, background);
    QPen pen = QPen(QColor(100, 100, 100));
    int widthRect = 6;
    pen.setWidth(widthRect);
    painter.setPen(pen);
    painter.drawRect(widthRect/2, 414+widthRect/2, 621-widthRect, 100-widthRect);
    painter.setBrush(QBrush(QColor(186, 136, 119)));
    painter.drawRect(widthRect/2, 414+widthRect/2, 2*621/3-widthRect, 100-widthRect);
    painter.setBrush(QBrush(QColor(240, 240, 240)));
    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(2);
    painter.setPen(pen);
    int offset = 5;
    int radius = 3;
    painter.drawRoundedRect(selected_case->pos().x()-offset,
                     selected_case->pos().y()+offset,
                     selected_case->size().width()+2*offset,
                     selected_case->size().height()-2*offset,
                     radius, radius);
}
