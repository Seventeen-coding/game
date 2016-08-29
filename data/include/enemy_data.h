#ifndef ENEMY_DATA_H
#define ENEMY_DATA_H
#include "data/include/base_data.h"
#include "data/include/place_data.h"

typedef struct {
    char name[30];
    char talk[200];
    int level;
    int ATK;
    int DEF;
    int SPE;
    int HP;
    int HP_Max;
    int MP;
    int MP_Max;
    int EXP;
    int GOLD;
    int hyp;
    int hwp;
    int hqb;
    int allow_run;
}enemy_t;
//怪物结构：名称，交流，等级，攻击，防御，速度，血，最大血，魔，最大魔，携带经验，携带金币，随机奖励药品（1有），随机武器，随机奇宝，允许逃跑（1允许）


enemy_t*Get_enemy(int num);
void Set_fight_enemy(int num);
enemy_t * Get_fight_enemy_info();
void Init_place_enemy(list_node *place_enemy_list,int num);

#endif // ENEMY_DATA_H

