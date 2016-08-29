
#include "window/include/shop_window.h"


void Show_shop_item_window()
{
    system("cls"); //清屏
    int pn;
    btdy("$","灭龙商店");
    printf("\n[W]--药品  |  [E]--武器  |  [R]--奇宝 |  [S]--包裹  |  [Q]--返回菜单\n");
    for(pn=0;pn<60;pn++)
        printf("-");
    printf("\n按键 物品名    价格    最多购买（个）\n");
    int n=1;
    int i;
    item_t *item_list = Get_item_list();
    for(i = 0;i < 200; i++){
        if(item_list[i].zyk == 1 && item_list[i].cbuy == 1)
        {
            printf("\n[%d]---%s     %d金币        %d",n++,item_list[i].name,item_list[i].mgold,item_list[i].mhave-item_list[i].haved);
        }
    }
}

void Show_shop_weapon_window()
{
    system("cls"); //清屏
    int pn;
    btdy("$","灭龙商店");
    printf("\n[W]--药品  |  [E]--武器  |  [R]--奇宝 |  [S]--包裹  |  [Q]--返回菜单\n");
    for(pn=0;pn<60;pn++)
        printf("-");
    printf("\n按键 物品名    价格    最多购买（个）\n");
    int n=1;
    int i;
    item_t *item_list = Get_item_list();
    for(i = 0;i < 200; i++){
        if(item_list[i].zyk == 2 && item_list[i].cbuy == 1)
        {
            printf("\n[%d]---%s     %d金币        %d",n++,item_list[i].name,item_list[i].mgold,item_list[i].mhave-item_list[i].haved);
        }
    }

}

void Show_shop_accessories_window()
{

    system("cls"); //清屏
    int pn;
    btdy("$","灭龙商店");
    printf("\n[W]--药品  |  [E]--武器  |  [R]--奇宝 |  [S]--包裹  |  [Q]--返回菜单\n");
    for(pn=0;pn<60;pn++)
        printf("-");
    printf("\n按键 物品名    价格    最多购买（个）\n");
    int n=1;
    int i;
    item_t *item_list = Get_item_list();
    for(i = 0;i < 200; i++){
        if(item_list[i].zyk == 3 && item_list[i].cbuy == 1)
        {
            printf("\n[%d]---%s     %d金币        %d",n++,item_list[i].name,item_list[i].mgold,item_list[i].mhave-item_list[i].haved);
        }
    }
}
