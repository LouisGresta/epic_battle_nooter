#include "type_table.h"
#include "type_tuple.h"


#include "type.h"

#include "qstd.h"
using namespace qstd;

#include <QList>

Type_table::Type_table()
{
    initTable();
}

void Type_table::addType(Type type)
{
    listType.append(type);
}

void Type_table::initTable()
{
    initNormal();   initFeu();          initEau();
    initPlante();    initElectrique();   initGlace();
    initCombat();   initPoison();       initSol();
    initVol();      initPsy();          initInsecte();
    initRoche();    initFantome();      initDragon();
    initAcier();    initFee();          initNoot();
}



void Type_table::initNormal(){
    Type Normal("Normal");

    Normal.addType({"Normal", 1});  Normal.addType({"Feu", 1});         Normal.addType({"Eau", 1});
    Normal.addType({"Plante", 1});   Normal.addType({"Electrique", 1});  Normal.addType({"Glace", 1});
    Normal.addType({"Combat", 1});  Normal.addType({"Poison", 1});      Normal.addType({"Sol", 1});
    Normal.addType({"Vol", 1});     Normal.addType({"Psy", 1});         Normal.addType({"Insecte", 1});
    Normal.addType({"Roche", 0.5});   Normal.addType({"Fantome", 0});     Normal.addType({"Dragon", 1});
    Normal.addType({"Acier", 0.5});   Normal.addType({"Fee", 1});         Normal.addType({"Noot", 0.1});

    addType(Normal);
}

void Type_table::initFeu(){
    Type Feu("Feu");

    Feu.addType({"Normal", 1});  Feu.addType({"Feu", 0.5});         Feu.addType({"Eau", 0.5});
    Feu.addType({"Plante", 2});   Feu.addType({"Electrique", 1});  Feu.addType({"Glace", 2});
    Feu.addType({"Combat", 1});  Feu.addType({"Poison", 1});      Feu.addType({"Sol", 1});
    Feu.addType({"Vol", 1});  Feu.addType({"Psy", 1});      Feu.addType({"Insecte", 2});
    Feu.addType({"Roche", 0.5});  Feu.addType({"Fantome", 1});      Feu.addType({"Dragon", 0.5});
    Feu.addType({"Acier", 2});  Feu.addType({"Fee", 1});      Feu.addType({"Noot", 0.1});

    addType(Feu);
}

void Type_table::initEau(){
    Type Eau("Eau");

    Eau.addType({"Normal", 1});  Eau.addType({"Feu", 2});         Eau.addType({"Eau", 0.5});
    Eau.addType({"Plante", 0.5});   Eau.addType({"Electrique", 1});  Eau.addType({"Glace", 1});
    Eau.addType({"Combat", 1});  Eau.addType({"Poison", 1});      Eau.addType({"Sol", 2});
    Eau.addType({"Vol", 1});  Eau.addType({"Psy", 1});      Eau.addType({"Insecte", 1});
    Eau.addType({"Roche", 2});  Eau.addType({"Fantome", 1});      Eau.addType({"Dragon", 0.5});
    Eau.addType({"Acier", 1});  Eau.addType({"Fee", 1});      Eau.addType({"Noot", 0.1});

    addType(Eau);
}

void Type_table::initPlante(){
    Type Plante("Plante");

    Plante.addType({"Normal", 1});  Plante.addType({"Feu", 0.5});         Plante.addType({"Eau", 2});
    Plante.addType({"Plante", 0.5});   Plante.addType({"Electrique", 1});  Plante.addType({"Glace", 1});
    Plante.addType({"Combat", 1});  Plante.addType({"Poison", 0.5});      Plante.addType({"Sol", 2});
    Plante.addType({"Vol", 0.5});  Plante.addType({"Psy", 1});      Plante.addType({"Insecte", 0.5});
    Plante.addType({"Roche", 2});  Plante.addType({"Fantome", 1});      Plante.addType({"Dragon", 0.5});
    Plante.addType({"Acier", 0.5});  Plante.addType({"Fee", 1});      Plante.addType({"Noot", 0.1});

    addType(Plante);
}

void Type_table::initElectrique(){
    Type Electrique("Electrique");

    Electrique.addType({"Normal", 1});  Electrique.addType({"Feu", 1});         Electrique.addType({"Eau", 2});
    Electrique.addType({"Plante", 0.5});   Electrique.addType({"Electrique", 0.5});  Electrique.addType({"Glace", 1});
    Electrique.addType({"Combat", 1});  Electrique.addType({"Poison", 1});      Electrique.addType({"Sol", 0});
    Electrique.addType({"Vol", 2});     Electrique.addType({"Psy", 1});         Electrique.addType({"Insecte", 1});
    Electrique.addType({"Roche", 1});   Electrique.addType({"Fantome", 1});     Electrique.addType({"Dragon", 0.5});
    Electrique.addType({"Acier", 1});   Electrique.addType({"Fee", 1});         Electrique.addType({"Noot", 0.1});

    addType(Electrique);
}

void Type_table::initGlace(){
    Type Glace("Glace");

    Glace.addType({"Normal", 1});  Glace.addType({"Feu", 0.5});         Glace.addType({"Eau", 0.5});
    Glace.addType({"Plante", 2});   Glace.addType({"Electrique", 1});  Glace.addType({"Glace", 0.5});
    Glace.addType({"Combat", 1});  Glace.addType({"Poison", 1});      Glace.addType({"Sol", 2});
    Glace.addType({"Vol", 2});  Glace.addType({"Psy", 1});      Glace.addType({"Insecte", 1});
    Glace.addType({"Roche", 1});  Glace.addType({"Fantome", 1});      Glace.addType({"Dragon", 2});
    Glace.addType({"Acier", 0.5});  Glace.addType({"Fee", 1});      Glace.addType({"Noot", 0.1});

    addType(Glace);
}

void Type_table::initCombat(){
    Type Combat("Combat");

    Combat.addType({"Normal", 2});  Combat.addType({"Feu", 1});         Combat.addType({"Eau", 1});
    Combat.addType({"Plante", 1});   Combat.addType({"Electrique", 1});  Combat.addType({"Glace", 2});
    Combat.addType({"Combat", 1});  Combat.addType({"Poison", 0.5});      Combat.addType({"Sol", 1});
    Combat.addType({"Vol", 0.5});  Combat.addType({"Psy", 0.5});      Combat.addType({"Insecte", 0.5});
    Combat.addType({"Roche", 2});  Combat.addType({"Fantome", 0});      Combat.addType({"Dragon", 1});
    Combat.addType({"Acier", 2});  Combat.addType({"Fee", 0.5});      Combat.addType({"Noot", 0.1});

    addType(Combat);
}

void Type_table::initPoison(){
    Type Poison("Poison");

    Poison.addType({"Normal", 1});  Poison.addType({"Feu", 1});         Poison.addType({"Eau", 1});
    Poison.addType({"Plante", 2});   Poison.addType({"Electrique", 1});  Poison.addType({"Glace", 1});
    Poison.addType({"Combat", 1});  Poison.addType({"Poison", 0.5});      Poison.addType({"Sol", 0.5});
    Poison.addType({"Vol", 1});  Poison.addType({"Psy", 1});      Poison.addType({"Insecte", 1});
    Poison.addType({"Roche", 0.5});  Poison.addType({"Fantome", 0.5});      Poison.addType({"Dragon", 1});
    Poison.addType({"Acier", 0});  Poison.addType({"Fee", 2});      Poison.addType({"Noot", 0.1});

    addType(Poison);
}

void Type_table::initSol(){
    Type Sol("Sol");

    Sol.addType({"Normal", 1});  Sol.addType({"Feu", 2});         Sol.addType({"Eau", 1});
    Sol.addType({"Plante", 0.5});   Sol.addType({"Electrique", 2});  Sol.addType({"Glace", 1});
    Sol.addType({"Combat", 1});  Sol.addType({"Poison", 2});      Sol.addType({"Sol", 1});
    Sol.addType({"Vol", 0});  Sol.addType({"Psy", 1});      Sol.addType({"Insecte", 0.5});
    Sol.addType({"Roche", 2});  Sol.addType({"Fantome", 1});      Sol.addType({"Dragon", 1});
    Sol.addType({"Acier", 2});  Sol.addType({"Fee", 1});      Sol.addType({"Noot", 0.1});

    addType(Sol);
}

void Type_table::initVol(){
    Type Vol("Vol");

    Vol.addType({"Normal", 1});  Vol.addType({"Feu", 1});         Vol.addType({"Eau", 1});
    Vol.addType({"Plante", 2});   Vol.addType({"Electrique", 0.5});  Vol.addType({"Glace", 1});
    Vol.addType({"Combat", 2});  Vol.addType({"Poison", 1});      Vol.addType({"Sol", 1});
    Vol.addType({"Vol", 1});  Vol.addType({"Psy", 1});      Vol.addType({"Insecte", 2});
    Vol.addType({"Roche", 0.5});  Vol.addType({"Fantome", 1});      Vol.addType({"Dragon", 1});
    Vol.addType({"Acier", 0.5});  Vol.addType({"Fee", 1});      Vol.addType({"Noot", 0.1});

    addType(Vol);
}

void Type_table::initPsy(){
    Type Psy("Psy");

    Psy.addType({"Normal", 1});  Psy.addType({"Feu", 1});         Psy.addType({"Eau", 1});
    Psy.addType({"Plante", 1});   Psy.addType({"Electrique", 1});  Psy.addType({"Glace", 1});
    Psy.addType({"Combat", 2});  Psy.addType({"Poison", 2});      Psy.addType({"Sol", 1});
    Psy.addType({"Vol", 1});  Psy.addType({"Psy", 0.5});      Psy.addType({"Insecte", 1});
    Psy.addType({"Roche", 1});  Psy.addType({"Fantome", 1});      Psy.addType({"Dragon", 1});
    Psy.addType({"Acier", 0.5});  Psy.addType({"Fee", 1});      Psy.addType({"Noot", 0.1});

    addType(Psy);
}

void Type_table::initInsecte(){
    Type Insecte("Insecte");

    Insecte.addType({"Normal", 1});  Insecte.addType({"Feu", 0.5});         Insecte.addType({"Eau", 1});
    Insecte.addType({"Plante", 2});   Insecte.addType({"Electrique", 1});  Insecte.addType({"Glace", 1});
    Insecte.addType({"Combat", 0.5});  Insecte.addType({"Poison", 0.5});      Insecte.addType({"Sol", 1});
    Insecte.addType({"Vol", 0.5});  Insecte.addType({"Psy", 2});      Insecte.addType({"Insecte", 1});
    Insecte.addType({"Roche", 1});  Insecte.addType({"Fantome", 0.5});      Insecte.addType({"Dragon", 1});
    Insecte.addType({"Acier", 0.5});  Insecte.addType({"Fee", 0.5});      Insecte.addType({"Noot", 0.1});

    addType(Insecte);
}

void Type_table::initRoche(){
    Type Roche("Roche");

    Roche.addType({"Normal", 1});  Roche.addType({"Feu", 2});         Roche.addType({"Eau", 1});
    Roche.addType({"Plante", 1});   Roche.addType({"Electrique", 1});  Roche.addType({"Glace", 2});
    Roche.addType({"Combat", 0.5});  Roche.addType({"Poison", 1});      Roche.addType({"Sol", 0.5});
    Roche.addType({"Vol", 2});  Roche.addType({"Psy", 1});      Roche.addType({"Insecte", 2});
    Roche.addType({"Roche", 1});  Roche.addType({"Fantome", 1});      Roche.addType({"Dragon", 1});
    Roche.addType({"Acier", 0.5});  Roche.addType({"Fee", 1});      Roche.addType({"Noot", 0.1});

    addType(Roche);
}

void Type_table::initFantome(){
    Type Fantome("Fantome");

    Fantome.addType({"Normal", 0});  Fantome.addType({"Feu", 1});         Fantome.addType({"Eau", 1});
    Fantome.addType({"Plante", 1});   Fantome.addType({"Electrique", 1});  Fantome.addType({"Glace", 1});
    Fantome.addType({"Combat", 1});  Fantome.addType({"Poison", 1});      Fantome.addType({"Sol", 1});
    Fantome.addType({"Vol", 1});  Fantome.addType({"Psy", 2});      Fantome.addType({"Insecte", 1});
    Fantome.addType({"Roche", 1});  Fantome.addType({"Fantome", 2});      Fantome.addType({"Dragon", 1});
    Fantome.addType({"Acier", 1});  Fantome.addType({"Fee", 1});      Fantome.addType({"Noot", 0.1});

    addType(Fantome);
}

void Type_table::initDragon(){
    Type Dragon("Dragon");

    Dragon.addType({"Normal", 1});  Dragon.addType({"Feu", 1});         Dragon.addType({"Eau", 1});
    Dragon.addType({"Plante", 1});   Dragon.addType({"Electrique", 1});  Dragon.addType({"Glace", 1});
    Dragon.addType({"Combat", 1});  Dragon.addType({"Poison", 1});      Dragon.addType({"Sol", 1});
    Dragon.addType({"Vol", 1});  Dragon.addType({"Psy", 1});      Dragon.addType({"Insecte", 1});
    Dragon.addType({"Roche", 1});  Dragon.addType({"Fantome", 1});      Dragon.addType({"Dragon", 2});
    Dragon.addType({"Acier", 0.5});  Dragon.addType({"Fee", 0});      Dragon.addType({"Noot", 0.1});

    addType(Dragon);
}

void Type_table::initAcier(){
    Type Acier("Acier");

    Acier.addType({"Normal", 1});  Acier.addType({"Feu", 0.5});         Acier.addType({"Eau", 0.5});
    Acier.addType({"Plante", 1});   Acier.addType({"Electrique", 0.5});  Acier.addType({"Glace", 2});
    Acier.addType({"Combat", 1});  Acier.addType({"Poison", 1});      Acier.addType({"Sol", 1});
    Acier.addType({"Vol", 1});  Acier.addType({"Psy", 1});      Acier.addType({"Insecte", 1});
    Acier.addType({"Roche", 2});  Acier.addType({"Fantome", 1});      Acier.addType({"Dragon", 1});
    Acier.addType({"Acier", 0.5});  Acier.addType({"Fee", 2});      Acier.addType({"Noot", 0.1});

    addType(Acier);
}

void Type_table::initFee(){
    Type Fee("Fee");

    Fee.addType({"Normal", 1});  Fee.addType({"Feu", 0.5});         Fee.addType({"Eau", 1});
    Fee.addType({"Plante", 1});   Fee.addType({"Electrique", 1});  Fee.addType({"Glace", 1});
    Fee.addType({"Combat", 2});  Fee.addType({"Poison", 0.5});      Fee.addType({"Sol", 1});
    Fee.addType({"Vol", 1});  Fee.addType({"Psy", 1});      Fee.addType({"Insecte", 1});
    Fee.addType({"Roche", 1});  Fee.addType({"Fantome", 1});      Fee.addType({"Dragon", 2});
    Fee.addType({"Acier", 0.5});  Fee.addType({"Fee", 1});      Fee.addType({"Noot", 0.1});

    addType(Fee);
}

void Type_table::initNoot(){
    Type Noot("Noot");

    Noot.addType({"Normal", 10});  Noot.addType({"Feu", 10});         Noot.addType({"Eau", 10});
    Noot.addType({"Plante", 10});   Noot.addType({"Electrique", 10});  Noot.addType({"Glace", 10});
    Noot.addType({"Combat", 10});  Noot.addType({"Poison", 10});      Noot.addType({"Sol", 10});
    Noot.addType({"Vol", 10});  Noot.addType({"Psy", 10});      Noot.addType({"Insecte", 10});
    Noot.addType({"Roche", 10});  Noot.addType({"Fantome", 10});      Noot.addType({"Dragon", 10});
    Noot.addType({"Acier", 10});  Noot.addType({"Fee", 10});      Noot.addType({"Noot", 10});

    addType(Noot);
}

Type Type_table::getType(QString nomType)
{
    foreach (Type type, this->listType) {
        if( type.getName() == nomType ){
            return type;
        }
    }
    return Type("Type_vide");
}

QString Type_table::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"[\n";

    int i = 1;
    foreach (Type type, listType) {
        if( i % 3 == 0 ){
            buf<<type.toString()<<" }\n";
        } else if( i % 3 == 1 ){
            buf<<"  { "<<type.toString()<<", ";
        }
        else {
            buf<<type.toString()<<", ";
        }
        i++;
    }
    buf<<"]";
    return res;
}
