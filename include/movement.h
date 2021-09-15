#ifndef movement_h
#define movement_h

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <glib/gprintf.h>
#include <gio/gio.h>
#include <time.h>
#include <sys/time.h>


void linearMove(GDBusProxy *proxy, int speed);

int linearMoveDistanceChecked(GDBusProxy *proxy, int speed, int distance);

void linearMoveDistanceUnchecked(GDBusProxy *proxy, int speed, int distance);

void turnLeft(GDBusProxy *proxy, int angle, int speed, double rayon);

void turnRight(GDBusProxy *proxy, int angle, int speed, double rayon);

void stop(GDBusProxy *proxy);

#endif /* movement_h */
