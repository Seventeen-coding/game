
#include "data/include/enemy_data.h"

enemy_t enemy[200]={
    {"灼热龙蛋","呜呜。。呜呜。离我远一点！",1,5,5,0,30,30,10,10,12,3,1,1,1,0},
    {"一岁幼龙","你是谁啊？想干嘛？不要过来！嗷",2,10,2,15,100,100,30,30,12,8,1,0,1,0},
    {"三岁幼龙","我的奶瓶！",3,13,18,3,200,200,50,50,20,12,1,0,0,0},
    {"五岁幼龙","就是你抢走了我弟弟的奶瓶？",5,16,20,5,300,300,70,70,25,20,1,1,0,1},//4
    {"小龙盖茨","听说你打败了我的弟弟！受死吧！",7,23,25,6,380,380,80,80,35,28,1,1,1,0},
    {"小龙比尔","我叫比尔，比尔盖茨的比尔。",9,26,30,9,430,430,89,89,40,35,1,1,1,0},
    {"小龙乔布","乔布斯？？不不，我是乔布。",12,35,40,11,500,500,95,95,50,40,1,1,1,0},
    {"变异怪龙","为什这么看我？我和其他龙不一样吗？",15,50,50,15,800,800,100,100,100,80,1,1,1,0},//8
    {"青龙甲","我是甲！",17,60,60,17,700,700,110,110,80,80,1,0,0,0},
    {"青龙乙","我是乙！",19,65,65,18,750,750,110,110,85,80,1,1,0,0},
    {"青龙丙","我是丙！",20,70,65,19,800,800,110,110,95,90,1,1,1,0},
    {"青龙丁","我当然是丁喽！",24,90,80,20,1000,1000,110,110,120,100,1,1,1,1},//12
    {"恶龙A","我很善良！",25,75,75,22,850,850,120,120,100,100,1,1,0,0},
    {"恶龙B","我本善良！",26,80,80,22,900,900,120,120,105,105,1,1,1,0},
    {"恶龙C","我最善良！",27,90,90,23,1100,1100,130,130,150,150,1,1,1,0},
    {"恶龙D","我就是恶龙了，想咋滴？？",30,100,100,25,1500,1500,140,140,300,150,1,1,1,1},//16
    {"东海龙网","我是龙王！",31,105,105,26,1150,1150,130,130,200,160,1,1,1,0},
    {"西海龙网","我是龙王！",32,110,110,27,1200,1200,130,130,210,180,1,1,1,0},
    {"南海龙网","我是龙王！",33,115,115,28,1290,1290,135,135,230,200,1,0,0,0},
    {"北海龙网","我是龙王！",35,160,180,30,1800,1800,150,150,600,300,1,1,1,1},//20
    {"东海龙王","我不是龙网！",36,120,120,30,1300,1300,140,140,300,250,1,0,0,0},
    {"西海龙王","我不是龙网！",37,125,125,32,1400,1400,150,150,350,300,1,0,1,0},
    {"南海龙王","我不是龙网！",39,140,140,33,1600,1600,170,170,420,350,1,1,1,0},
    {"北海龙王","我不是龙网！",45,200,200,36,2500,2500,200,200,1000,600,1,1,1,1},//24
    {"魔龙守卫","啊，是人类啊，好久没吃到人类了！",46,150,150,34,1700,1700,180,180,450,400,1,0,0,0},
    {"魔卫统领","我的手下被你干掉了？？",47,160,160,35,1800,1800,190,190,500,500,1,1,1,0},
    {"魔龙小弟","你找我大哥有什么事情啊？",48,180,180,36,2000,2000,200,200,550,550,1,1,1,1},
    {"超级魔龙","呜呜。。呜呜。离我远一点！你这混蛋！",50,500,500,50,5000,5000,300,300,3000,2000,1,1,1,1},//28
};//怪物定义:名称，交流，等级，攻击，防御，速度，血，最大血，魔，最大魔，携带经验，携带金币，随机奖励药品（1有），随机武器，随机奇宝，允许逃跑（1不允许)

enemy_t *enemy_list[8][4];      // ->> 可用可不用
enemy_t current_enemy;

enemy_t*Get_enemy(int num)
{
    return &enemy[num];
}

void Set_fight_enemy(int num)
{
    int i = 0 ;
    place_t *current_place = Get_current_place();
    list_node *node =  current_place->enemy_list;
    while(i++ != num && node->next != NULL)
    {
        node  = node->next;
    }
    memcpy(&current_enemy , node->data,sizeof(enemy_t));
}
void Init_place_enemy(list_node *place_enemy_list,int num)
{
    enemy_t *list [8][4] ={
        {&enemy[0],&enemy[1],&enemy[2],&enemy[3]},
        {&enemy[4],&enemy[5],&enemy[6],&enemy[7]},
        {&enemy[8],&enemy[9],&enemy[10],&enemy[11]},
        {&enemy[12],&enemy[13],&enemy[14],&enemy[15]},
        {&enemy[16],&enemy[17],&enemy[18],&enemy[19]},
        {&enemy[20],&enemy[21],&enemy[22],&enemy[23]},
        {&enemy[24],&enemy[25],&enemy[26],&enemy[27]}
    };
    memcpy(enemy_list,list,sizeof(enemy_t *) * 8 * 4);
    list_insert_end(place_enemy_list,list[num][0]);
    list_insert_end(place_enemy_list,list[num][1]);
    list_insert_end(place_enemy_list,list[num][2]);
    list_insert_end(place_enemy_list,list[num][3]);
}


enemy_t * Get_fight_enemy_info()
{
    return &current_enemy;
}


