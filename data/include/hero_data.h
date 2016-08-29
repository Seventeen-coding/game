#ifndef HERO_DATA_H
#define HERO_DATA_H
#include "data/include/base_data.h"
#include <stdlib.h>
typedef struct{
    char name[20];  //角色名
    //base_t base;
    int level;              //等级
    int ATK;                //攻击
    int DEF;                //防御
    int SPE;                //速度
    int LUC;                //幸运
    int GOLD;           //金币
    int yesp;               //存在判断（ 若yesp=99则判定用户已存在），
    int EXP;                //经验
    int UP_GRADE;   //升级经验
    int HP;                    //血量和魔法值
    int HP_Max;
    int MP;
    int MP_Max;
}hero_t;


hero_t *hero_init(char name[20],int level,int ATK,int DEF,int SPE,int LUC,int GOLD,int yesp,int EXP,int UP_GRADE,int HP,int HP_Max,int MP,int MP_Max);
hero_t *Get_current_hero_info();

void hero_sleep();
void hero_upgrade();
int Check_up_up_grade();
int Set_hero_name(char *name);
int Set_hero_ATK(int ATK);
int Set_hero_DEF(int DEF);
int Set_hero_SPE(int SPE);
int Set_hero_LUC(int LUC);
int Set_hero_EXP(int EXP);
int Set_hero_GOLD(int GOLD);

#endif // HERO_DATA_H

