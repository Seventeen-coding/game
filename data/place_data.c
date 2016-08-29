#include "data/include/place_data.h"
extern enemy_t enemy[200];
place_t *current_place = NULL;
place_t place[8]={
    {"叶龙岛","嘎嘎，欢迎踏入死亡之岛！",0,4,1},
    {"炎龙沙漠","Welcome!炎龙岛群龙大喊！",4,4,3},
    {"青龙仙宫","青龙仙宫，天下第一宫！",8,4,5},
    {"恶龙洞穴","你来这里是要作死么？",12,4,10},
    {"水晶宫","龙王在此。还不下跪？",16,4,15},
    {"龙王殿","真正的龙王在这里。",20,4,19},
    {"超级魔龙","你能来到这里算你命大，不过到此结束了！",24,4,30},
};//地图定义：地图名，简介；怪物起点，怪物数量，限制等级



static list_node *list = NULL;

place_t *Get_current_place()
{
    return current_place;
}

place_t *Get_place(int num)
{
    //这里有待优化
    list_destroy(&place[num].enemy_list);
    place[num].enemy_list = list_create(NULL);
    Init_place_enemy(place[num].enemy_list,num);
    current_place =  &place[num];
    return current_place;
}


list_node *Get_place_list(int num)
{
    return place[num].enemy_list;
}

