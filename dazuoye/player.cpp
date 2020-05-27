#include "player.h"
#include "config.h"
#include <QKeyEvent>



player::player()
{
    p_player1.load(PLAYER_PATH);
    playerY=80;
    playerX=30;
}


void player::move(int direction)//1,2,3,4:上下左右
{
    if(direction==1){
        if(playerY>80){
            playerY=playerY-100;
        }
    }
    if(direction==2){
        if(playerY<480){
            playerY=playerY+100;
        }
    }
    if(direction==3){
        if(playerX>30){
            playerX=playerX-80;
        }
    }
    if(direction==4){
        if(playerX<660){
            playerX=playerX+80;
        }
    }
}
