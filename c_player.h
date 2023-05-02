#ifndef C_PLAYER_H
#define C_PLAYER_H

#include <QList>
#include <QString>


class C_Player
{
private:
    int id;
    QString name;
    QList<C_Nooter *> team[5];

public:
    C_Player();
    C_Player(int i, QString n);
    void addNooter(C_Nooter* n);
    void removeNooter(C_Nooter* n);
};

#endif // C_PLAYER_H
