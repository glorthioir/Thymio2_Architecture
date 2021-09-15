#include "movement.h"
#include "motors.h"
#include "detection.h"
#include "advanced.h"
#include "map.h"
#include "computePath.h"
#include "pathExecution.h"


/*****************************
 *
 *
 *	Advanced functions
 *
 *
 ******************************/


// This function takes as argument a "GDBusProxy", an int "speed" and an other int "duration"
// The function executes a random walk for the robot during a period of "duration" seconds 
// The value of "speed" must be between -500 and 500 
void randomWalk(GDBusProxy *proxy, int speed, int duration){
    
    int distance, angle;
    int borneInf=15, borneSup=40;
    time_t temps1, temps2;
    
    time(&temps1);
    time(&temps2);
    
    while(difftime(temps2, temps1) < duration){
        distance=rand()%(borneSup-borneInf)+borneInf;
        linearMoveDistanceChecked(proxy, speed, distance);
        
        g_print ("Distance : %d \n", distance);
        
        if(detectLeftObstacle(proxy) || detectRightObstacle(proxy) || detectFrontObstacle(proxy) || detectBackObstacle(proxy))
            obstacleAvoidance(proxy, speed);
        
        angle=rand()%181+1;
        if(rand()%2 == 0)
            turnLeft(proxy, angle, speed, 4.90);
        else
            turnRight(proxy, angle, speed, 4.90);
        
        g_print ("Angle : %d \n", angle);
        time(&temps2);
    }
    
    
    
}




// This function takes as argument a "GDBusProxy" and an int "speed" 
// The function check if the robot detect a obstacle and moves away if it's the case 
// The value of "speed" must be between -500 and 500 
void obstacleAvoidance(GDBusProxy *proxy, int speed){
    
    if(detectBackObstacle(proxy))
        linearMoveDistanceChecked(proxy, speed, 10);
    
    while(detectLeftObstacle(proxy))
        turnRight(proxy, 30, speed, 4.90);
    
    while(detectRightObstacle(proxy))
        turnLeft(proxy, 30, speed, 4.90);
    
    if(detectFrontObstacle(proxy) || detectLeftObstacle(proxy))
        linearMove(proxy, -speed);
    
    while(detectFrontObstacle(proxy)){
        if(detectBackObstacle(proxy))
            stop(proxy);
        else
            usleep(500000);
    }
    stop(proxy);
    
}











