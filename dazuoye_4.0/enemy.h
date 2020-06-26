#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>
#include "config.h"

class Enemy
{
public:
    Enemy();

    void updatePosition();
public:
    QPixmap m_enemy;
    QPixmap m_enemy2;



    int enemy_X;
    int enemy_Y;


    QRect enemy_Rect;


    int enemy_health;


    bool enemy_Free;

    int enemy2_Speed;

    int enemy_Speed;


    int game_Flag;//等于0则游戏结束


};

#endif // ENEMY_H
