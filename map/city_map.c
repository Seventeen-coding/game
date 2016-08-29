#include "map/include/city_map.h"

void Enter_city_select()
{
    switch(getch()){
    case 'h':case 'H':
        Help_map();
        break;
    case 'a':case 'A':
        Set_current_map(Hero_info_map);
        break;
    case 'f':case 'F':
        Set_current_map(Main_map);
        break;
    case 'b':case 'B':
        Hero_item_map();
        break;
    case 'c':case 'C':
        Set_current_map(Shop_item_map);
        break;
    case 'd':case 'D':
        Set_current_map(World_map);
        break;
    case 'e':case 'E':
        Set_current_map(Save_Load_map);
        break;
    case 'g':case 'G':
        Set_current_map(Bar_map);
        break;
    case 's':case 'S':
        hero_sleep();
    case 'M':
        //            god_mod();        //说白了就是测试用的
        break;
    }
}

void City_map()
{
    Show_city_menu();
    Enter_city_select();
}

