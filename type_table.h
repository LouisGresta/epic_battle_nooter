#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

#include "type.h"

class Type_table
{
private:
    QList<Type> listType;

    void initTable();

    void initNormal();
    void initFeu();
    void initEau();
    void initHerbe();
    void initElectrique();
    void initGlace();
    void initCombat();
    void initPoison();
    void initSol();
    void initVol();
    void initPsy();
    void initInsecte();
    void initRoche();
    void initFantome();
    void initDragon();
    void initAcier();
    void initFee();
    void initNoot();
public:
    Type_table();
    void addType(Type type);

    Type getType(QString nomType);

    QString toString();
};

#endif // TYPE_TABLE_H
