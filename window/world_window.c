#include "window/include/world_window.h"


void Show_world_window()
{
    system("cls");//清屏
    btdy("-","【灭龙战场】");
    printf("\n");
    printf("\n\n\t[A]--叶龙岛        [B]--炎龙沙漠");
    printf("\n\n\t[C]--青龙仙宫      [D]--恶龙洞窟");
    printf("\n\n\t[E]--水晶宫        [F]--龙王殿");
    printf("\n\n\t[G]--超级魔龙殿    [Q]--回城");
}

void Show_world_place(int num)
{
    place_t *place = Get_place(num);
    btdy("-",place->name);
    printf("%s",place->info);
    gsdy("-",60);
    printf("\n按键展开进入和此怪的战斗！【Q】-返回地图");
    gsdy("-",60);
    int i ;
    int enemy_index = 0;
    enemy_t *enemy;
    list_node *enemy_list_head = place->enemy_list;
    while(enemy_list_head->next != NULL)
    {
        enemy_list_head = enemy_list_head->next;
        if(enemy_index%2==0)
            printf("\n\n");
        enemy = (enemy_t *)enemy_list_head->data;
        printf("\t[%d]--%s",++enemy_index,enemy->name);
    }
}
