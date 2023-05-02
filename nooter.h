#ifndef NOOTER_H
#define NOOTER_H

#include <QString>
#include <QList>
#include "attack.h"
#include "type.h"

class Nooter
{

private:
    QString name;
    Type type;
    QList<Attack *> attacks;
    int actual_hp;
    int maximum_hp;
    int actual_energy;
    int initial_energy;
    int maximum_energy;
    int energy_gain_per_turn;


public:
    Nooter();
    Nooter(QString n, QList<Attack *> a[], int hp , int energy, int energy_growth);
    int getActual_hp() const;
    int getActual_energy() const;
    int getMaximum_energy() const;
    int getEnergy_gain_per_turn() const;
    void updateEnergy(int value);
    int getMaximum_hp() const;
    int useAttack(Attack a);
    void getAttacked(int value);
    void endTurn();
};

#endif // NOOTER_H
