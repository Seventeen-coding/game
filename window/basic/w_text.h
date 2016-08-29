#ifndef  WINDOW_TEXT_H_
#define WINDOW_TEXT_H_

#include "game/game_window.h"

typedef enum{
    TEXT_NEXT,
    TEXT_END
}text_control_t;

typedef int (*w_text_set_text)(const char *text);

typedef struct {
    char *text;
    int  index;
    int  len;
}w_text_data_t;

typedef struct {
    w_text_set_text set_text;
}w_text_function_t;

typedef struct{
    window_t *window;
    w_text_data_t   data;
    //function
   // w_text_set_text set_text;

}w_text_t;

w_text_t *window_create_text(window_t *parent);
int     window_set_text(w_text_t*text,const char *src_text);
int     window_show_text(w_text_t*text);

#endif //WINDOW_TEXT_H_
