
#include "welcome_map.h"
#include "game/game_goble.h"
#include "game/game_debug.h"
#include "window/basic/w_text.h"

struct{
    game_map_t *map;
    //window
    w_text_t*   text;
    w_text_t*   text1;
    w_text_t*   text2;
}welcome_map;

int welcome_map_handle(void);
int welcome_map_show(void);
int welcome_map_select(char key);
int welcome_map_init();

game_map_t * welcome_map_get()
{
    if(welcome_map.map > 0)         return welcome_map.map;
    welcome_map_init();
    return welcome_map.map;
}

int welcome_map_init()
{
    if(welcome_map.map > 0) {
        return -1;
    }
    welcome_map.map  = (game_map_t * )malloc(sizeof(game_map_t));
    welcome_map.map->_init = welcome_map_init;
    welcome_map.map->_show = welcome_map_show;
    welcome_map.map->_select = welcome_map_select;

    welcome_map.text = window_create_text(NULL);
    window_set_text(welcome_map.text,"helloworld 1 2 3 4 5 6 7 \r\n");
    window_set_position(welcome_map.text->window,10,10);

    welcome_map.text1 = window_create_text(NULL);
    window_set_text(welcome_map.text1,"helloworld 1  \r\n");
    window_set_position(welcome_map.text1->window,2,2);

    welcome_map.text2 = window_create_text(NULL);
    window_set_text(welcome_map.text2,"helloworld 2 \r\n");
    window_set_position(welcome_map.text2->window,3,3);

    return 0;   //INIT_OK
}
//int welcome_handle(void)
//{

//}

int welcome_map_show(void)
{
    GAME_BASE_DEBUG("welcome_show\r\n");
    window_show_text(welcome_map.text);
    window_show_text(welcome_map.text1);
    window_show_text(welcome_map.text2);
}

int welcome_map_select(char key)
{
    GAME_BASE_DEBUG("welcome_select : %c\r\n",key);
    if(key == '1') return GAME_MAP_FINISH;  //for test
    return GAME_RUNNING;
}
