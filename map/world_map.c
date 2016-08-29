#include "map/include/world_map.h"

static char select_place;
int Enter_world_select()
{
    select_place= getch();
    switch(select_place)
    {
    case 'q':case 'Q':
        Set_current_map(City_map);
        break;
    case 'a':case 'A':
    case 'b':case 'B':
    case 'c':case 'C':
    case 'd':case 'D':
    case 'e':case 'E':
    case 'f':case 'F':
    case 'g':case 'G':
        Set_current_map(Place_map);
        break;
    default:
        break;
    }
}
static char select_enemy;
int Enter_place_select()
{
    select_enemy  = getch();
    switch(select_enemy)
    {
    case  '1':
    case  '2':
    case  '3':
    case  '4':
        Fight_init(select_enemy - '0');
       // Set_fight_enemy(select_enemy - '0');
        Set_current_map(Fight_map);
        break;
    case 'q':case 'Q':
        Set_current_map(World_map);
        break;
    }
}
void World_map()
{
  //  Show_world_window();
    Enter_world_select();
}

void Place_map()
{
    int select = (int)select_place;
    if(select >96)
        select = select -97;
    else if(select <91)
        select =select -65;
    //Show_world_place(select);
    Enter_place_select();
}
