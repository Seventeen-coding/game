#include "data/include/hero_data.h"
hero_t *player;
hero_t *hero_init(char *name,int level,int ATK,int DEF,int SPE,int LUC,int GOLD,int yesp,int EXP,int UP_GRADE,int HP,int HP_Max,int MP,int MP_Max)
{
    hero_t *hero_p = malloc(sizeof(hero_t));
    if(hero_p == NULL)  return NULL;
    if(name != NULL)
        strcpy(hero_p->name,name);
    hero_p->level = level;
    hero_p->ATK = ATK;
    hero_p->DEF = DEF;
    hero_p->SPE = SPE;
    hero_p->LUC = LUC;
    hero_p->GOLD = GOLD;
    hero_p->EXP = EXP;
    hero_p->UP_GRADE =  UP_GRADE; //这里搞一个算法算等级拉
    hero_p->HP_Max = HP_Max;
    hero_p->HP = HP;
    hero_p->MP_Max = MP_Max;
    hero_p->MP = MP;
    if(player != NULL) free(player);
    player = hero_p;
    return player;
}

hero_t *Get_current_hero_info()//角色信息查看
{
    return player;
}

int Set_hero_name(char *name)
{
    if(name == NULL)    return -1;
    strcpy(player->name,name);
    return 0;
}
int Set_hero_EXP(int EXP)
{
    player->EXP = EXP;
    return 0;
}
int Set_hero_GOLD(int GOLD)
{
    player->GOLD = GOLD;
    return 0;
}

int Set_hero_ATK(int ATK)
{
    player->ATK = ATK;
    return 0;
}

int Set_hero_DEF(int DEF)
{
    player->DEF = DEF;
    return 0;
}

int Set_hero_SPE(int SPE)
{
    player->SPE = SPE;
    return 0;
}

int Set_hero_LUC(int LUC)
{
    player->LUC = LUC;
    return 0;
}

void hero_sleep()
{
    player->HP  =   player->HP_Max;
    player->MP =   player->MP_Max ;
}
void hero_upgrade()
{
    player->level += 1;
    player->EXP = 0;
    player->UP_GRADE = player->level*100;
    player->ATK +=5;
    player->DEF +=4;
    player->SPE +=2;
    player->LUC +=1;
    player->HP_Max = player->level*100;
    player->MP_Max = player->level*50;
}

int   Check_up_up_grade()
{
    if(player->UP_GRADE > player->EXP )  {
        return -1;
    }
    return 0 ;
}

