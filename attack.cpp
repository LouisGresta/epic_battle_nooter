#include "attack.h"

int Attack::getEnergy_cost() const
{
    return energy_cost;
}

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

