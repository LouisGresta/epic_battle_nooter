#include "player.h"

Player::Player()
{

}

Player::Player(int i, QString n):
    id(i), name(n)
{

}

void Player::addNooter(Nooter *n)
{
    team.append(&n);
}

void Player::removeNooter(Nooter *n)
{
    team.removeOne(&n);

}


