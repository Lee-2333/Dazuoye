#ifndef TOWER_H
#define TOWER_H
#include <QPixmap>
#include <QRect>
#include "bullet.h"
#include "config.h"





class Tower
{
public:
    Tower();

    void shoot();

    QPixmap t_tower1;
    QPixmap t_tower2;
    void setTower(int x,int y);

    int towerposX;
    int towerposY;
    QRect t_tower1rec;
    QRect t_tower2rec;

    Bullet t_bullet[BULLET_NUM];
    int t_bullet_recorder;


};

#endif // TOWER_H
