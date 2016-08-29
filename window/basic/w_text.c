#include "w_text.h"
#include <stdlib.h>
#include <string.h>

static w_text_t * __init( window_t *);
static int __show();
static int __destory();
static int __select(char key);
static int __hide();
static int __msg(char msg);

//static int __set_text();


w_text_t * window_create_text(window_t *parent)
{
    window_t *window;
    w_text_t *text;
    window = __create_window(parent);
    text = __init(window);
    return (w_text_t *)text;
}

static w_text_t * __init(window_t *window)
{
   w_text_t * text = (w_text_t *)malloc(sizeof(w_text_t));
    text->window = window;
    text->window->this_window = &text;
    /*
    text->window->_destory = __destory;
    text->window->_show = __show;
    text->window->_hide = __hide;
    text->window->_select = __select;
    text->window->_msg = __msg;
    */
    return text;
}

static int __select(char key)
{
    return TEXT_NEXT;
}

static int __hide()
{


}

int     window_show_text(w_text_t*text)
{
        cursor_goto(text->window->__x,text->window->__y);
        printf("%s",text->data.text);
        return 0;
}

static int __msg(char msg)
{

    return 0;
}
static int __destory()
{

    return 0;
}

int    window_set_text(w_text_t*text, const char *src_text)
{
    text->data.len = strlen(src_text);
    if(text->data.text != NULL) free(text->data.text);
    text->data.text = (char *)malloc(text->data.len + 1);
    strcpy(text->data.text,src_text);

    return 0;
}
