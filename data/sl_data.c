
#include "data/include/sl_data.h"
//读取文件最好以字符串形式获取修改起来比较方便。。。
//对于不怀好意的同样方便。。。(如果为了安全，前面加一个校验就可以了)
char buffer[1024];
int SL_load_data()
{
    FILE *fp;
    if((fp=fopen("./KillDragon.dat","r"))==NULL)    return -1;
    fread(buffer,1024,1,fp);
    hero_t hero;
    strcpy(hero.name,Load_hero_info(buffer,"hero_name"));
    hero.level = atoi(Load_hero_info(buffer,"hero_level"));
    hero.ATK =     atoi(Load_hero_info(buffer,"hero_ATK"));
    hero.DEF =   atoi(Load_hero_info(buffer,"hero_DEF"));
    hero.SPE =  atoi(Load_hero_info(buffer,"hero_SPE"));
    hero.LUC =     atoi(Load_hero_info(buffer,"hero_LUC"));
    hero.GOLD =  atoi(Load_hero_info(buffer,"hero_GOLD"));
    hero.yesp =  atoi(Load_hero_info(buffer,"hero_yesp"));
    hero.EXP =   atoi(Load_hero_info(buffer,"hero_EXP"));
    hero.UP_GRADE =  atoi(Load_hero_info(buffer,"hero_UP_GRADE"));
    hero.HP =  atoi(Load_hero_info(buffer,"hero_HP"));
    hero.HP_Max =   atoi(Load_hero_info(buffer,"hero_HP_Max"));
    hero.MP   = atoi(Load_hero_info(buffer,"hero_MP"));
    hero.MP_Max =  atoi(Load_hero_info(buffer,"hero_MP_Max"));
    hero_init(hero.name,hero.level,hero.ATK,hero.DEF,hero.SPE,hero.LUC, hero.GOLD,\
              hero.yesp,hero.EXP,hero.UP_GRADE,hero.HP,hero.HP_Max,hero.MP,hero.MP_Max);
    if(fclose(fp)!=0)            return -1;
    return 0;
}

int  SL_save_data()
{
    if(Get_current_hero_info() == NULL) return -1;
    FILE *fp;
    if((fp=fopen("./KillDragon.dat","w"))==NULL)    return -1;
    hero_t hero;
    memcpy(&hero, Get_current_hero_info(),sizeof(hero_t));
    char hero_info_str[20];
    sprintf(hero_info_str,"hero_name=%s\n",hero.name);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_level=%d\n",hero.level);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_ATK=%d\n",hero.ATK);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_DEF=%d\n",hero.DEF);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_SPE=%d\n",hero.SPE);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_LUC=%d\n",hero.LUC);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_GOLD=%d\n",hero.GOLD);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_yesp=%d\n",hero.yesp);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_EXP=%d\n",hero.EXP);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_UP_GRADE=%d\n",hero.UP_GRADE);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_HP=%d\n",hero.HP);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_HP_Max=%d\n",hero.HP_Max);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_MP=%d\n",hero.MP);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);
    sprintf(hero_info_str,"hero_MP_Max=%d\n",hero.MP_Max);
    fwrite(hero_info_str,strlen(hero_info_str),1,fp);

    if(fclose(fp)!=0)
    {
        return -1;
    }
    return 0;
}

char *Load_hero_info(char * buf,const char *info)
{
    if(buf == NULL) return NULL;
    //
    char *line_str_start = strstr(buf,info);
    if(line_str_start == NULL)    return NULL;
    char *line_str_end = strchr(line_str_start,'\n');
    if(line_str_end == NULL)    return NULL;
    int len = line_str_end - line_str_start-strlen(info) - 1;
    char *info_data = malloc(len+1);
    //
    strncpy(info_data,line_str_start+strlen(info) + 1,len);
    info_data[len] = '\0';
    return info_data;
}
