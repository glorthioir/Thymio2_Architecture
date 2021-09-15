#include "proxSensors.h"

/*****************************
 *
 *
 *	Getting sensors values
 *
 *
 ******************************/


// This function takes as argument a "GDBusProxy" and a table of "int", the function fills the table with 
// the values of the seven horizontal sensor of the Thymio (sensor 0 in position 0, sensor 1 in position 1, etc...)
void proximityHorizonSensor(GDBusProxy *proxy, int* vProxSens){
    
    
    GVariant *result;
    GError *error = NULL;
    int proxSens;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "prox.horizontal"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    
    int i=0;
    while (g_variant_iter_loop (iter, "n", &proxSens)){
        //g_print ("%ld\n", proxSens);
        vProxSens[i]=proxSens;
        ++i;
    }
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    
    
}







// This function takes as argument a "GDBusProxy" and a table of "int", the function fills the table with 
// the values of the two ground sensor of the Thymio (left sensor in position 0, right sensor in position 1) for the light intensity
void proximityGroundAmbiantSensor(GDBusProxy *proxy, int* vProxSens){
    
    
    GVariant *result;
    GError *error = NULL;
    int proxSens;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "prox.ground.ambiant"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    
    int i=0;
    while (g_variant_iter_loop (iter, "n", &proxSens)){
        vProxSens[i]=proxSens;
        ++i;
    }
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    
}








// This function takes as argument a "GDBusProxy" and a table of "int", the function fills the table with 
// the values of the two ground sensor of the Thymio (left sensor in position 0, right sensor in position 1) for the light reflection
void proximityGroundReflectedSensor(GDBusProxy *proxy, int* vProxSens){
    
    
    GVariant *result;
    GError *error = NULL;
    int proxSens;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "prox.ground.reflected"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    
    int i=0;
    while (g_variant_iter_loop (iter, "n", &proxSens)){
        vProxSens[i]=proxSens;
        ++i;
    }
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    
}





// This function takes as argument a "GDBusProxy" and a table of "int", the function fills the table with 
// the values of the two ground sensor of the Thymio (left sensor in position 0, right sensor in position 1) for the delta between "ambiant" and "reflected"
void proximityGroundDeltaSensor(GDBusProxy *proxy, int* vProxSens){
    
    
    GVariant *result;
    GError *error = NULL;
    int proxSens;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "prox.ground.delta"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    
    int i=0;
    while (g_variant_iter_loop (iter, "n", &proxSens)){
        vProxSens[i]=proxSens;
        ++i;
    }
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    
}


