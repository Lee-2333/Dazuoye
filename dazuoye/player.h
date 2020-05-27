#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>
#include <QKeyEvent>

class player
{
public:
    player();
    void setTower();
    void setPosition(int x,int y);
    QPixmap p_player1;
    void move(int direction);


    int playerX;
    int playerY;
};

#endif // PLAYER_H
