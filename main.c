#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <glib/gprintf.h>
#include <gio/gio.h>
#include <unistd.h>

#include "proxSensors.h"
#include "buttons.h"
#include "otherSensors.h"
#include "motors.h"
#include "movement.h"
#include "detection.h"
#include "advanced.h"
#include "map.h"

//Raspberry : -I/usr/lib/arm-linux-gnueabihf/glib-2.0/include

// To compile :
// gcc -g main.c -o test -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include/ -ldbus-1 -ldbus-glib-1 -Wall -Wextra -lglib-2.0 -lgio-2.0 -lgobject-2.0 -lgthread-2.0

// To execute
// sudo ./test
// (don't forget to start medulla first)




/*****************************
 *
 *
 *	Tests
 *
 *
 ******************************/

int main(void){
    
    
    GDBusProxy *proxy;
    GDBusConnection *conn;
    GError *error = NULL;
    int i;
    int speed = 300;
    int max = 3500;
    int orientation = 0;

    conn = g_bus_get_sync(G_BUS_TYPE_SESSION, NULL, &error);
    g_assert_no_error(error);
    
    
    
    
    proxy = g_dbus_proxy_new_sync(conn,
                                  G_DBUS_PROXY_FLAGS_NONE,
                                  NULL,                /* GDBusInterfaceInfo */
                                  "ch.epfl.mobots.Aseba",        /* name */
                                  "/",    /* object path */
                                  "ch.epfl.mobots.AsebaNetwork",    /* interface */
                                  NULL,                /* GCancellable */
                                  &error);
    g_assert_no_error(error);
 
    
    error = NULL;







	// ****  Tests bas niveaux  **** // 
    
    /*
    double temp = temperature(proxy);
	g_print ("Temperature : %f C\n", temp);
     
     
     int* proxH=malloc(7*sizeof(int));
     proximityHorizonSensor(proxy, proxH);
     for(i=0; i<7; ++i)
     g_print ("Proximity Horizontal Sensor %d : %d \n", i, proxH[i]);
     
     
     int* proxGA=malloc(2*sizeof(int));
     proximityGroundAmbiantSensor(proxy, proxGA);
     for(i=0; i<2; ++i)
     g_print ("Proximity Ground Sensor Ambiant %d : %d \n", i, proxGA[i]);
     
     
     int* proxGR=malloc(2*sizeof(int));
     proximityGroundReflectedSensor(proxy, proxGR);
     for(i=0; i<2; ++i)
     g_print ("Proximity Ground Sensor Reflected %d : %d \n", i, proxGR[i]);
     
     
     int* proxGD=malloc(2*sizeof(int));
     proximityGroundDeltaSensor(proxy, proxGD);
     for(i=0; i<2; ++i)
     g_print ("Proximity Ground Sensor Delta %d : %d \n", i, proxGD[i]);
     
     
     g_print (detectFrontObstacleMax(proxy, max) ? "Obstacle frontale : oui !\n" : "Obstacle frontale : non !\n");
     g_print (detectBackObstacleMax(proxy, max) ? "Obstacle arriere : oui !\n" : "Obstacle arriere : non !\n");
     g_print (detectLeftObstacleMax(proxy, max) ? "Obstacle gauche : oui !\n" : "Obstacle gauche : non !\n");
     g_print (detectRightObstacleMax(proxy, max) ? "Obstacle droite : oui !\n" : "Obstacle droite : non !\n");
     g_print (detectGround(proxy) ? "Detection sol : oui !\n" : "Detection sol : non !\n");
     g_print (detectSound(proxy, 50) ? "Detection son : oui !\n" : "Detection son : non !\n");
     

     if(buttonForward(proxy))
     g_print ("Forward button pushed.\n");
     else
     g_print ("Forward button released.\n");
     
     if(buttonBackward(proxy))
     g_print ("Backward button pushed.\n");
     else
     g_print ("Backward button released.\n");
     
     if(buttonLeft(proxy))
     g_print ("Left button pushed.\n");
     else
     g_print ("Left button released.\n");
     
     if(buttonRight(proxy))
     g_print ("Right button pushed.\n");
     else
     g_print ("Right button released.\n");
     
     if(buttonCenter(proxy))
     g_print ("Center button pushed.\n");
     else
     g_print ("Center button released.\n");
     
	*/







	// ****  Test du suivi d'itineraire  **** //

    /*int sizeCell = 0, height = 0, width = 0;
    sizeMap("carte2.txt", &width, &height, &sizeCell);
    char* map = malloc(width*height*sizeof(char));
    toMap("carte2.txt", map, width, height);
    
    
    int * pathToFollow = malloc(10 * sizeof(int));
    int sizePath=-1;
    int* pathToFollow = pathToTarget(&sizePath, map, width, height);

    executePathUnchecked(proxy, speed, pathToFollow, sizePath, sizeCell, orientation);
    executePathChecked(proxy, speed, map, width, height, pathToFollow, &sizePath, sizeCell, orientation);
    
    if(sizePath !=-1)
        free(pathToFollow);
    
    free(map);
	*/







	// ****  Test de  l'exploration  **** //

	//exploration(proxy, "carte3.txt", speed, 8, 10);







	// ****  Test du deplacement aleatoire  **** //
 
    //randomWalk(proxy, speed, 30);
	






	// ****  Test des fonctions de deplacement  **** // 

	linearMoveDistanceChecked(proxy, speed, 50);
	turnLeft(proxy, 90, speed, 4.90);
	linearMoveDistanceChecked(proxy, speed, 50);
	turnLeft(proxy, 90, speed, 4.90);
	linearMoveDistanceChecked(proxy, speed, 50);
	turnLeft(proxy, 90, speed, 4.90);
	linearMoveDistanceChecked(proxy, speed, 50);
	turnLeft(proxy, 90, speed, 4.90);




    g_object_unref(proxy);
    g_object_unref(conn);
    
    
	


	// A decommenter pour les tests bas niveaux
	
    /*free(proxH);
     free(proxGA);
     free(proxGR);
     free(proxGD);*/
    

    return 0;
}
