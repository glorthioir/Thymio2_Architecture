#include "motors.h"

/*****************************
 *
 *
 *	Getting/Setting motors values
 *
 *
 ******************************/



// This function takes as argument a "GDBusProxy" and return an int which is equal 
// to the value of the Thymio left motor speed
int getMotorLeft(GDBusProxy *proxy){
	GVariant *result;
    GError *error = NULL;
    const int speed;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy, 
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "motor.left.speed"), 
                                    G_DBUS_CALL_FLAGS_NONE, 
                                    -1,
                                    NULL,
                                    &error);

    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter); 
    if(iter!=NULL)
        g_variant_iter_next (iter, "n", &speed);
      
    g_variant_iter_free (iter);
    g_variant_unref(result);
        
    return speed;
}



// This function takes as argument a "GDBusProxy" and return an int which is equal 
// to the value of the Thymio right motor speed
int getMotorRight(GDBusProxy *proxy){
	GVariant *result;
    GError *error = NULL;
    const int speed;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy, 
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "motor.right.speed"), 
                                    G_DBUS_CALL_FLAGS_NONE, 
                                    -1,
                                    NULL,
                                    &error);

    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter); 
    if(iter!=NULL)
        g_variant_iter_next (iter, "n", &speed);
      
    g_variant_iter_free (iter);
    g_variant_unref(result);
        
    return speed;
}



// This function takes as arguments a "GDBusProxy" and an int "speed" which is equal 
// to the value of the Thymio left motor speed which one wishes to achieve
void setMotorLeft(GDBusProxy *proxy, int speed){
    
    
    GError *error = NULL;
    GVariantBuilder *builder;
    
    
    builder = g_variant_builder_new (G_VARIANT_TYPE ("an"));
    g_variant_builder_add (builder, "n", speed);
    
    
    g_dbus_proxy_call_sync(proxy,
                           "SetVariable",
                           g_variant_new("(ssan)","thymio-II", "motor.left.target",builder),
                           G_DBUS_CALL_FLAGS_NONE,
                           -1,
                           NULL,
                           &error);
    g_assert_no_error(error);
    g_variant_builder_unref(builder);
    
}



// This function takes as arguments a "GDBusProxy" and an int "speed" which is equal 
// to the value of the Thymio right motor speed which one wishes to achieve
void setMotorRight(GDBusProxy *proxy, int speed){
    
    
    GError *error = NULL;
    GVariantBuilder *builder;
    
    
    builder = g_variant_builder_new (G_VARIANT_TYPE ("an"));
    g_variant_builder_add (builder, "n", speed);
    
    
    g_dbus_proxy_call_sync(proxy,
                           "SetVariable",
                           g_variant_new("(ssan)","thymio-II", "motor.right.target",builder),
                           G_DBUS_CALL_FLAGS_NONE,
                           -1,
                           NULL,
                           &error);
    g_assert_no_error(error);
    g_variant_builder_unref(builder);
    
}

