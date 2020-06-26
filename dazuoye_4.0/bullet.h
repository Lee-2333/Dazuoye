#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>
#include <QRect>



class Bullet
{
public:
    Bullet();
    void updatePosition();


    QPixmap b_bullet1;
    QPixmap b_bullet2;

    int bullet_X;
    int bullet_Y;

    int bullet_speed;


    //子弹是否闲置
    bool bullet_free;



    QRect bullet_rec;




};

#endif // BULLET_H
