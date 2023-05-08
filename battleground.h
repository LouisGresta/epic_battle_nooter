#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H

#include "player.h"

#include <QList>



class Battleground
{
private:
    QList<Player> players;
    int turn_count = 0;
    int starting_player;

public:
    Battleground(QList<Player> players, int starting_player_index);
};

#endif // BATTLEGROUND_H
