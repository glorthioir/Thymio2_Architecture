#ifndef motors_h
#define motors_h

#include <stdio.h>
#include <glib/gprintf.h>
#include <gio/gio.h>


int getMotorLeft(GDBusProxy *proxy);

int getMotorRight(GDBusProxy *proxy);

void setMotorLeft(GDBusProxy *proxy, int speed);

void setMotorRight(GDBusProxy *proxy, int speed);

#endif /* motors_h */
