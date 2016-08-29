
#include "map/include/shop_map.h"

int   Enter_shop_select()
{
    switch(getch()){
    case 'w':case 'W':
        Set_current_map(Shop_item_map);
        break;
    case 'e':case 'E':
        Set_current_map(Shop_weapon_map);
        break;
    case 'r':case 'R':
        Set_current_map(Shop_accessories_map);
        break;
    case 's':case 'S':  //包裹?
        Set_current_map(Hero_item_map);
        break;
    case 'q':case 'Q':
        Set_current_map(City_map);  //优化:进入shop可以用一个指针作为返回保存
        break;
    default:
        break;
    }
}
void Shop_item_map()
{
    Show_shop_item_window();
    Enter_shop_select();
}

void Shop_accessories_map()
{
    Show_shop_accessories_window();
    Enter_shop_select();
}
void Shop_weapon_map()
{
    Show_shop_weapon_window();
    Enter_shop_select();
}
