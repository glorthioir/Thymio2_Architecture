#ifndef exploration_h
#define exploration_h

#include <stdio.h>
#include <stdlib.h>
#include <gio/gio.h>
#include <stdbool.h>

typedef struct LittleCell LittleCell;
struct LittleCell{
    
    //char letter;
    bool obstacle;
    bool explored;
    bool open;
    
};

void updateLilCellMap(LittleCell* mapLilCell, int* pathFollowed, int sizePath, char* map, int width);

void exploration(GDBusProxy *proxy, char* path, int speed, int width, int sizeCell);

#endif /* exploration_h */
