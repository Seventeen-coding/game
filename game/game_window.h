#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "window/include/window.h"

typedef  int (*w_msg_handle)(char);
typedef  int (* w_init_handle)(void);
typedef  int (*w_show_handle)(void);
typedef  int (*w_hide_handle)(void);
typedef  int (*w_select_handle)(char );
typedef  int (*w_destory_handle)( );


typedef struct{
    w_msg_handle      _msg;
    w_show_handle   _show;
    w_select_handle  _select;
    w_hide_handle     _hide;
}game_window_function_t;

typedef struct{
    w_init_handle       _init;
    w_destory_handle    _destory;
}game_window_base_t;


typedef struct{
    struct game_window_t *parent;
    char * type;
    int         __x;
    int         __y;
    void         *data;     /*根据不同的window存不同的data*/
}game_window_data_t;

typedef struct window_t{
    void *this_window;
    //game_window_base_t  *base;
    //w_init_handle       _init;
    w_destory_handle    _destory;

    // game_window_function_t  *function;
    w_msg_handle     _msg;
    w_show_handle   _show;
    w_select_handle  _select;
    w_hide_handle     _hide;

    //game_window_data_t  data;
    struct window_t *parent;
   // char * type;
    int         __x;
    int         __y;
    //void         *data;     /*根据不同的window存不同的data*/
}window_t;

window_t * __create_window(window_t *parent);
int game_focus_window(window_t *window);
int window_set_position(window_t * window ,int x,int y);

#endif // GAME_WINDOW_H

