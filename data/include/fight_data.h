#ifndef FIGHT_DATA_H
#define FIGHT_DATA_H
#include "data/include/hero_data.h"
#include "data/include/enemy_data.h"
#include "data/include/place_data.h"

#define HERO_WIN        'h'
#define ENEMY_WIN     'e'
#define NOBOBY_WIN  'n'

typedef struct {
    int hero_attack;
    int enemy_attack;
    char result;
}fight_result_t;

void Fight_init(int num);
void fight_with_attack(hero_t *hero,enemy_t *enemy);
void fight_with_skill(hero_t *hero,enemy_t *enemy);
int Check_up_result();
char Get_finally_winner();
fight_result_t * Get_fight_result();
#endif // FIGHT_DATA_H

