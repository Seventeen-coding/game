#include "map/include/sl_map.h"


void Enter_SL_select()
{
    switch (getch()) {
    case 's': case 'S':
       Save_map();
        break;
    case 'r': case 'R':
        Load_map();
        break;
    case 'q' :case 'Q':
        break;
    default:
        break;
    }
}
void Save_Load_map()
{
    Show_Save_Load_window();
    Enter_SL_select();
}

int Enter_load_select()
{
    switch(getch())
    {

    }
}

void Load_map()
{
    Show_Load_window();
    //Enter_load_select();
    printf("\n档案读取中，请稍候\n\t");
    sttdy(".............",30,0);
    if(SL_load_data()   !=  0)
    {
        printf("\n文件关闭失败！");
        //Set_current_map();// datdell();
        getch();
        return;
    }
    printf("\n档案读取成功！");
    Set_current_map(City_map);
    getch();
}
void Save_map()
{
    Show_Save_window();
    //Enter_save_select();
    printf("\n档案存储中，请稍候\n\t");
    sttdy(".............",30,0);
    if(SL_save_data() != 0)
    {
        printf("\n数据写入失败！");
        getch();
        return;
    }
    printf("\n档案存储成功！");
    getch();
}
