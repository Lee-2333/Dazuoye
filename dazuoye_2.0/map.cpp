#include "map.h"
#include "config.h"

map::map()
{
    //加载地图
    m_map1.load(MAP_PATH);
    m_title.load(TITLE_PATH);

    //初始化y轴坐标
    m_map1_posY=-GAME_HEIGHT;

    m_title_posY=0;


}
