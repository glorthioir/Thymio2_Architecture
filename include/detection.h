#ifndef detection_h
#define detection_h

#include <stdbool.h>
#include <stdio.h>
#include <glib/gprintf.h>
#include <gio/gio.h>


bool detectFrontObstacle(GDBusProxy *proxy);

bool detectBackObstacle(GDBusProxy *proxy);

bool detectLeftObstacle(GDBusProxy *proxy);

bool detectRightObstacle(GDBusProxy *proxy);

bool detectGround(GDBusProxy *proxy);

bool detectFrontObstacleMax(GDBusProxy *proxy, int max);

bool detectBackObstacleMax(GDBusProxy *proxy, int max);

bool detectLeftObstacleMax(GDBusProxy *proxy, int max);

bool detectRightObstacleMax(GDBusProxy *proxy, int max);

bool detectSound(GDBusProxy *proxy, int max);

bool detectTilt(GDBusProxy *proxy);

#endif /* detection_h */
