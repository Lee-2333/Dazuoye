#include "mainscene.h"
#include "config.h"
#include <QPainter>
#include <QTimer>
#include <QSound>

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
    win_count=0;
    m_recorder=0;
    plant_delay=0;

}

void MainScene::playGame()
{
    QSound::play(SOUND_BACKGROUND);
    //启动定时器
    m_Timer.start();

    connect(&m_Timer,&QTimer::timeout,[=](){

        plant_delay++;

        enemyToScene();

        updatePoisition();

        update();

        collisionDetection();


        for(int i=0;i<20;i++)
        {
            if(e_enemy[i].game_Flag==0)
            {
                for(int j=0;j<ENEMY_NUM;j++)
                {
                    e_enemy[j].enemy_Free=true;
                }
                m_lose.m_lose_X=0;
                m_lose.m_lose_Y=0;
                m_Timer.stop();


            }
        }
        if(win_count==300)
        {
            m_win.m_win_X=0;
            m_win.m_win_Y=0;
            m_Timer.stop();
        }
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
    for(int i=0;i< ENEMY_NUM;i++)
    {
        if(e_enemy[i].enemy_Free==false)
        {
            e_enemy[i].updatePosition();
        }
    }
}

void MainScene::paintEvent(QPaintEvent *)
{
    int i;
    QPainter painter(this);
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_title_posY,m_map.m_title);
    painter.drawPixmap(m_win.m_win_X,m_win.m_win_Y,m_win.m_win);
    painter.drawPixmap(m_lose.m_lose_X,m_lose.m_lose_Y,m_lose.m_lose);
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
            if(tt_tower[i].t_bullet[j].bullet_free==false)
            {
                painter.drawPixmap(tt_tower[i].t_bullet[j].bullet_X,tt_tower[i].t_bullet[j].bullet_Y,tt_tower[i].t_bullet[j].b_bullet1);
            }
        }
        painter.drawPixmap(tt_tower[i].towerposX,tt_tower[i].towerposY,tt_tower[i].t_tower2);

        }
    }


    //绘制敌人
    for(int i=0;i< ENEMY_NUM;i++)
    {
        if(i%7!=1){
        if(e_enemy[i].enemy_Free==false)
        {
            painter.drawPixmap(e_enemy[i].enemy_X,e_enemy[i].enemy_Y,e_enemy[i].m_enemy);
         }
        }
        if(i%7==1)
        {
            if(e_enemy[i].enemy_Free==false)
            {
                 painter.drawPixmap(e_enemy[i].enemy_X,e_enemy[i].enemy_Y,e_enemy[i].m_enemy2);
            }
        }
    }





}

void MainScene::keyPressEvent(QKeyEvent *e)
{
    //按Space开始
    {
        if(e->key()==0x20)
        {
            m_map.m_map1_posY=0;
            m_map.m_title_posY=-GAME_HEIGHT;
            p_player.playerY=80;
            for(int i=0;i<ENEMY_NUM;i++)
            {
                e_enemy[i].enemy_Free=true;
            }

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
        if(plant_delay<TOWER_INTERVAL)
        {
            return;
        }

        if(judge_grass[(p_player.playerX-30)/80][(p_player.playerY-80)/100]==0)
        {
        t_tower[tower_count].setTower(p_player.playerX+12,p_player.playerY+9);
        tower_count++;
        judge_grass[(p_player.playerX-30)/80][(p_player.playerY-80)/100]=1;//1表示种过豌豆
        plant_delay=0;
        QSound::play(TOWER_PLANT_SOUND_PATH);
        }

    }

    //a键升级豌豆
    if(e->key()==0x41)
    {
        if(plant_delay<TOWER_INTERVAL)
        {
            return;
        }
        if(judge_grass[(p_player.playerX-30)/80][(p_player.playerY-80)/100]==1)
            {
            tt_tower[tower_update_count].setTower(p_player.playerX+12,p_player.playerY+9);
            tower_update_count++;
            judge_grass[(p_player.playerX-30)/80][(p_player.playerY-80)/100]=2;//2表示升级1次
            plant_delay=0;
            QSound::play(TOWER_UPGRATE_SOUND_PATH);
            }


    }

}

void MainScene::enemyToScene()
{
    int temp_interval;

    temp_interval=ENEMY_INTERVAL-win_count*10;
    if(temp_interval<=20)
    {
        temp_interval=20;
    }
    m_recorder++;
    if(m_recorder<temp_interval)
    {
        return;
    }
    m_recorder=0;
    for(int i=0;i< ENEMY_NUM;i++)
    {
        if(e_enemy[i].enemy_Free)
        {
            e_enemy[i].enemy_Free=false;
            e_enemy[i].enemy_X=GAME_WIDTH-e_enemy[i].enemy_Rect.width(); 
            e_enemy[i].enemy_Y=(rand()%5)*100+20;
            if(i%7==1)
            {
                e_enemy[i].enemy_health=3;
            }
            if(i%7!=1)
            {
                e_enemy[i].enemy_health=2;
            }
            e_enemy[i].enemy_X=GAME_WIDTH-e_enemy[i].enemy_Rect.width();
            e_enemy[i].enemy_Y=(rand()%5)*100+20;
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    for(int i=0;i< ENEMY_NUM;i++)
    {
        if(e_enemy[i].enemy_Free)
        {
            continue;
        }
        for(int j=0;j< 45;j++)
        {
            for(int k=0;k<BULLET_NUM;k++)
            {
                if(t_tower[j].t_bullet[k].bullet_free)
                {
                    continue;
                }
                if(e_enemy[i].enemy_Rect.intersects(t_tower[j].t_bullet[k].bullet_rec))
                {
                    e_enemy[i].enemy_health=e_enemy[i].enemy_health-1;
                    QSound::play(HIT_SOUND);

                    if(e_enemy[i].enemy_health==0)
                    {
                        e_enemy[i].enemy_Free=true;
                        win_count++;
                    }
                    t_tower[j].t_bullet[k].bullet_free=true;

                }
            }
        }
    }
    for(int i=0;i< ENEMY_NUM;i++)
    {
        if(e_enemy[i].enemy_Free)
        {
            continue;
        }
        for(int j=0;j< 45;j++)
        {
            for(int k=0;k<BULLET_NUM;k++)
            {
                if(tt_tower[j].t_bullet[k].bullet_free)
                {
                    continue;
                }
                if(e_enemy[i].enemy_Rect.intersects(tt_tower[j].t_bullet[k].bullet_rec))
                {
                    e_enemy[i].enemy_health=e_enemy[i].enemy_health-1;
                    QSound::play(HIT_SOUND);

                    if(e_enemy[i].enemy_health==0)
                    {
                        e_enemy[i].enemy_Free=true;
                        win_count++;
                    }
                    tt_tower[j].t_bullet[k].bullet_free=true;

                }
            }
        }
    }

}



















