/*灭龙传说文字版  V2016/6/27  By Seventeen  */
/*重构版 2016/8/17    By Seventeen                       */

#include "main.h"
#include "window/include/window.h"


int main (int argc, char *argv[])
{

    //init_game_env();/*这里运行的是游戏外部无关的设置 如窗口大小 光标 字体颜色等 思维: 以“游戏” 为思想去设计这个接口 */
    do{
        game_start();
        //        return 0;         //coding  start
        if(game_status_get() == GAME_TEST)
        {
            game_test_run();           //每开发一个模块在test模块独立运行 大大提高开发效率
            continue;
        }
        game_run();
        game_end();
    }while(0);//game_status_get() != GAME_EXIT );
    return 0;
}


