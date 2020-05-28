#include "bullet.h"

Bullet::Bullet()
{
    b_bullet1.load(BULLET1_PATH);
    b_bullet2.load(BULLET2_PATH);

    bullet_X=-40;
    bullet_Y=-40;

    //子弹状态 默认空闲
    bullet_free= true;

    //子弹速度；
    bullet_speed=BULLET_SPEED;



    bullet_rec.setWidth(BULLET_WIDTH);
    bullet_rec.setHeight(BULLET_HEIGHT);
    bullet_rec.moveTo(bullet_X,bullet_Y);




}

void Bullet::updatePosition()
{
    if(bullet_free)
    {
        return;
    }

    bullet_X=bullet_X+bullet_speed;
    bullet_rec.moveTo(bullet_X,bullet_Y);

    //子弹超出窗口后变成空闲状态
    if(bullet_X>=2*bullet_rec.width()+GAME_WIDTH)
    {
        bullet_free=true;
    }

}
