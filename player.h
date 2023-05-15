#ifndef PLAYER_H
#define PLAYER_H

#include <QList>
#include <QString>

#include "nooter.h"

class Player
{
private:
    QString name;
    QList<Nooter> team;

public:
    Player();
    Player(QString name);
    QList<Nooter> getTeam() const;
    void addNooter(Nooter nooter);
    void removeNooter(Nooter nooter);
    QString toString();
    bool operator==(Player player) const;
    int getId() const;
    QString getName() const;
};

#endif // PLAYER_H
