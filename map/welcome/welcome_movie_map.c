#include "welcome_movie_map.h"
#include "game/game_goble.h"
#include "game/game_debug.h"

game_map_t *map ;
int welcome_movie_map_handle(void);
int welcome_movie_map_show(void);
int welcome_movie_map_select(char key);

game_map_t * welcome_movie_map_get()
{
    if(map > 0)         return map;
    welcome_movie_map_init(map);
    return map;
}

int welcome_movie_map_init()
{
    if(map > 0) {
        return &map;
    }
    map  = (game_map_t * )malloc(sizeof(game_map_t));
    map->_init = welcome_movie_map_init;
    map->_show = welcome_movie_map_show;
    map->_select = welcome_movie_map_select;
    return 0;   //INIT_OK
}
//int welcome_handle(void)
//{

//}

int welcome_movie_map_show(void)
{
    GAME_BASE_DEBUG("welcome_movie_show\r\n");
    Show_main_dh();
}

int welcome_movie_map_select(char key)
{
    GAME_BASE_DEBUG("welcome_movie_select : %c\r\n",key);
    if(key == '1')      {
        return GAME_MAP_FINISH;
    }
    return GAME_RUNNING;
}
