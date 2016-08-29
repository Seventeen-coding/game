
#include "map/include/fight_map.h"

void   Enter_fight_select()
{

    switch(getch())
    {
    case 'x':case 'X':
        fight_with_attack(Get_current_hero_info(),Get_fight_enemy_info());
        break;
    case 's':case 'S':
        break;
    case 'f':case 'F':
        break;
    case 'r':case 'R':
        break;
    }
}

void Fight_end()
{
    switch(Get_finally_winner()){
    case HERO_WIN:
        Show_hero_win();
        getch();
        if(Check_up_up_grade() == 0 )
        {
            Show_upgrade_window();
            getch();
        }
        Set_current_map(Place_map);
        break;
    case ENEMY_WIN:
        Show_enemy_win();
        getch();
        Set_current_map(City_map);
        break;
    }
}

void Fight_map()
{
    Show_fight_window();
    if(Check_up_result() != 0) Show_result();
    else {
        Fight_end();
        return ;
    }
    Show_action();
    Enter_fight_select();
}

