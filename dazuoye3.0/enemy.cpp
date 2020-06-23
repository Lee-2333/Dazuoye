#include "enemy.h"
#include "config.h"
Enemy::Enemy()
{
    m_enemy.load(ENEMY_PATH);

    enemy_X=-100;
    enemy_Y=0;


    enemy_Free= false;

    enemy_Speed=ENEMY_SPEED;


    enemy_Rect.setWidth(m_enemy.width());
    enemy_Rect.setHeight(m_enemy.height());
    enemy_Rect.moveTo(enemy_X,enemy_Y);

    game_Flag=1;



}

void Enemy::updatePosition()
{

    if(enemy_Free)
    {
        return;
    }
    enemy_X=enemy_X-ENEMY_SPEED;
    enemy_Rect.moveTo(enemy_X,enemy_Y);


    if(enemy_X==0)
    {
        game_Flag=0;
    }

}
