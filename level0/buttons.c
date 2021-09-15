
#include "buttons.h"

// This function takes a "GDBusProxy" as argument and return a "boolean"
// which is equal to "true" if the forward button of the Thymio is pushed, "false" else.
bool buttonForward(GDBusProxy *proxy){
    
    
    GVariant *result;
    GError *error = NULL;
    const int buttonPushed;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "button.forward"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    if(iter!=NULL)
        g_variant_iter_next (iter, "n", &buttonPushed);
    
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    if (buttonPushed==1)
        return true;
    
    return false;
}





// This function takes a "GDBusProxy" as argument and return a "boolean"
// which is equal to "true" if the backward button of the Thymio is pushed, "false" else.
bool buttonBackward(GDBusProxy *proxy){
    
    
    GVariant *result;
    GError *error = NULL;
    const int buttonPushed;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "button.backward"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    if(iter!=NULL)
        g_variant_iter_next (iter, "n", &buttonPushed);
    
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    if (buttonPushed==1)
        return true;
    
    return false;
}





// This function takes a "GDBusProxy" as argument and return a "boolean"
// which is equal to "true" if the left button of the Thymio is pushed, "false" else.
bool buttonLeft(GDBusProxy *proxy){
    
    
    GVariant *result;
    GError *error = NULL;
    const int buttonPushed;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "button.left"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    if(iter!=NULL)
        g_variant_iter_next (iter, "n", &buttonPushed);
    
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    if (buttonPushed==1)
        return true;
    
    return false;
}






// This function takes a "GDBusProxy" as argument and return a "boolean"
// which is equal to "true" if the right button of the Thymio is pushed, "false" else.
bool buttonRight(GDBusProxy *proxy){
    
    
    GVariant *result;
    GError *error = NULL;
    const int buttonPushed;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "button.right"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    if(iter!=NULL)
        g_variant_iter_next (iter, "n", &buttonPushed);
    
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    if (buttonPushed==1)
        return true;
    
    return false;
}






// This function takes a "GDBusProxy" as argument and return a "boolean"
// which is equal to "true" if the forward button of the Thymio is pushed, "false" else.
bool buttonCenter(GDBusProxy *proxy){
    
    
    GVariant *result;
    GError *error = NULL;
    const int buttonPushed;
    GVariantIter *iter;
    
    
    result = g_dbus_proxy_call_sync(proxy,
                                    "GetVariable",
                                    g_variant_new("(ss)","thymio-II", "button.center"),
                                    G_DBUS_CALL_FLAGS_NONE,
                                    -1,
                                    NULL,
                                    &error);
    g_assert_no_error(error);
    g_variant_get(result, "(an)", &iter);
    
    if(iter!=NULL)
        g_variant_iter_next (iter, "n", &buttonPushed);
    
    
    
    g_variant_iter_free (iter);
    g_variant_unref(result);
    
    if (buttonPushed==1)
        return true;
    
    return false;
}

