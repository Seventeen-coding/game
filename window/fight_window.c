#include "window/include/fight_window.h"

void Show_result()
{
    fight_result_t *result= Get_fight_result();
    hero_t * hero  = Get_current_hero_info();
    enemy_t *enemy = Get_fight_enemy_info();
    gsdy("-",60);
    printf("\n\t【结果】：%s损失：%d\n",enemy->name,result->hero_attack);
    printf("\n\t          %s损失: %d\n",hero->name,result->enemy_attack);
}

void Show_fight_window()
{
    place_t  *current_place = Get_current_place();
    enemy_t *enemy = Get_fight_enemy_info();
    hero_t * hero  = Get_current_hero_info();
    btdy("-","【战斗ing】");
    printf("\n%s:%s",enemy->name,enemy->talk);
    gsdy("-",60);
    printf("\n[%8.8s]\t【VS】\t[%8.8s]\n",hero->name,enemy->name);
    printf("\n勇士HP:%d\t  |\t怪物HP:%d",hero->HP,enemy->HP);
    printf("\n勇士MP:%d",hero->MP);
    printf("\n");
    gsdy("-",60);
}

void Show_action()
{
    printf("\n[X]--普通攻击    [S]--技能   [F]--包裹   [R]--逃跑");
    printf("\n\t[Z]--查看怪物信息    [Q]--返回上页");
}
void Show_hero_win()
{
    //如果想再弄好一点把数据和图形分析 修改一下接口就可以了
    enemy_t *enemy = Get_fight_enemy_info();
    hero_t * hero  = Get_current_hero_info();
    btdy("-","【战斗胜利！】");
    printf("\n你战胜了 %s",hero->name);
    printf("\n【战果】:");
    printf("\n获得经验:%d",enemy->EXP);
    printf("\n获得金币:%d",enemy->GOLD);
    Set_hero_EXP(hero->EXP+enemy->EXP);
    Set_hero_GOLD(hero->GOLD+enemy->GOLD);
}
void Show_enemy_win()
{
    enemy_t *enemy = Get_fight_enemy_info();
    btdy("-","【战斗失败！】");
    printf("\n%s:哈哈，想打败我，再去修炼几百年吧！",enemy->name);
    printf("\n\n勇士，失败是成功的妈妈，请继续努力！");
    printf("\n\n★按任意键回到家乡。");
}
