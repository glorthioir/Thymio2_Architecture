#ifndef advanced_h
#define advanced_h

#include <glib/gprintf.h>
#include <gio/gio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void randomWalk(GDBusProxy *proxy, int speed, int time);

void obstacleAvoidance(GDBusProxy *proxy, int speed);




#endif /* advanced_h */
