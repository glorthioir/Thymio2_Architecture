#ifndef otherSensors_h
#define otherSensors_h

#include <stdio.h>
#include <glib/gprintf.h>
#include <gio/gio.h>


int temperature(GDBusProxy *proxy);

void Accelerometer(GDBusProxy *proxy, int* vAcc);

int soundIntensity(GDBusProxy *proxy);

#endif /* otherSensors_h */
