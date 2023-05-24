#include "nooter.h"

#include <QTextStream>

Nooter::Nooter(QString name, Type type, QList<Attack> attacks, int hp, int energy, int energy_growth , int max_energy):
    name(name), type(type), attacks(attacks), actual_hp(hp), maximum_hp(hp), actual_energy(energy),
    initial_energy(energy), energy_gain_per_turn(energy_growth),maximum_energy(max_energy)
{

}

Nooter::Nooter(QString name)
{
    switch(name)
    {
        case "Nootkia":
            Attack autodestruction("Autodestruction" , "la batterie est vieille, EXPLOSION", 1000, 0,0,table.getType("Feu"));
            Attack ultrason("Ultrason" , "emet un ultrason grace a la technologie de pointe", 2000, 0,0,table.getType("Psy"));
            Attack decharge("Décharge" , "consomme de sa batterie pour lancer de l'elec", 3000, 20,0,table.getType("Electrique"));
            Attack charge("Charge" , "se jette sur l'ennemie", 4000, 0,0,table.getType("Normal"));

            QList<Attack> liste_atk_n = QList<Attack>({autodestruction,ultrason,decharge,charge});
            this->type = table.getType("Acier");
            this->attacks = liste_atk_n;
            this->actual_hp = 9000;
            this->maximum_hp = 9000;
            this->actual_energy = 30;
            this->initial_energy = 30;
            this->energy_gain_per_turn=5;
            this->maximum_energy=100;


            break;
        case "Original_Noot":
            Attack defo1("deforestation" , "wallah je coupe des arbres", 1000, 0,0,table.getType("Herbe"));
            Attack defo2("DEFORESTATION" , "encore mieux", 2000, 0,0,table.getType("Herbe"));
            Attack defo3("DEFORESTATION !" , "je découpe beaucoup", 3000, 0,0,table.getType("Herbe"));
            Attack defo4("DEFORESTATION !!!" , "y'a plus d'arbre", 4000, 0,0,table.getType("Herbe"));

            QList<Attack> liste_atk_n = QList<Attack>({defo1,defo2,defo3,defo4});
            this->type = table.getType("Noot");
            this->attacks = liste_atk_n;
            this->actual_hp = 10000;
            this->maximum_hp = 10000;
            this->actual_energy = 20;
            this->initial_energy = 20;
            this->energy_gain_per_turn=10;
            this->maximum_energy=100;


            break;
        case "Nootzilla":
            Attack rugissement("Rugissement du dragon" , "j'en ai marre d'écrire les descriptions", 1000, 0,0,table.getType("Dragon"));
            Attack queue("Coup de queue" , "tape avec sa queue", 2000, 0,0,table.getType("Combat"));
            Attack pic("Lance pic" , "envoie les pic de son dos", 3000, 0,0,table.getType("Insect"));
            Attack poing("Coup de poing" , "coup de poing que king kong lui a apprie", 4000, 0,0,table.getType("Combat"));

            QList<Attack> liste_atk_n = QList<Attack>({rugissement,queue,pic,poing});
            this->type = table.getType("Dragon");
            this->attacks = liste_atk_n;
            this->actual_hp = 9000;
            this->maximum_hp = 9000;
            this->actual_energy = 30;
            this->initial_energy = 30;
            this->energy_gain_per_turn=5;
            this->maximum_energy=100;

            break;
        case "Terminootor":
            Attack tir1("tir mitraillette" , "pew pew", 1000, 0,0,table.getType("Acier"));
            Attack tir2("tir bazooka" , "kaboom", 2000, 0,0,table.getType("Acier"));
            Attack grenade("lance grenade" , "GRENADAAAA", 3000, 0,0,table.getType("Roche"));
            Attack tir3("tir de laser" , "pew pew en mieux", 4000, 0,0,table.getType("Acier"));

            QList<Attack> liste_atk_n = QList<Attack>({tir1,tir2,grenade,tir3});
            this->type = table.getType("Combat");
            this->attacks = liste_atk_n;
            this->actual_hp = 9000;
            this->maximum_hp = 9000;
            this->actual_energy = 30;
            this->initial_energy = 30;
            this->energy_gain_per_turn=5;
            this->maximum_energy=100;

            break;
        case "BigNoot":
            Attack charge("Charge" , "charge normale", 1000, 0,0,table.getType("Normal"));
            Attack morsure("Morsure" , "tape un croc dans l'adversaire", 2000, 0,0,table.getType("Combat"));
            Attack neige("Boule de neige" , "lance une boule de neige", 3000, 0,0,table.getType("Glace"));
            Attack eboulement("Eboulement" , "crie fort et crée un éboulement", 4000, 0,0,table.getType("Glace"));

            QList<Attack> liste_atk_n = QList<Attack>({charge,morsure,neige,eboulement});
            this->type = table.getType("Glace");
            this->attacks = liste_atk_n;
            this->actual_hp = 9000;
            this->maximum_hp = 9000;
            this->actual_energy = 30;
            this->initial_energy = 30;
            this->energy_gain_per_turn=5;
            this->maximum_energy=100;
            break;
        case "BatNoot":
            Attack uppercut("Uppercut" , "vraiment besoin d'une description ?", 1000, 0,0,table.getType("Combat"));
            Attack batarang1("BatNootarang" , "lance son boomerang a lui", 2000, 0,0,table.getType("Vol"));
            Attack batarang2("BatNootarang empoisonné" , "fallais bien un type poison", 3000, 0,0,table.getType("Poison"));
            Attack ciel("Attaque du ciel" , "se jette d'un batiment pour ecraser son adversaire", 4000, 0,0,table.getType("Vol"));

            QList<Attack> liste_atk_n = QList<Attack>({uppercut,batarang1,batarang2,ciel});
            this->type = table.getType("Vol");
            this->attacks = liste_atk_n;
            this->actual_hp = 9000;
            this->maximum_hp = 9000;
            this->actual_energy = 30;
            this->initial_energy = 30;
            this->energy_gain_per_turn=5;
            this->maximum_energy=100;

            break;
    }
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
    buf << name << " - " << " type : " << type.getName()<<"\n";
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
