#include "window/include/city_window.h"

void Show_city_menu()
{
    system("cls");//清屏
    int pn;
    date_check();
    system("color 30");
    printf("\n");
    for(pn=0;pn<25;pn++)
        printf(" ");
    printf("【灭龙传说】\n");
    for(pn=0;pn<60;pn++)
        printf("-");
    hero_t *hero_p = Get_current_hero_info();
    printf("\n\n勇士：%s (1级)",hero_p->name);
    printf("\n\n[A]--人物信息\t[B]--包裹 \t [C]--商店");
    printf("\n\n[D]--【战场】\t[E]--档案 \t[F]--返回");
    printf("\n\n[G]--小游戏\t[S]--休息 \t [H]--帮助");
}

