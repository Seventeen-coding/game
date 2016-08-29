#ifndef SL_DATA_H
#define SL_DATA_H
#include <stdio.h>
#include <string.h>
#include "data/include/hero_data.h"
int  SL_load_data();
int  SL_save_data();
char *Load_hero_info(char * buf,const char *info);

#endif // SL_DATA_H

