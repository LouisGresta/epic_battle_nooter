#ifndef CANEVAS_H
#define CANEVAS_H

#include "nooter.h"
#include <QGridLayout>
#include <QLabel>
#include <QWidget>

class Canevas : public QWidget
{
    Q_OBJECT
private:
    int background_height=414, background_width=621;
    QGridLayout *grid_layout = new QGridLayout();
    QLabel message = QLabel("Je n'suis paaaaas un héro, j'veux pas croire ce que disent les journaux.");
    QLabel cases[2][2];
    int selected_case_indexes[2] = {0, 0};
    QLabel *selected_case = &cases[selected_case_indexes[0]][selected_case_indexes[1]];
    int pos_x_nooter1 = 20, pos_y_nooter1 = 200;
    int pos_x_nooter2 = 425, pos_y_nooter2 = 100;

    void updateSelectedCase();
    void drawNooter(QPainter *painter, Nooter nooter, int x, int y, bool active = true);

public:
    explicit Canevas(QWidget *parent = nullptr);


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // CANEVAS_H
