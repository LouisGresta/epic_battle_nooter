#include "nooter.h"

#include <QTextStream>

Nooter::Nooter(QString name, Type type, QList<Attack> attacks, int hp, int energy, int energy_growth , int max_energy):
    name(name), type(type), attacks(attacks), actual_hp(hp), maximum_hp(hp), actual_energy(energy),
    initial_energy(energy), energy_gain_per_turn(energy_growth),maximum_energy(max_energy)
{

}

int Nooter::getActual_hp() const
{
    return actual_hp;
}

int Nooter::getActual_energy() const
{
    return actual_energy;
}

int Nooter::getMaximum_energy() const
{
    return maximum_energy;
}

int Nooter::getEnergy_gain_per_turn() const
{
    return energy_gain_per_turn;
}

void Nooter::updateEnergy(int value)
{
    actual_energy+=value;
}

int Nooter::getMaximum_hp() const
{
    return maximum_hp;
}

int Nooter::useAttack(Attack attack)
{
    if(attack.getEnergy_cost()<= actual_energy)
    {
        actual_energy-=attack.getEnergy_cost();
        return attack.getDamage();
    }
    return -1;
}

void Nooter::getAttacked(int value)
{
    actual_hp-= value;
}

void Nooter::endTurn()
{
    actual_energy+=energy_gain_per_turn;
}

QString Nooter::toString()
{
    QString res;
    QTextStream buf(&res);
    buf << name << " - " << type.getName() << " type : \t";
    buf << actual_hp << "/" << maximum_hp << " hp - " << actual_energy << "/" << maximum_energy << "energy \n";
    foreach (Attack attack, attacks) {
        buf << attack.toString();
        if (!attacks.endsWith(attack))
            buf << "\n";
    }
    return res;
}

bool Nooter::operator==(Nooter nooter) const
{
    return name == nooter.name
            && type == nooter.type
            && attacks == nooter.attacks
            && actual_hp == nooter.actual_hp
            && maximum_hp == nooter.maximum_hp
            && actual_energy == nooter.actual_energy
            && maximum_energy == nooter.maximum_energy
            && energy_gain_per_turn == nooter.energy_gain_per_turn;
}
