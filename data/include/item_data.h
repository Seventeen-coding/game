#ifndef ITEM_DATA_H
#define ITEM_DATA_H

typedef struct {
    char name[30];  //物品名
    char pinzhi[20]; //品质
    int zyk;    //作用值，，
    int jhp;    //加血
    int jmp;    //加魔
    int jgj;    //加攻击
    int jfy;    //加防御
    int jspeed; //加速度
    int jluck;  //加幸运
    int mgold;  //价格
    int nbag;   //占用包裹
    int jbaoj;  //加暴击 ，。
    int haved;  //拥有量
    int mhave;  //最大拥有
    int cbuy;   //（1可买，0不可）
    int cshop;  //可卖（1可）
}item_t;
item_t *Get_item(int num);
item_t *Get_item_list();

#endif // ITEM_DATA_H

