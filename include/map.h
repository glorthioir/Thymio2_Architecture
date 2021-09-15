#ifndef map_h
#define map_h

#include <stdio.h>



void toMap(char* path, char* map, int height, int width);

void sizeMap(char* path, int* sizeCell, int* height, int* width);


void writeMap(char* path, char* map, int width, int height, int sizeCell);

#endif /* map_h */
