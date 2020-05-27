#include "mainscene.h"
#include "config.h"
#include <QPainter>
#include <QTimer>



MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();
    playGame();
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

}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);


    painter.drawPixmap(p_player.playerX,p_player.playerY,p_player.p_player1);

}

void MainScene::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==0x01000013){
        p_player.move(1);
    }
    else if(e->key()==0x01000015){
        p_player.move(2);
    }
    else if(e->key()==0x01000012){
        p_player.move(3);
    }
    else if(e->key()==0x01000014){
        p_player.move(4);
    }
}





