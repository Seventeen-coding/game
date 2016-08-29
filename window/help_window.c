#include "window/include/help_window.h"
char help_m[600]="本游戏十分简单，所有操作只需按选项之前的字母或者数字。作为一款文字游戏，本游戏没有华丽的图片和声音特效，只为交流编程技术，当你闯关完成后，将会获得本程序的源代码。注意，不要试图使用不正常方法通关哦！";

void Show_help_menu()//游戏帮助
{
    system("cls");//清屏
    ttdy(help_m,"【游戏帮助】",1,0,0,0);
}
