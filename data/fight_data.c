#include "data/include/fight_data.h"
fight_result_t *result;
fight_result_t *Get_fight_result()
{
    return result;
}

void Fight_init(int num)
{
    if(result != NULL)  free(result);
    Set_fight_enemy(num);
    result = malloc(sizeof(fight_result_t));
    result->hero_attack = 0;
    result->enemy_attack = 0;
    result->result = NOBOBY_WIN;
}

void fight_with_attack(hero_t *hero,enemy_t *enemy)
{
    //没有做攻击算法看不懂
    result->hero_attack = hero->ATK ;
    result->enemy_attack = enemy->ATK;
    if((enemy->HP = enemy->HP - hero->ATK) <= 0)
        result->result = HERO_WIN;
    if((hero->HP = hero->HP - enemy->ATK) <= 0)
        result->result = ENEMY_WIN;
    //    getgj=lgj*(rand()%gplay[c_play].gj+1);
    //    getggj=lggj*(rand()%ggw[bhao].gj+1);
    //    here_ghp-=getgj;
    //    gplay[c_play].hp-=getggj;
}

void fight_with_skill(hero_t *hero,enemy_t *enemy)
{


}

int Check_up_result()
{
    if(Get_finally_winner() == NOBOBY_WIN)  return -1;
    return 0;
}

char Get_finally_winner()
{
    return result->result;
}
