
#include "main.h"
int shop_n,spn_a,spn_b,spn_c,spn_n,spback_n; //商店种类判断参数
int wpinfo_n,wpback_n=0,wp_run_n;//信息界面显示菜单值，1显示使用，2显示购买
int sp_a[10],sp_b[10],sp_c[10];//列表具体物品判定
int sk_n,skback_n=0,skill_n=0;  //技能参数，返回值（0返回人物信息，1返回战斗），
int pkmenu_n=0,here_ghp,pkstart=0;//PK菜单显示判断，0则显示返回，1则不能再返回。
int getgj,getfy,getspeed,getsk,gethp;
int lgj=1,lfy=1,lspeed=1;//因技能产生的临时倍率
int lggj=1,lgfy=1,lgspeed=1;//因技能产生的怪物临时倍率
int getggj,getgfy,getgspeed,getgsk,getghp;//战斗必须参数
int cityk_n;//城市返回全局参数
int dat_back=0;//返回何处读档
int upcheck_k=0; //升级奖励不重复
int shop_back=0;//商店返回

char main_t[700]="自古就有想要屠龙的勇士，世间也流传着无数屠龙的传说！毫无疑问，能够成为屠龙之人，必定能够名动天下，流传千古。而《灭龙传说》的故事，就开始于屠龙，开始于你。。。";
char main_t_title[30]="《灭龙传说》游戏序V1.5";
int main_pd=1,welcome_n=1;//开场动画播放判定



void datdell()
{
    /*
    cls;
    system("color 30");
    btdy("-","【档案管理】");
    printf("\n请选择菜单进行档案操作！");
    printf("\n\n\nS--存储档案");
    printf("\tR--读取档案");
    printf("\n\n   Q--返回主菜单");
    while(1)
    {
        char ch;
        ch=getch();
        if(ch=='s'||ch=='S')
            save_dat();
        if(ch=='r'||ch=='R')
            //		read_dat();
            if(ch=='q'||ch=='Q')
                menuf();
    }
    datdell();

*/
}







void pkwin(int bhao)  //战斗胜利 
{
    /*
    int rand_pk;
    int pn_yp,pn_wq,pn_qb;
    int pna,pnb,pnc,pn_a=0,pn_b=0,pn_c=0;
    int pn[10];
    btdy("-","【战斗胜利！】");
    printf("\n你战胜了 %s",ggw[bhao].name);
    printf("\n【战果】:");
    printf("\n获得经验:%d",ggw[bhao].hexp);
    printf("\n获得金币:%d",ggw[bhao].hgold);
    rand_pk=rand()%8+1;
    if(rand_pk==1)//随机可能获得奖励
 {
    if(ggw[bhao].hyp==1)
    {
        for(pna=0;pna<200;pna++)
          if(gwp[pna].zyk==1)
          {
            pn[pn_a]=pnc;
            pn_a++;
          }
          pn_yp=rand()%pn_a+1;
          gwp[pn_yp].haved+=1;
          printf("\n获得：%s*1",gwp[pn_yp].name);
    }
    if(ggw[bhao].hwp==1)
    {
        for(pnb=0;pnb<200;pnb++)
          if(gwp[pnb].zyk==2)
          {
            pn[pn_b]=pnc;
            pn_b++;
          }
          pn_wq=rand()%pn_b+1;
          gwp[pn_wq].haved+=1;
          printf("\n获得：%s*1",gwp[pn_wq].name);
    }
    if(ggw[bhao].hqb==1)
    {
        for(pnc=0;pnc<200;pnc++)
          if(gwp[pnc].zyk==3)
          {
            pn[pn_c]=pnc;
            pn_c++;
          }
          pn_qb=rand()%pn_c+1;
          gwp[pn_qb].haved+=1;
          printf("\n获得：%s*1",gwp[pn_qb].name);
    }
 }

    getch();
    gplay[c_play].exp+=ggw[bhao].hexp;
    gplay[c_play].gold+=ggw[bhao].hgold;
    upcheck();
    */

}



void pklost(int bhao)//战斗失败 
{
    btdy("-","【战斗失败！】");
    printf("\n%s:哈哈，想打败我，再去修炼几百年吧！",ggw[bhao].name);
    printf("\n\n勇士，失败是成功的妈妈，请继续努力！");
    printf("\n\n★按任意键回到家乡。");
    getch();
}

void gwinfo(int bhao)//怪物信息查看 
{
    btdy("-","【怪物信息查看】");
    printf("\n\n名称:%s",ggw[bhao].name);
    printf("\n等级:%d",ggw[bhao].dj);
    printf("\n攻击力:%d",ggw[bhao].gj);
    printf("\n防御力:%d",ggw[bhao].fy);
    printf("\n速度  :%d",ggw[bhao].speed);
    printf("\n血量  :%d",ggw[bhao].hp);
    printf("\n魔力值:%d",ggw[bhao].mp);
    printf("\n经验值:%d",ggw[bhao].hexp);
    printf("\n金币  :%d",ggw[bhao].hgold);
    if(ggw[bhao].allow_run==1)
        printf("\n【特殊】：不允许逃跑！");
    printf("\n可能掉落：");
    if(ggw[bhao].hyp==1)
        printf("\n\t【药品】");
    if(ggw[bhao].hwp==1)
        printf("\n\t【武器】");
    if(ggw[bhao].hqb==1)
        printf("\n\t【奇宝】");
    printf("\n任意键返回战斗界面。");
    getch();

}



void skill()//技能 
{
    /*
    int pn=0;
    char ch;
    cls;
    btdy("-","【技能】");
    printf("\n★按相应数字键将显示详细，【Q】键返回上页★");
    gsdy("-",60);
    printf("\n\n按键 | 技能名称| 需要MP|可学等级|说明               |其他");
    gsdy("-",60);
    for(pn=0;pn<9;pn++)
    {
    printf("\n[%d]---%s\t%d\t%d级   %.16s...",pn+1,gskill[pn].name,gskill[pn].nmp,gskill[pn].ndj,gskill[pn].info);
    if(gplay[c_play].dj>=gskill[pn].ndj)
    printf(" ★已学会");
    }
while(1)
{
    ch=getch();
    if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9')
      {
        sk_n=ch-49;
        skillinfo(sk_n);
      }
    if(ch=='q'||ch=='Q')
      {
      if(skback_n==0)
      peoinfo();
      if(skback_n==1)
      pkload(wp_run_n);
      }

}
skill();
*/
}


void skillinfo(int bhao)//技能信息查看和释放，支持判断极限和魔法值扣除。 
{
    /*
    cls;
    char ch;
    btdy("-","【技能详细】");
    printf("\n");
    printf("\n%s",gskill[bhao].name);
    if(gskill[bhao].ndj<=gplay[c_play].dj)
        printf("  【已学会】\n\n");
    else
        printf("   【未掌握】\n\n");
    skdy(gskill[bhao].info);
    printf("\n\n作用：\n");
    if(gskill[bhao].jhp>0)
        printf("\n\tHP+%d",gskill[bhao].jhp);
    if(gskill[bhao].jgj>0)
        printf("\n\t攻击+%d倍",gskill[bhao].jgj);
    if(gskill[bhao].jfy>0)
        printf("\n\t防御+%d倍",gskill[bhao].jfy);
    if(gskill[bhao].jspeed>0)
        printf("\n\t速度+%d倍",gskill[bhao].jspeed);
    if(gskill[bhao].jluck>0)
        printf("\n\t幸运+%d倍",gskill[bhao].jluck);
    if(skill_n==1)
        printf("\n\nY--释放       N--返回战斗");
    if(skill_n==0)
        printf("\n\n【Q】--返回技能菜单");
    while(1)
    {
        ch=getch();
        if(ch=='y'&&skill_n==1||ch=='Y'&&skill_n==1)
        {
            if(gskill[bhao].ndj<=gplay[c_play].dj&&gskill[bhao].jhp<=0)
            {
                if(gplay[c_play].mp-gskill[bhao].nmp<0)
                {
                    printf("\n【魔法值不足！】");
                    getch();
                    skill();
                }
                lgj=gskill[bhao].jgj;
                lfy=gskill[bhao].jfy;
                lspeed=gskill[bhao].jspeed;
                gplay[c_play].mp-=gskill[bhao].nmp;
                pkstart=1;
                printf("\n【%s】释放成功！",gskill[bhao].name);
                getch();
                pkload(wp_run_n);
            }
            if(gskill[bhao].ndj<=gplay[c_play].dj&&gskill[bhao].jhp>0)
            {
                if(gplay[c_play].mp-gskill[bhao].nmp<0)
                {
                    printf("\n【魔法值不足！】");
                    getch();
                    skill();
                }
                if((gplay[c_play].hp+gskill[bhao].jhp)>(gplay[c_play].hpmax+20))
                {
                    printf("\n【血量足够，无需添加】");
                    getch();
                    skill();
                }
                lgj=gskill[bhao].jgj;
                lfy=gskill[bhao].jfy;
                lspeed=gskill[bhao].jspeed;
                gplay[c_play].hp+=gskill[bhao].jhp;
                gplay[c_play].mp-=gskill[bhao].nmp;
                printf("\n【%s】释放成功！",gskill[bhao].name);
                getch();
                pkload(wp_run_n);


            }
            else
            {
                printf("\n【等级不足，此技能您还不能释放！】");
                getch();
                skill();
            }

        }
        if(ch=='n'&&skill_n==1||ch=='N'&&skill_n==1)
            pkload(wp_run_n);
        if(ch=='q'&&skill_n==0||ch=='Q'&&skill_n==0)
            skill();



    }
*/
}



void usewp(int bhao)//使用物品 
{
    /*
    btdy("=","【使用物品】");
    printf("\n%s",gwp[bhao].name);
    printf("使用成功！");
    printf("\n\n获得效果：");
    if(gwp[bhao].jhp>0)
    {
        /*                                                                 //暂时不做检查
      if((gplay[c_play].hp+gwp[bhao].jhp)>gplay[c_play].hpmax)
      {
        printf("\n血量足够，无需添加！");
        getch();
        wpinfo(bhao);
      }
      */
/*
        gplay[c_play].hp+=gwp[bhao].jhp;
        printf("HP+%d",gwp[bhao].jhp);
    }
    if(gwp[bhao].jmp>0)
    {gplay[c_play].mp+=gwp[bhao].jmp;
        printf("  MP+%d",gwp[bhao].jmp);}
    if(gwp[bhao].jgj>0)
    {gplay[c_play].gj+=gwp[bhao].jgj;
        printf("  攻击+%d",gwp[bhao].jgj);}
    if(gwp[bhao].jfy>0)
    {gplay[c_play].fy+=gwp[bhao].jfy;
        printf("  防御+%d",gwp[bhao].jfy);}
    if(gwp[bhao].jspeed>0)
    {gplay[c_play].speed+=gwp[bhao].jspeed;
        printf("  速度+%d",gwp[bhao].jspeed);}
    if(gwp[bhao].jluck>0)
    {gplay[c_play].luck+=gwp[bhao].jluck;
        printf("  幸运+%d",gwp[bhao].jluck);}

    gwp[bhao].haved-=1;
    getch();
    if(gwp[bhao].haved<1)
        wupin();
    wpinfo(bhao);

*/
}



void wpinfo(int bhao)//物品信息查看，接受物品编号 
{
    /*
    int pn;
    char ch;
    btdy("-","【物品信息】");
    printf("\n名称：%s",gwp[bhao].name);
    if(gwp[bhao].cshop!=1)
        printf("（不可出售）");
    printf("\n\n品质：%s",gwp[bhao].pinzhi);
    printf("\n价格：%d金币     拥有：%d 个",gwp[bhao].mgold,gwp[bhao].haved);
    printf("\n作用：");
    if(gwp[bhao].jhp>1)
        printf("\n\n\tHP+%d",gwp[bhao].jhp);
    if(gwp[bhao].jmp>1)
        printf("\n\tMP+%d",gwp[bhao].jmp);
    if(gwp[bhao].jgj>1)
        printf("\n\t攻击+%d",gwp[bhao].jgj);
    if(gwp[bhao].jfy>1)
        printf("\n\t防御+%d",gwp[bhao].jfy);
    if(gwp[bhao].jspeed>1)
        printf("\n\t速度+%d",gwp[bhao].jspeed);
    if(gwp[bhao].jluck>1)
        printf("\n\t幸运+%d",gwp[bhao].jluck);
    if(gwp[bhao].jbaoj>1)
        printf("\n\t暴击+%d",gwp[bhao].jbaoj);
    printf("\n\n\t*占用包裹：%d格",gwp[bhao].nbag);
    if(wpinfo_n==1)
        printf("\n\n\t[B]--购买   [Q]--返回商店");
    if(wpinfo_n==2)
        printf("\n\n\t[K]--使用   [P]--出售      [Q]--返回物品");
    while(1)
    {
        ch=getch();
        if(ch=='b'||ch=='B')
            buywp(bhao);
        if(ch=='q'||ch=='Q')
        {
            if(spback_n==1)
                shopc();
            if(spback_n==2)
                peoinfo();
            if(spback_n==3)
                wupin();
        }
        if(ch=='k'||ch=='K')
            usewp(bhao);
        if(ch=='p'||ch=='P')
        { if(gwp[bhao].cshop!=1)
            {
                printf("\n\n\t【警告】该物品无法出售！");
                getch();
                wpinfo(bhao);
            }
            pwp(bhao);
        }
    }
*/
}

void pwp(int bhao)//出售物品 
{
    /*
    int pn,n=0;
    char ch;

    while(1)
    {
        cls;
        btdy("-","出售确认");
        printf("\n请按键确定出售个数，当前拥有：%d（个）！):",gwp[bhao].haved);
        printf("\n\n[W]--↑  [S]--↓  [空格键]--确认出售   [Q]--返回");
        printf("\n\n当前准备出售：%d  个",n);
        ch=getch();
        if(ch=='w')
        {
            if(n>gwp[bhao].haved-1)
            {
                printf("\n已到达最大值!");
                getch();
            }
            else
                n=n+1;
        }
        if(ch=='s')
        {
            if(n<1)
            {
                printf("\n已达到最小值！");
                getch();
            }
            else
                n=n-1;
        }
        if(ch==' ')
            break;
        if(ch=='q')
            wpinfo(bhao);
    }
    printf("\n你确认要出售%d个%s?可获得%d金币",n,gwp[bhao].name,n*gwp[bhao].mgold);
    printf("\n\n[Y]-确认   [N]-放弃");
    while(1)
    {
        ch=getch();
        if(ch=='y'||ch=='Y')
        {
            gwp[bhao].haved-=(n);
            gplay[c_play].gold+=n*gwp[bhao].mgold;
            printf("\n出售成功！");
            getch();
            wupin();
        }
        if(ch=='n'||ch=='N')
            wpinfo(bhao);
    }
*/
}


void buywp(int bhao)// 物品购买判定，接受物品编号参数 
{
    /*
    int n=0,pn;
    char ch;
    while(1)
    {
        cls;
        btdy("-","购买物品");
        printf("\n少侠，你现在拥有金币： %d 个 ",gplay[c_play].gold);
        printf("\n【%s】 标价 %d /个",gwp[bhao].name,gwp[bhao].mgold);
        printf("\n\n[W]--↑  [S]--↓  [空格键]--确认购买   [Q]--返回");
        printf("\n\n当前准备购买：%d  个",n);
        ch=getch();
        if(ch=='w')
        {
            n=n+1;
        }
        if(ch=='s')
        {
            if(n<1)
            {
                printf("\n已达到最小值！");
                getch();
            }
            else
                n=n-1;
        }
        if(ch==' ')
            break;
        if(ch=='q')
            wpinfo(bhao);
    }
    if(n<=0||n>1000)
    {
        printf("\n请求错误！请选择大于0并且小于1000的数目！");
        getch();
        buywp(bhao);
    }
    if((gplay[c_play].gold-pn)<0)
    {
        printf("\n少侠，你的金币不够哦！");
        getch();
        wpinfo(bhao);
    }
    if((gwp[bhao].haved+n)>gwp[bhao].mhave)
    {printf("\n你最多还能购买【%s】%d个！",gwp[bhao].name,gwp[bhao].mhave-gwp[bhao].haved);
        getch();
        wpinfo(bhao);
    }
    pn=gwp[bhao].mgold*n;
    gplay[c_play].gold-=pn;
    printf("\n购买%d个%s成功！",n,gwp[bhao].name);
    printf("\n花费%d个金币",pn);
    gwp[bhao].haved+=n;
    getch();
    wpinfo(bhao);
    */
}


void upcheck()
{
    /*
    date_check();
    if(gplay[c_play].exp>=gplay[c_play].exped)
    {
        cls;
        gplay[c_play].dj+=1;
        if(gplay[c_play].dj>25&&upcheck_k==0)
        {
            upcheck_k=1;
            god_here();
        }
        gplay[c_play].exp=gplay[c_play].exp-gplay[c_play].exped;
        gplay[c_play].exped=gplay[c_play].dj*100;
        gplay[c_play].gj+=5;
        gplay[c_play].fy+=4;
        gplay[c_play].speed+=2;
        gplay[c_play].luck+=1;
        gplay[c_play].hpmax=gplay[c_play].dj*100;
        gplay[c_play].mpmax=gplay[c_play].dj*50;
        gplay[c_play].hp=gplay[c_play].hpmax;
        gplay[c_play].mp=gplay[c_play].mpmax;
        btdy("-","【升级啦！】");
        printf("\n恭喜你，勇士！你升到了%d级！",gplay[c_play].dj);
        printf("\n\n攻击+5\n防御+4\n速度+2\n幸运+1\n ");
        getch();
        upcheck();
    }
*/
}

void god_mod()//上帝代码 
{
    /*
    btdy("-","【上帝代码】");

    if(gplay[c_play].gj>100)
    {
        printf("\n上帝代码已失效！");
        getch();
        menuf();
    }
    else
    {
        printf("\n你看到了上帝！你的攻击力提升了10倍！");
        gplay[c_play].gj*=10;
        getch();
        menuf();
    }
    */
}



void test()//测试引导 
{
    int k;
    k=MessageBox(NULL,"该功能暂未开放！是否到作者论坛了解更多信息？","系统提示",MB_YESNO|MB_ICONINFORMATION);
    if(k==IDYES)
    {
        system("start www.nextgod.com");
    }
    else
        ;
}

void god_here()//神秘奖励 
{
    MessageBox(NULL,"恭喜你勇士！你成功过关，将得到神秘奖励！","神秘奖励",MB_OK);
    system("start www.nextgod.com");

}




void date_check()//系统数据检查 
{
    /*
    if(gplay[c_play].dj>100||gplay[c_play].dj<0||gplay[c_play].gold>200000||gplay[c_play].speed>1000||gplay[c_play].exped<0||gplay[c_play].exped>1000000)
    {
        errdy("程序数据异常，可能存在利用BUG作弊或者档案读取异常，游戏将自动结束,请按照规则进行游戏!","【BUG警告】","严重",0);
        exit(1);
    }
    ;*/
}








