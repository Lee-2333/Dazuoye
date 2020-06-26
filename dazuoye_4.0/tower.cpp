#include "tower.h"
#include "config.h"



Tower::Tower()
{
    t_tower1.load(TOWER1_PATH);
    t_tower2.load(TOWER2_PATH);
    towerposX=-100;
    towerposY=-100;


    //初始化矩形边框
    t_tower1rec.setWidth(TOWER1_WIDTH);
    t_tower1rec.setHeight(TOWER1_HEIGHT);
    t_tower2rec.setWidth(TOWER2_WIDTH);
    t_tower2rec.setHeight(TOWER2_HEIGHT);







}

void Tower::shoot()
{
    //累加时间间隔
    t_bullet_recorder++;

    //如果记录数字未达到时间间隔，不发射
    if(t_bullet_recorder<BULLET_INTERVAL)
    {
        return;
    }

    //达到发射时间
    t_bullet_recorder=0;

    for(int i=0;i<BULLET_NUM;i++)
    {
        if(t_bullet[i].bullet_free)
        {
            t_bullet[i].bullet_free=false;

            t_bullet[i].bullet_X=towerposX+30;
            t_bullet[i].bullet_Y=towerposY;
            break;

        }
    }




}
void Tower::setTower(int x,int y)
{
    towerposX=x;
    towerposY=y;
}
