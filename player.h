#ifndef PLAYER_H
#define PLAYER_H

#include <QList>
#include <QString>

#include "nooter.h"



class Player
{
private:
    int id;
    QString name;
    QList<Nooter *> team;

public:
    Player();
    Player(int i, QString n);
    void addNooter(Nooter n);
    void removeNooter(Nooter n);
};

#endif // PLAYER_H
