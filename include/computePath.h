#ifndef computePath_h
#define computePath_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Cell Cell;
struct Cell{
    bool obstacle;
    bool open;
    int h;		//For A* algorithm
    int g;		//For A* algorithm
    Cell* father;
    
    int i;
    int j;
};
int* pathToTarget(int* sizePath, char* map, int width, int height);


#endif /* computePath_h */
