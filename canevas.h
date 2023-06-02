#ifndef CANEVAS_H
#define CANEVAS_H

#include "nooter.h"
#include <QGridLayout>
#include <QLabel>
#include <QWidget>

#define NB_NOOTERS 7

class Canevas : public QWidget
{
    Q_OBJECT
private:
    int background_height=480, background_width=720;
    QGridLayout *grid_layout = new QGridLayout();
    // labels
    QLabel message = QLabel("Veuillez sélectionner une attaque.");
    QLabel cases[2][2];
    int selected_case_indexes[2] = {0, 0};
    QLabel *selected_case = &cases[selected_case_indexes[0]][selected_case_indexes[1]];
    //nooters
    Nooter nooters[NB_NOOTERS] = {
        Nooter("OriginalNoot"),
        Nooter("BigNoot"),
        Nooter("Nookia"),
        Nooter("Nooragan"),
        Nooter("Nootilus"),
        Nooter("PyroNoot"),
        Nooter("Nootzilla")
    };
    Nooter *activeNooter, *inactiveNooter;
    // nooter positions
    int pos_x_nooter1 = 140, pos_y_nooter1 = 200;
    int pos_x_nooter2 = 500, pos_y_nooter2 = 140;
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
