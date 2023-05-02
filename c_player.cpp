#include "c_player.h"

C_Player::C_Player()
{

}

C_Player::C_Player(int i, QString n):
    id(i), name(n)
{

}

void C_Player::addNooter(C_Nooter *n)
{
    team.append(&n);
}

void C_Player::removeNooter(C_Nooter *n)
{
    team.removeOne(&n);
}


