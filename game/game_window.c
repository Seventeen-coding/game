

#include "game/game_window.h"
#include "game/game_window_type.h"
#include "list/list.h"  //如果需要更好兼容性 那就自己创建一个 game_list 去代替这个list

typedef list_node  __window_tpye_list_t  ;

struct{
    __window_tpye_list_t  window_type_list;
}__window_core__;

window_t * __create_window(window_t *parent)
{
    window_t * window = __get_window__();
    __w_init__(parent,window);     //这里想像的是通用的初始化
    return  window;
}

int  __w_init__(window_t *parent, window_t * window )
{
    window->parent = parent;
    /*如果是画图就需要用plant*/
    window_set_position(window,0,0);
}

/*destory 的话 没什么好做的 因为我们初始化的东西就不想把他们删除
    除非是大型游戏 ^-^
    一般来说加了 __前缀就不应该修改他们了
*/
int    __w_destory__(void)
{

}

int window_set_position(window_t * window ,int x,int y)
{
    window->__x = x;
    window->__y = y;
    return 0;
}

