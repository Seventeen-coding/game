#ifndef MAP_H
#define MAP_H

typedef void (*map_handle)(void);
void  Set_current_map(map_handle map);
void  Exec_map();


#endif // MAP_H

