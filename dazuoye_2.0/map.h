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

    int m_map1_posY;
    int m_map1_posX;

    int m_title_posY;
};

#endif // MAP_H
