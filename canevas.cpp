#include "canevas.h"

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <time.h>

void Canevas::updateSelectedCase()
{
    selected_case = &cases[selected_case_indexes[0]][selected_case_indexes[1]];
}

void Canevas::drawNooter(QPainter *painter, Nooter nooter, int x, int y, bool active)
{
    int line_lenght = 150;
    int width_hp_bar = 6;
    int width_energy_bar = 4;
    int img_size = 200;
    // draw PV
    QPen pen = QPen(QColor(255, 0, 0));
    pen.setWidth(width_hp_bar);
    painter->setPen(pen);
    painter->drawLine(x, y, x+line_lenght, y);
    pen.setColor(QColor(0, 255, 0));
    painter->setPen(pen);
    painter->drawLine(x, y, x+((float) nooter.getActual_hp()/nooter.getMaximum_hp() * line_lenght), y);
    if(active){
        // draw Energy
        int diff_bar_width = width_hp_bar - width_energy_bar;
        pen.setWidth(width_energy_bar);
        pen.setColor(QColor(100, 100, 100));
        painter->setPen(pen);
        painter->drawLine(x-diff_bar_width/2,
                         y+width_energy_bar,
                         x+line_lenght+diff_bar_width/2,
                         y+width_energy_bar);
        pen.setColor(QColor(0, 255, 240));
        painter->setPen(pen);
        painter->drawLine(x-diff_bar_width/2,
                         y+width_energy_bar,
                         x+((float) nooter.getActual_energy()/nooter.getMaximum_energy() * (line_lenght+diff_bar_width/2)),
                         y+width_energy_bar);
    }
    QPixmap noot(":/ressources/nooters/" + nooter.getName() + ".png");
    painter->drawPixmap(x, y, img_size, img_size, noot);
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

    grid_layout->addItem(new QSpacerItem(background_width/2, background_height+10), 0, 0);
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
    bool action = false;
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
    case Qt::Key_Space:
        action = true;
    }
    updateSelectedCase();
    if(action){
        // lancer attaque sélectionnée (selected_case) et animation d'attaque (clignotement adversaire)
        // et passer au tour suivant avec un message qui reste jusqu'au clic d'une touche puis changer de pov
    }
    repaint();
}

void Canevas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage background(":/ressources/background/winter_battle_background.jpg");
    painter.drawImage(0, 0, background);
    QPen pen = QPen(QColor(100, 100, 100));
    int width_rect_line = 6;
    pen.setWidth(width_rect_line);
    painter.setPen(pen);
    painter.drawRect(width_rect_line/2, background_height+width_rect_line/2, background_width-width_rect_line, 100-width_rect_line);
    painter.setBrush(QBrush(QColor(186, 136, 119)));
    painter.drawRect(width_rect_line/2, background_height+width_rect_line/2, 2*background_width/4-width_rect_line, 100-width_rect_line);

    Nooter terminootor("Terminootor");
    drawNooter(&painter, terminootor, pos_x_nooter1, pos_y_nooter1);
    drawNooter(&painter, terminootor, pos_x_nooter2, pos_y_nooter2, false);
    message.setText("Veuillez sélectionner une attaque.");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cases[i][j].setText(terminootor.getAttackAt(i+j).getName());
        }
    }
    // draw selected rectangle
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
