#ifndef ATTACK_H
#define ATTACK_H

#include "type.h"

#include <QString>

class Attack
{
private:
    QString name;
    QString description;
    int damage;
    int energy_cost;
    int cooldown;
    int starting_cooldown;
    Type type;

public:
    Attack(QString name, QString description, int damage, int energy_cost, int cooldown, Type type);
    int getDamage() const;
    void setCooldown(int newCooldown);
    int getEnergy_cost() const;
    QString toString();
    bool operator==(Attack attack) const;
    QString getName() const;
    QString getDescription() const;
    Type getType() const;
};

#endif // C_ATTACK_H
