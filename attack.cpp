#include "attack.h"

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

