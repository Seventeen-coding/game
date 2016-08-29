
#include "window/include/hero_window.h"

void Show_create_hero_window()
{
    system("cls");//清屏
    ttdy("欢迎你！勇士！请告诉我你的名字：","【勇士注册】",1,0,0,0);
}

void Show_hero_info_window()
{
    system("cls");//清屏
    hero_t * hero_p =  Get_current_hero_info();
    ttdy("","【角色信息】",1,0,0,0);
    printf("\n\n侠名：%s",hero_p->name);
    printf("\n\n等级:%d (%d/%d)",hero_p->level,hero_p->EXP,hero_p->UP_GRADE);
    printf("\n血量:%d/%d    魔力:%d/%d",hero_p->HP,hero_p->HP_Max,hero_p->MP,hero_p->MP_Max);
    printf(" \n攻击力:%d \n防御:%d \n速度:%d",hero_p->ATK,hero_p->DEF,hero_p->SPE);
    printf(" \n幸运:%d \n金币:%d  ",hero_p->LUC,hero_p->GOLD);
    printf("\n\n[W]--装备         [Y]--物品     ");
    printf("\n\n[K]--技能         [Q]--返回     ");
}

void Show_hero_weapon_window()
{
    system("cls");//清屏
    int pn_a=1,pn; //超出判断、临时
    char ch;
    date_check();
    btdy("=","包裹");
    printf("\n[W]--药 | [E]--武器 | [R]--奇宝 | [S]--商店 | [Q]--返回菜单\n");
    for(pn=0;pn<60;pn++)
        printf("=");
    printf("\n按键 物品名         价格         当前拥有（个）\n");
    item_t *item_list = Get_item_list();
    int n=1;
    int i ;
    for(i = 0;i < 200; i++){
        if(item_list[i].zyk == 1 && item_list[i].haved > 0 )
        {
            printf("\n[%d]---%s     %d金币        %d个",n++,item_list[i].name,item_list[i].mgold,item_list[i].haved);
        }
    }
    if(n==1)
        printf("\n没有任何武器！");
}

void Show_hero_accessories_window()
{
    system("cls");//清屏
    int pn_a=1,pn; //超出判断、临时
    char ch;
    date_check();
    btdy("=","包裹");
    printf("\n[W]--药 | [E]--武器 | [R]--奇宝 | [S]--商店 | [Q]--返回菜单\n");
    for(pn=0;pn<60;pn++)
        printf("=");
    printf("\n按键 物品名         价格         当前拥有（个）\n");
    item_t *item_list = Get_item_list();
    int n=1;
    int i ;
    for(i = 0;i < 200; i++){
        if(item_list[i].zyk == 2 && item_list[i].haved > 0 )
        {
            printf("\n[%d]---%s     %d金币        %d个",n++,item_list[i].name,item_list[i].mgold,item_list[i].haved);
        }
    }
    if(n==1)
        printf("\n没有任何奇宝！");
}

void Show_hero_item_window()
{
    system("cls");//清屏
    int pn_a=1,pn; //超出判断、临时
    char ch;
    date_check();
    btdy("=","包裹");
    printf("\n[W]--药 | [E]--武器 | [R]--奇宝 | [S]--商店 | [Q]--返回菜单\n");
    for(pn=0;pn<60;pn++)
        printf("=");
    printf("\n按键 物品名         价格         当前拥有（个）\n");
    item_t *item_list = Get_item_list();
    int n=1;
    int i ;
    for(i = 0;i < 200; i++){
        if(item_list[i].zyk == 2 && item_list[i].haved > 0 )
        {
            printf("\n[%d]---%s     %d金币        %d个",n++,item_list[i].name,item_list[i].mgold,item_list[i].haved);
        }
    }
    if(n==1)
        printf("\n没有任何物品！");
}

void Show_upgrade_window()
{
    hero_upgrade();
    hero_t * hero_p =  Get_current_hero_info();
    btdy("-","【升级啦！】");
    printf("\n恭喜你，勇士！你升到了%d级！",hero_p->level);
    printf("\n\n攻击+5\n防御+4\n速度+2\n幸运+1\n ");
}




