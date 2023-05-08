#include "player.h"

#include <QTextStream>

QString Player::getName() const
{
    return name;
}

Player::Player(QString name) : name(name), team(QList<Nooter>())
{
}

QList<Nooter> Player::getTeam() const
{
    return team;
}

void Player::addNooter(Nooter nooter)
{
    team.append(nooter);
}

void Player::removeNooter(Nooter nooter)
{
    team.removeOne(nooter);
}

QString Player::toString()
{
    QString res;
    QTextStream buf(&res);

    buf << name << " : \nteam : ";
    foreach (Nooter nooter, team)
    {
        buf << "\t" << nooter.toString();
        if (!team.endsWith(nooter))
            buf << "\n";
    }
    return res;
}

bool Player::operator==(Player player) const
{
    return name == player.name && team == player.team;
}
