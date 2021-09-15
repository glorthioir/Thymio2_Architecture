#ifndef orientation_h
#define orientation_h

#include <stdio.h>
#include <gio/gio.h>

void orientateTo(GDBusProxy *proxy, int orientation, int orientationNeeded);


#endif /* orientation_h */
