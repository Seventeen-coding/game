
#include "welcome_story.h"

game_story_t *welcome_story = NULL;

int  welcome_story_init()
{
    game_node_t *node;
    node = welcome_node_get();
    if(node == NULL)   return RET_WELCOME_ERROR;
    /*有故事就开始创建表*/
    welcome_story = (game_story_t *)malloc(sizeof(game_story_t));
    welcome_story->node_head =  (game_story_list_node_t *)list_create(( game_node_t *)node);

    return  RET_WELCOME_OK;
}

game_story_t  *welcome_story_get()
{
    int ret;
    if(welcome_story  == NULL) {
        ret = welcome_story_init(welcome_story);
        if(ret != RET_WELCOME_OK)            return NULL;
    }
    return  welcome_story;
}
