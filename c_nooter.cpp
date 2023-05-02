#include "c_nooter.h"

int C_Nooter::getActual_hp() const
{
    return actual_hp;
}

int C_Nooter::getActual_energy() const
{
    return actual_energy;
}

int C_Nooter::getMaximum_energy() const
{
    return maximum_energy;
}

int C_Nooter::getEnergy_gain_per_turn() const
{
    return energy_gain_per_turn;
}

void C_Nooter::updateEnergy(int value)
{
    actual_energy+=value;
}

int C_Nooter::getMaximum_hp() const
{
    return maximum_hp;
}

int C_Nooter::useAttack(Attack a)
{
    if(a.getEnergy_cost()<= this->getActual_energy())
    {
        this->actual_energy-=a.getEnergy_cost();
        return a.getDamage();
    }
    return -1;
}

void C_Nooter::getAttacked(int value)
{
    this->actual_hp-= value;
}

void C_Nooter::endTurn()
{
    this->actual_energy+=this->getEnergy_gain_per_turn();
}

C_Nooter::C_Nooter()
{

}

C_Nooter::C_Nooter(QString n, Attack a[], int hp, int e, int energy_growth):
    name(n),actual_hp(hp),maximum_hp(hp),actual_energy(e),initial_energy(e),energy_gain_per_turn(energy_growth)

{
    //initialisation du tableau des atk
    for(int i=0; i<4 ; i++)
    {
        attacks[i]=a[i];
    }
}
