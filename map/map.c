#include "map/include/map.h"

map_handle current_map;
void  Set_current_map(map_handle map)
{
    current_map = map;
}
void  Exec_map()
{
        current_map();
}
