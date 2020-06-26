#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "player.h"
#include<QKeyEvent>
#include "tower.h"
#include "bullet.h"
#include "enemy.h"
#include <QApplication>



class MainScene : public QWidget,public player
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    //初始化场景
    void initScene();

    //启动游戏
    void playGame();


    //结束游戏
    void endGame();


    //更新坐标
    void updatePoisition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent *e);


    //地图对象
    map m_map;

    map m_win;

    map m_lose;

    //定时器
    QTimer m_Timer;

    //玩家
    player p_player;


    //防御塔豌豆
    Tower t_tower[45];

    //双发豌豆
    Tower tt_tower[45];

    //防御塔计数
    int tower_count;
    int tower_update_count;

    //坐标是否为空
    int judge_grass[9][5];

    int win_count;

    Enemy e_enemy[ENEMY_NUM];

    void enemyToScene();

    int m_recorder;


    void collisionDetection();


    int plant_delay;






};
#endif // MAINSCENE_H
