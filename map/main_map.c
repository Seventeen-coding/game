#include "map/include/main_map.h"

int Enter_main_select()
{
    switch(getch())
    {
    case 'a'|'A':
        Set_current_map(New_game);
        break;
    case 'b'|'B':
        Save_Load_map();     //save load
        break;
    case 'c'|'C':
        Show_main_menu_end();              //--> 不好
        break;
    case 'w'|'W':
        Show_main_god_here();
        break;
    default:
        break;
    }
}

void Main_map()
{
    Show_main_window();
    //如果用while在这里判定选择 就不会刷图这么难看了
    Enter_main_select();
}


