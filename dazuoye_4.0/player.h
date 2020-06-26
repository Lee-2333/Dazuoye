#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>
#include <vector>
#include "tower.h"
#include "config.h"

class player
{
public:
    player();
    void setPosition(int x,int y);
    QPixmap p_player1;
    void move(int direction);


    int playerX;
    int playerY;
    Tower t_tower;

};

#endif // PLAYER_H
