
#include "welcome_node.h"

game_node_t * welcome_node = NULL;


game_node_t * welcome_node_get()
{
    int ret;
    if(welcome_node == NULL)
    {
        ret = welcome_node_init();
        if(ret != RET_WELCOME_OK)   return NULL;
    }
    return welcome_node;
}

int welcome_node_init()
{
    /*这部分逻辑有点乱需要优化*/
    int ret;
    game_map_t *map;
    welcome_node = (game_node_t *)malloc(sizeof(game_node_t));
    if(welcome_node == NULL)    return RET_WELCOME_ERROR;

    /* map是随机的*/
    game_map_list_node_t*map_list_node = (game_map_list_node_t*) list_create(NULL);
    welcome_node->map_head = map_list_node;
    /*get map*/
    map  = welcome_map_get();
    map_list_node->data = map;
    map  = welcome_movie_map_get();
    list_insert_after(map_list_node, map);

    return RET_WELCOME_OK;
}
