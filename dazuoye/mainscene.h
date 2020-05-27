#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "player.h"
#include<QKeyEvent>

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

    //更新坐标
    void updatePoisition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent *e);


    //地图对象
    map m_map;

    //定时器
    QTimer m_Timer;

    //玩家
    player p_player;











};
#endif // MAINSCENE_H
