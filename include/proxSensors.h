//
//  proxSensors.h
//
//
//  Created by Nicolas BILLOD on 08/03/2017.
//
//

#ifndef proxSensors_h
#define proxSensors_h

#include <stdio.h>
#include <glib/gprintf.h>
#include <gio/gio.h>


void proximityHorizonSensor(GDBusProxy *proxy, int* vProxSens);

void proximityGroundAmbiantSensor(GDBusProxy *proxy, int* vProxSens);

void proximityGroundReflectedSensor(GDBusProxy *proxy, int* vProxSens);

void proximityGroundDeltaSensor(GDBusProxy *proxy, int* vProxSens);

#endif /* proxSensors_h */
