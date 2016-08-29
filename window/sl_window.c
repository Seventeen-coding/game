
#include "window/include/sl_window.h"

void Show_Save_Load_window()
{
    system("cls");
    system("color 30");
    btdy("-","【档案管理】");
    printf("\n请选择菜单进行档案操作！");
    printf("\n\n\nS--存储档案");
    printf("\tR--读取档案");
    printf("\n\n   Q--返回主菜单");
}

void Show_Load_window()
{
    //应该是先读取存档表 然后显示
    system("cls");//清屏
    btdy("-","【读取档案】");
}

void Show_Save_window()
{
    system("cls");//清屏
    btdy("-","【档案存储】");
}
