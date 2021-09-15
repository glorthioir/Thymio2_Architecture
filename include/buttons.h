#ifndef buttons_h
#define buttons_h

#include <stdio.h>
#include <stdbool.h>
#include <glib/gprintf.h>
#include <gio/gio.h>


bool buttonForward(GDBusProxy *proxy);

bool buttonBackward(GDBusProxy *proxy);

bool buttonLeft(GDBusProxy *proxy);

bool buttonRight(GDBusProxy *proxy);

bool buttonCenter(GDBusProxy *proxy);

#endif /* buttons_h */
