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
    // labels
    QLabel message = QLabel("Veuillez sélectionner une attaque.");
    QLabel cases[2][2];
    int selected_case_indexes[2] = {0, 0};
    QLabel *selected_case = &cases[selected_case_indexes[0]][selected_case_indexes[1]];
    //tmp nooters
    Nooter terminootor1 = Nooter("BatNoot");
    Nooter terminootor2 = Nooter("Nootzilla");
    Nooter *activeNooter = &terminootor1, *inactiveNooter = &terminootor2;
    // nooter positions
    int pos_x_nooter1 = 20, pos_y_nooter1 = 200;
    int pos_x_nooter2 = 425, pos_y_nooter2 = 100;
    // scene triggers
    int attack_animation_running = 0;
    bool change_player_screen = false;

    void updateSelectedCase();
    void drawNooter(QPainter *painter, Nooter nooter, int x, int y, bool active = true);
    void drawBackground(QPainter *painter);
    void drawSelectedCase(QPainter *painter);
    void attack_animation(int duration);
    void drawChangePlayerScreen(QPainter *painter);

public:
    explicit Canevas(QWidget *parent = nullptr);


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // CANEVAS_H
