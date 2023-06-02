#ifndef NOOTER_H
#define NOOTER_H

#include <QString>
#include <QList>
#include "attack.h"

class Nooter
{

private:
    QString name;
    Type type = Type("Type_vide");
    QList<Attack> attacks = QList<Attack>();
    int actual_hp = 0;
    int maximum_hp = 0;
    int actual_energy = 0;
    int initial_energy = 0;
    int maximum_energy=0;
    int energy_gain_per_turn=0;


public:
    Nooter(QString name, Type type, QList<Attack> attacks, int hp, int energy, int energy_growth, int max_energy);
    Nooter(QString name);
    int getActual_hp() const;
    int getActual_energy() const;
    int getMaximum_energy() const;
    int getEnergy_gain_per_turn() const;
    Attack getAttackAt(int index);
    void updateEnergy(int value);
    int getMaximum_hp() const;
    int useAttack(Attack a);
    void getAttacked(Attack attack);
    float getDefenseRatio(Type attaquant, Type defenseur);
    void endTurn();
    QString toString();
    bool operator==(Nooter nooter) const;
    QString getName() const;
};

#endif // NOOTER_H
