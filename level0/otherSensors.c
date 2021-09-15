#include "otherSensors.h"

/*****************************
 *
 *
 *	Getting sensors values
 *
 *
 ******************************/


// This function takes as argument a "GDBusProxy" and return an int which is equal 
// to the value of the temperature detected by the Thymio (in deg C)  
int temperature(GDBusProxy *proxy){
    
    
    GVariant *result;
    GError *error = NULL;
    const int temp;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy, // proxy
                                    "GetVariable", // Method name
                                    g_variant_new("(ss)","thymio-II", "temperature"), // Input : (ss) = first one is a string, second one is a string, then the values of those strings
                                    G_DBUS_CALL_FLAGS_NONE, // flags
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter); // "(an)" because the output it is an array (a) of gint16 (n)
    
    if(iter!=NULL)
        g_variant_iter_next (iter, "n", &temp);
    
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    
    return temp/10.0;
}





// This function takes as argument a "GDBusProxy" and a table of "int", the function 
// fills the table with the values of the axes x, y and z at positions 0, 1 and 2
void Accelerometer(GDBusProxy *proxy, int* vAcc){
    
    
    GVariant *result;
    GError *error = NULL;
    int acc;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "acc"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    
    int i=0;
    while (g_variant_iter_loop (iter, "n", &acc)){
        vAcc[i]=acc;
        i++;
    }
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
}





// This function takes as argument a "GDBusProxy" and return an int which is equal 
// to the value of the sound intensity detected by the Thymio 
int soundIntensity(GDBusProxy *proxy){
    
    
    GVariant *result;
    GError *error = NULL;
    const int mic;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy, 
                                    "GetVariable", 
                                    g_variant_new("(ss)","thymio-II", "mic.intensity"), 
                                    G_DBUS_CALL_FLAGS_NONE, 
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter); 
    
    if(iter!=NULL)
        g_variant_iter_next (iter, "n", &mic);
    
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    
    return mic;
}

