#include "nooter.h"
#include "type_table.h"
#include <QTextStream>

Type_table types;

Nooter::Nooter(QString name, Type type, QList<Attack> attacks, int hp, int energy, int energy_growth, int max_energy) : name(name), type(type), attacks(attacks), actual_hp(hp), maximum_hp(hp), actual_energy(energy),
                                                                                                                        initial_energy(energy), maximum_energy(max_energy), energy_gain_per_turn(energy_growth)
{
}

Nooter::Nooter(QString name)
{
    if (name == "Nootkia")
    {
        Attack autodestruction("Autodestruction", "la batterie est vieille, EXPLOSION", 1000, 0, 0, types.getType("Feu"));
        Attack ultrason("Ultrason", "emet un ultrason grace a la technologie de pointe", 2000, 0, 0, types.getType("Psy"));
        Attack decharge("Décharge", "consomme de sa batterie pour lancer de l'elec", 3000, 20, 0, types.getType("Electrique"));
        Attack charge("Charge", "se jette sur l'ennemie", 4000, 0, 0, types.getType("Normal"));

        this->name = "Nootkia";
        this->type = types.getType("Acier");
        this->attacks = QList<Attack>({autodestruction, ultrason, decharge, charge});
        ;
        this->actual_hp = 9000;
        this->maximum_hp = 9000;
        this->actual_energy = 30;
        this->initial_energy = 30;
        this->energy_gain_per_turn = 5;
        this->maximum_energy = 100;
    }

    else if (name == "Original_Noot")
    {
        Attack defo1("deforestation", "wallah je coupe des arbres", 1000, 0, 0, types.getType("Herbe"));
        Attack defo2("DEFORESTATION", "encore mieux", 2000, 0, 0, types.getType("Herbe"));
        Attack defo3("DEFORESTATION !", "je découpe beaucoup", 3000, 0, 0, types.getType("Herbe"));
        Attack defo4("DEFORESTATION !!!", "y'a plus d'arbre", 4000, 0, 0, types.getType("Herbe"));

        this->name = "Original_Noot";
        this->type = types.getType("Noot");
        this->attacks = QList<Attack>({defo1, defo2, defo3, defo4});
        ;
        this->actual_hp = 10000;
        this->maximum_hp = 10000;
        this->actual_energy = 20;
        this->initial_energy = 20;
        this->energy_gain_per_turn = 10;
        this->maximum_energy = 100;
    }
    else if (name == "Nootzilla")
    {
        Attack rugissement("Rugissement du dragon", "j'en ai marre d'écrire les descriptions", 1000, 0, 0, types.getType("Dragon"));
        Attack queue("Coup de queue", "tape avec sa queue", 2000, 0, 0, types.getType("Combat"));
        Attack pic("Lance pic", "envoie les pic de son dos", 3000, 0, 0, types.getType("Insect"));
        Attack poing("Coup de poing", "coup de poing que king kong lui a apprie", 4000, 0, 0, types.getType("Combat"));

        this->name = "Nootzilla";
        this->type = types.getType("Dragon");
        this->attacks = QList<Attack>({rugissement, queue, pic, poing});
        this->actual_hp = 9000;
        this->maximum_hp = 9000;
        this->actual_energy = 30;
        this->initial_energy = 30;
        this->energy_gain_per_turn = 5;
        this->maximum_energy = 100;
    }
    else if (name == "Terminootor")
    {
        Attack tir1("tir mitraillette", "pew pew", 1000, 0, 0, types.getType("Acier"));
        Attack tir2("tir bazooka", "kaboom", 2000, 0, 0, types.getType("Acier"));
        Attack grenade("lance grenade", "GRENADAAAA", 3000, 0, 0, types.getType("Roche"));
        Attack tir3("tir de laser", "pew pew en mieux", 4000, 0, 0, types.getType("Acier"));

        this->name = "Terminootor";
        this->type = types.getType("Combat");
        this->attacks = QList<Attack>({tir1, tir2, grenade, tir3});
        this->actual_hp = 9000;
        this->maximum_hp = 9000;
        this->actual_energy = 30;
        this->initial_energy = 30;
        this->energy_gain_per_turn = 5;
        this->maximum_energy = 100;
    }
    else if (name == "BigNoot")
    {
        Attack charge("Charge", "charge normale", 1000, 0, 0, types.getType("Normal"));
        Attack morsure("Morsure", "tape un croc dans l'adversaire", 2000, 0, 0, types.getType("Combat"));
        Attack neige("Boule de neige", "lance une boule de neige", 3000, 0, 0, types.getType("Glace"));
        Attack eboulement("Eboulement", "crie fort et crée un éboulement", 4000, 0, 0, types.getType("Glace"));

        this->name = "BigNoot";
        this->type = types.getType("Glace");
        this->attacks = QList<Attack>({charge, morsure, neige, eboulement});
        this->actual_hp = 9000;
        this->maximum_hp = 9000;
        this->actual_energy = 30;
        this->initial_energy = 30;
        this->energy_gain_per_turn = 5;
        this->maximum_energy = 100;
    }
    else if (name == "BatNoot")
    {
        Attack uppercut("Uppercut", "vraiment besoin d'une description ?", 1000, 0, 0, types.getType("Combat"));
        Attack batarang1("BatNootarang", "lance son boomerang a lui", 2000, 0, 0, types.getType("Vol"));
        Attack batarang2("BatNootarang empoisonné", "fallais bien un type poison", 3000, 0, 0, types.getType("Poison"));
        Attack ciel("Attaque du ciel", "se jette d'un batiment pour ecraser son adversaire", 4000, 0, 0, types.getType("Vol"));

        this->name = "BatNoot";
        this->type = types.getType("Vol");
        this->attacks = QList<Attack>({uppercut, batarang1, batarang2, ciel});
        this->actual_hp = 9000;
        this->maximum_hp = 9000;
        this->actual_energy = 30;
        this->initial_energy = 30;
        this->energy_gain_per_turn = 5;
        this->maximum_energy = 100;
    }
    else if (name == "PyroNoot")
    {
        Attack flamme("lance flamme", "pyroNoot crache du feu", 1000, 0, 0, types.getType("Feu"));
        Attack bouleDeFeu("boule de feu", "lance une boule de feu", 2000, 0, 0, types.getType("Feu"));
        Attack extincteur("coup d'extincteur", "tape fort avec l'extincteur", 3000, 0, 0, types.getType("Combat"));
        Attack extincteur2("extinction du feu", "utilise l'extincteur pour réparer ses betises", 4000, 0, 0, types.getType("Eau"));

        this->name = "PyroNoot";
        this->type = types.getType("Feu");
        this->attacks = QList<Attack>({flamme, bouleDeFeu, extincteur, extincteur2});
        this->actual_hp = 9000;
        this->maximum_hp = 9000;
        this->actual_energy = 30;
        this->initial_energy = 30;
        this->energy_gain_per_turn = 5;
        this->maximum_energy = 100;
    }
    else if (name == "Nooragan")
    {
        Attack brise("brise", "cré une petite brise qui décoiffe", 1000, 0, 0, types.getType("Vol"));
        Attack jet("jet de cannette", "envoie des cannette qu'il avait accumulé dans sa tornade", 2000, 0, 0, types.getType("Normal"));
        Attack jet2("jet de voiture", "envoie une voiture qu'il avait stocké dans sa tornade", 3000, 0, 0, types.getType("Normal"));
        Attack tornade("tornade", "envoie une tornade", 4000, 0, 0, types.getType("Vol"));

        this->name = "Nooragan";
        this->type = types.getType("Vol");
        this->attacks = QList<Attack>({brise, jet, jet2, tornade});
        this->actual_hp = 9000;
        this->maximum_hp = 9000;
        this->actual_energy = 30;
        this->initial_energy = 30;
        this->energy_gain_per_turn = 5;
        this->maximum_energy = 100;
    }
    else if (name == "Nootilus")
    {
        Attack epee("coup d'épée", "donne un coup d'épée", 1000, 0, 0, types.getType("Combat"));
        Attack tirCanon("tir de canon", "lance une coup de canon", 2000, 0, 0, types.getType("Feu"));
        Attack kraken("appel du kraken", "appel son copain le kraken", 3000, 0, 0, types.getType("Eau"));
        Attack abordage("abordage", "débarque avec son équipage", 4000, 0, 0, types.getType("Combat"));

        this->name = "Nootilus";
        this->type = types.getType("Eau");
        this->attacks = QList<Attack>({epee, tirCanon, kraken, abordage});
        this->actual_hp = 9000;
        this->maximum_hp = 9000;
        this->actual_energy = 30;
        this->initial_energy = 30;
        this->energy_gain_per_turn = 5;
        this->maximum_energy = 100;
    }
}

QString Nooter::getName() const
{
    return name;
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

Attack Nooter::getAttackAt(int index)
{
    return attacks.at(index);
}

void Nooter::updateEnergy(int value)
{
    actual_energy += value;
}

int Nooter::getMaximum_hp() const
{
    return maximum_hp;
}

int Nooter::useAttack(Attack attack)
{
    if (attack.getEnergy_cost() <= actual_energy)
    {
        actual_energy -= attack.getEnergy_cost();
        return attack.getDamage();
    }
    return -1;
}

void Nooter::getAttacked(Attack attack)
{
    // degat de l'attaque
    int atkDmg = attack.getDamage();
    // calcul des degats selon le type de l'attaque et le type du perso qui recoit

    Type typeAttack = attack.getType();
    float defenseRatio = getDefenseRatio(typeAttack, this->type);

    // envoie des degats
    actual_hp -= atkDmg * defenseRatio;
}

float Nooter::getDefenseRatio(Type attaquant, Type defenseur)
{
    int iDef = defenseur.getIndex();

    return attaquant.getAtkAtIndex(iDef);
}

void Nooter::endTurn()
{
    actual_energy += energy_gain_per_turn;
}

QString Nooter::toString()
{
    QString res;
    QTextStream buf(&res);
    buf << name << " - "
        << " type : " << type.getName() << "\n";
    buf << actual_hp << "/" << maximum_hp << " hp - " << actual_energy << "/" << maximum_energy << "energy \n";
    foreach (Attack attack, attacks)
    {
        buf << attack.toString();
        if (!attacks.endsWith(attack))
            buf << "\n";
    }
    return res;
}

bool Nooter::operator==(Nooter nooter) const
{
    return name == nooter.name && type == nooter.type && attacks == nooter.attacks && actual_hp == nooter.actual_hp && maximum_hp == nooter.maximum_hp && actual_energy == nooter.actual_energy && maximum_energy == nooter.maximum_energy && energy_gain_per_turn == nooter.energy_gain_per_turn;
}
