#ifndef MAP_H
#define MAP_H
#include <QPixmap>


class map
{
public:
    map();


public:
    QPixmap m_map1;
    QPixmap m_title;
    QPixmap m_win;
    QPixmap m_lose;

    int m_win_X;
    int m_win_Y;

    int m_lose_X;
    int m_lose_Y;



    int m_map1_posY;
    int m_map1_posX;

    int m_title_posY;
    int m_end1_posY;
};

#endif // MAP_H
