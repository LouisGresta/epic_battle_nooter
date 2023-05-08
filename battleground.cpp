#include "battleground.h"
#include "initParameterException.h"

Battleground::Battleground(QList<Player> players, int starting_player_index):
    players(players), starting_player(starting_player_index)
{
    if (players.size() != 2)
        throw InitParameterException(0);
//    else {
//        active_nooter_p1 = players.at(0).getTeam().at(0);
//        active_nooter_p2 = players.at(1).getTeam().at(0);
//    }
}
