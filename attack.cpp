#include "attack.h"

#include <QTextStream>

QString Attack::getName() const
{
    return name;
}

QString Attack::getDescription() const
{
    return description;
}

Attack::Attack(QString name, QString description, int damage, int energy_cost, int cooldown, Type type):
    name(name), description(description), damage(damage), energy_cost(energy_cost), cooldown(cooldown), starting_cooldown(cooldown), type(type)
{

}

int Attack::getDamage() const
{
    return damage;
}

void Attack::setCooldown(int newCooldown)
{
    cooldown = newCooldown;
}

int Attack::getEnergy_cost() const
{
    return energy_cost;
}

QString Attack::toString()
{
    QString res;
    QTextStream buf(&res);
    buf << name << " : \n";
    buf << description << "\n";
    buf << "type : " << type.getName() << "\n";
    buf << "damage : " << damage << "\n";
    buf << "energy_cost : " << energy_cost << "\n";
    buf << "cooldown : " << starting_cooldown;
    return res;
}

bool Attack::operator==(Attack attack) const
{
    return name == attack.name
            && description == attack.description
            && type == attack.type
            && damage == attack.damage
            && energy_cost == attack.energy_cost
            && starting_cooldown == attack.starting_cooldown
            && cooldown == attack.cooldown;
}


