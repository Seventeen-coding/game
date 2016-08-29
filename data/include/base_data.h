#ifndef BASE_DATA_H
#define BASE_DATA_H

typedef struct{
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
}base_t;


#endif // BASE_DATA_H

