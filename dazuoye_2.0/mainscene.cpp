#include "mainscene.h"
#include "config.h"
#include <QPainter>
#include <QTimer>



MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{

    initScene();
    playGame();
    tower_count=0;
    tower_update_count=0;
    int i,j;
    for(i=0;i<=8;i++)
    {
        for(j=0;j<=4;j++)
            judge_grass[i][j]=0;
    }

}

MainScene::~MainScene()
{
}


void MainScene::initScene()
{
    //set_size
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //set_title
    setWindowTitle(GAME_TITLE);
    m_Timer.setInterval(GAME_RATE);

}

void MainScene::playGame()
{
    //启动定时器
    m_Timer.start();

    connect(&m_Timer,&QTimer::timeout,[=](){
       updatePoisition();
       update();
    });

}


void MainScene::updatePoisition()
{
    for(int i=0;i<=44;i++)
    {
        if(t_tower[i].towerposX>=30)
        {
            t_tower[i].shoot();
            for(int j=0;j<BULLET_NUM;j++)
            {
                if(t_tower[i].t_bullet[j].bullet_free==false)
                {
                    t_tower[i].t_bullet[j].updatePosition();
                }
            }
        }
        if(tt_tower[i].towerposX>=30)
        {
            tt_tower[i].shoot();
            for(int k=0;k<BULLET_NUM;k++)
            {
                if(tt_tower[i].t_bullet[k].bullet_free==false)
                {
                    tt_tower[i].t_bullet[k].updatePosition();
                }
            }
        }
    }
}

void MainScene::paintEvent(QPaintEvent *)
{
    int i;
    QPainter painter(this);
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_title_posY,m_map.m_title);



    painter.drawPixmap(p_player.playerX,p_player.playerY,p_player.p_player1);

    for(i=0;i<=44;i++)
    {
        if(t_tower[i].towerposX>=30)
        {

        for(int j=0;j<BULLET_NUM;j++)
        {
            if(t_tower[i].t_bullet[j].bullet_free==false)
            {
                painter.drawPixmap(t_tower[i].t_bullet[j].bullet_X,t_tower[i].t_bullet[j].bullet_Y,t_tower[i].t_bullet[j].b_bullet1);
            }
        }
        painter.drawPixmap(t_tower[i].towerposX,t_tower[i].towerposY,t_tower[i].t_tower1);
        }
    }
    for(i=0;i<=44;i++)
    {
        if(tt_tower[i].towerposX>=30)
        {

        for(int j=0;j<BULLET_NUM;j++)
        {
            if(t_tower[i].t_bullet[j].bullet_free==false)
            {
                painter.drawPixmap(tt_tower[i].t_bullet[j].bullet_X,tt_tower[i].t_bullet[j].bullet_Y,tt_tower[i].t_bullet[j].b_bullet1);
            }
        }
        painter.drawPixmap(tt_tower[i].towerposX,tt_tower[i].towerposY,tt_tower[i].t_tower2);

        }
    }




}

void MainScene::keyPressEvent(QKeyEvent *e)
{
    //按Enter开始
    {
        if(e->key()==0x20)
        {
            m_map.m_map1_posY=0;
            m_map.m_title_posY=-GAME_HEIGHT;
            p_player.playerY=80;

        }

    }



    //框体移动
    if(e->key()==0x01000013)
    {
        p_player.move(1);
    }
    else if(e->key()==0x01000015)
    {
        p_player.move(2);
    }
    else if(e->key()==0x01000012)
    {
        p_player.move(3);
    }
    else if(e->key()==0x01000014)
    {
        p_player.move(4);
    }

    //z键种豌豆
    if(e->key()==0x5a)
    {
        if(judge_grass[(p_player.playerX-30)/80][(p_player.playerY-80)/100]==0){
        t_tower[tower_count].setTower(p_player.playerX+12,p_player.playerY+9);
        tower_count++;
        judge_grass[(p_player.playerX-30)/80][(p_player.playerY-80)/100]=1;//1表示种过豌豆
        }
    }

    //a键升级豌豆
    if(e->key()==0x41)
    {
        if(judge_grass[(p_player.playerX-30)/80][(p_player.playerY-80)/100]==1)
            {
            tt_tower[tower_update_count].setTower(p_player.playerX+12,p_player.playerY+9);
            tower_update_count++;
            judge_grass[(p_player.playerX-30)/80][(p_player.playerY-80)/100]=2;//2表示升级1次
            }
    }

}





