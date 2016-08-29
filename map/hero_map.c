#include "map/include/hero_map.h"

int Enter_hero_name(){
    char player_enter_name[20];
    scanf("%s",player_enter_name);
    if(strlen(player_enter_name)>20)
    {
        printf("\n这么长的名字，我记不住！请重新输入!");
        getch();
        return -1;
    }
    if(strlen(player_enter_name) == 0)
    {
        printf("\n太短了！");
        printf("\n请再次输入!");
        getch();
        return -2;
    }
    Set_hero_name(player_enter_name);
    return 0;
}
int Enter_hero_info_select()
{
    switch(getch()){
    case 'q':case 'Q':
        Set_current_map(City_map);
        break;
    case 'w':case 'W':
        // Set_current_map();
        //   Hero_weapon_map();
        break;
    case 'k':case 'K':
        //   Hero_skill_map();
    case 'y':case 'Y':
        Hero_item_map();
        break;
    }
}

int Enter_hero_item_select()
{
    switch(getch())
    {
    case 'w':case 'W':
        Set_current_map(Hero_item_map);
        break;
    case 'e':case 'E':
         Set_current_map(Hero_weapon_map);
         break;
    case 'r':case 'R':
        Set_current_map(Hero_accessories_map);
        break;
    case 's':case 'S':
        Set_current_map(Shop_item_map);
        break;
    case 'y':case 'Y':
        break;
    }
}

void Create_hero_map()
{
    if( hero_init(NULL,1,5,8,3,5,1000,0,0,50,100,100,50,50) == NULL)  exit(-1);    //申请不了内存空间 可以用exit 退出了
    Show_create_hero_window();
    if(Enter_hero_name() != 0)  return;
    Set_current_map(City_map);
}

void Hero_info_map()
{
    Show_hero_info_window();
    Enter_hero_info_select();
}

void Hero_item_map()
{
    Show_hero_item_window();
    Enter_hero_item_select();
}
void Hero_weapon_map()
{
    Show_hero_weapon_window();
    Enter_hero_item_select();
}
void Hero_accessories_map()
{
    Show_hero_accessories_window();
    Enter_hero_item_select();
}
