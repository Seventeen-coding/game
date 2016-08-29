#include "window/include/window.h"

HANDLE hout;
//移动光标到指定位置
void cursor_goto(int x,int y)
{
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord; //屏幕上的坐标
    CONSOLE_SCREEN_BUFFER_INFO csbi; //控制台屏幕缓冲区信息
    GetConsoleScreenBufferInfo(hout,&csbi);
    coord.X=csbi.dwCursorPosition.X; //得到坐标X的值
    coord.Y=csbi.dwCursorPosition.Y; //得到坐标Y的值
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hout,coord);

}

void btdy(char btfh[],char bttitle[])//标题打印函数
{
    system("cls");
    int pn;
    printf("\n");
    for(pn=0;pn<25;pn++)
        printf(" ");
    printf("%s",bttitle);
    printf("\n");
    for(pn=0;pn<60;pn++)
        printf("%s",btfh);
    printf("\n");
}



void ttdy(char main_t[],char m_title[],int clspa,int clspb,int timep,int ptime)//动态打印函数，通用！ 打印主体、标题、清屏确认（clspa=1显示前清屏，clspb=1显示后清屏,播放速度，播完暂停时间
{
    if(clspa==1)
    {system("cls");}
    int len,pn;
    len=strlen(main_t);
    for(pn=0;pn<15;pn++)
        printf(" ");
    printf("%s\n",m_title);
    for(pn=0;pn<len;pn++)
    {
        if(pn%40==0)
            printf("\n\n");
        printf("%c",main_t[pn]);
        //Sleep(timep);
    }
    if(clspb==1)
    {system("cls");}
    //Sleep(ptime);
}

void sttdy(char stt[],int timep,int ptime)//单一打印函数
{
    int pn,len;
    len=strlen(stt);
    for(pn=0;pn<len;pn++)
    {
        if(pn%40==0)
            printf(" ");
        printf("%c",stt[pn]);
        //Sleep(timep);

    }
    //Sleep(ptime);
}

void skdy(char skt[])//技能说明无损打印
{
    int pn,len;
    len=strlen(skt);
    printf("   ");
    for(pn=0;pn<len;pn++)
    {
        printf("%c",skt[pn]);
    }

}

void gsdy(char gst[],int len)//打印间隔条
{
    int pn;
    printf("\n");
    for(pn=0;pn<len;pn++)
        printf("%s",gst);
}


void errdy(char etext[],char e_title[],char e_class[],int clsup)//错误反馈
{
    int pn=0,len;
    system("color c0");
    if(clsup==1)
    {system("cls");}
    printf("\n\n\a");
    for(pn=0;pn<20;pn++)
        printf(" ");
    printf("%s\n",e_title);
    for(pn=0;pn<50;pn++)
        printf("*");
    printf("\n\n【错误等级】：%s\n\n",e_class);
    printf("【错误原因】：\n ");
    len=strlen(etext);
    for(pn=0;pn<=len;pn++)
    {
        if(pn%41==0)
            printf("\n");
        printf("%c",etext[pn]);
    }
    getch();
}

