#ifndef pathExecution_h
#define pathExecution_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gio/gio.h>

void executePathUnchecked(GDBusProxy *proxy, int speed, int* pathToFollow, int sizePath, int sizeCell, int orientation);

void addXMap(char* map, int width, int height, int index);
void moveBMap(char* map, int width, int height, int index);

int executePathChecked(GDBusProxy *proxy, int speed, char* map, int width, int height, int* pathToFollow, int* sizePath, int sizeCell, int orientation);



#endif /* pathExecution_h */
