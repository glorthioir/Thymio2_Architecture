#include "movement.h"
#include "motors.h"
#include "detection.h"
#include <math.h>

/*****************************
 *
 *
 *	Movements
 *
 *
 ******************************/

	
//This function takes as argument a "GDBusProxy" and stop the Thymio's motors
void stop(GDBusProxy *proxy){
    setMotorLeft(proxy, 0);
    setMotorRight(proxy, 0);
}




//This function takes as arguments a "GDBusProxy" and an int "speed", the two motors
// of the Thymio will be set at this speed
// The value of "speed" must be between -500 and 500
void linearMove(GDBusProxy *proxy, int speed){
    setMotorLeft(proxy, speed);
    setMotorRight(proxy, speed);
}



//This function takes as arguments a "GDBusProxy", an int "speed" and an int "distance" 
// the Thymio will advance "distance" centimeters at the speed "speed" and will stop if 
// a obstacle is encountered
// The value of "speed" must be between -500 and 500
int linearMoveDistanceChecked(GDBusProxy *proxy, int speed, int distance){
    puts("Appuyez sur ENTREE pour continuer...");
    getchar();
    double taux=fabs(speed/500.0);
    double temps=distance/(taux*15.0);
    
    setMotorLeft(proxy, speed);
    setMotorRight(proxy, speed);
    
    struct timeval tmv1, tmv2;
    double duration;
    gettimeofday(&tmv1, NULL);
    gettimeofday(&tmv2, NULL);
    duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
    
    if(speed > 0)
        while( duration < temps ){
            if(detectLeftObstacle(proxy) || detectFrontObstacle(proxy) || detectRightObstacle(proxy)){
                duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
                stop(proxy);
                return (int)(duration * (taux*15.0)); // Send a message to inform how many cm the robot travelled
            }
            
            gettimeofday(&tmv2, NULL);
            duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
        }
    else
        while( duration < temps ){
            //g_print ("Temps : %f sec\n", duration );
            if(detectBackObstacle(proxy)){
                duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
                stop(proxy);
                return (int)(duration * (taux*15.0)); // Send a message to inform how many cm the robot travelled
            }

			gettimeofday(&tmv2, NULL);

            duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
        }
    
    stop(proxy);
    return -1;
}






//This function takes as arguments a "GDBusProxy", an int "speed" and an int "distance" 
// the Thymio will advance "distance" centimeters at the speed "speed"
// The value of "speed" must be between -500 and 500
void linearMoveDistanceUnchecked(GDBusProxy *proxy, int speed, int distance){
    double taux=fabs(speed/500.0);
    double temps=distance/(taux*15.0);
    
    setMotorLeft(proxy, speed);
    setMotorRight(proxy, speed);
    
    struct timeval tmv1, tmv2;
    double duration;
    gettimeofday(&tmv1, NULL);
    gettimeofday(&tmv2, NULL);
    duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
    
    while( duration < temps ){
        gettimeofday(&tmv2, NULL);
        duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
    }
    
    stop(proxy);
}








//This function takes as arguments a "GDBusProxy", an int "angle", an int "speed"
// and a double "rayon" which is the radius of the robot, the Thymio will rotate from
// the left to "angle" degrees at the speed "speed"
// The value of "speed" must be between 1 and 500
// The value of "angle" must be between 1 and 180
 
void turnLeft(GDBusProxy *proxy, int angle, int speed, double rayon){ //rayon = 4.85 pour bon fonctionnement
    
	struct timeval tmv1, tmv2;
    double duration;
	double tauxA=angle/360.0;
    double tauxV=fabs(speed/500.0);
	double distance=2*M_PI*rayon*tauxA;
    double temps=distance/(tauxV*15.0);

	gettimeofday(&tmv1, NULL);
    gettimeofday(&tmv2, NULL);
    duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
    
	
	if(angle <= 180 && angle > 0 && speed >0){

		setMotorLeft(proxy, -speed);
        setMotorRight(proxy, speed);

        while( duration < temps ){
			gettimeofday(&tmv2, NULL);
            duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
		}

		stop(proxy);
        
    }else
        g_print("Valeur d'angle ou vitesse incorrect !\n");
    
}




//This function takes as arguments a "GDBusProxy", an int "angle", an int "speed"
// and a double "rayon" which is the radius of the robot, the Thymio will rotate from
// the right to "angle" degrees at the speed "speed"
// The value of "speed" must be between 1 and 500
// The value of "angle" must be between 1 and 180
void turnRight(GDBusProxy *proxy, int angle, int speed, double rayon){
    
    struct timeval tmv1, tmv2;
    double duration;
	double tauxA=angle/360.0;
    double tauxV=fabs(speed/500.0);
	double distance=2*M_PI*rayon*tauxA;
    double temps=distance/(tauxV*15.0);

	gettimeofday(&tmv1, NULL);
    gettimeofday(&tmv2, NULL);
    duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
    
	
	if(angle <= 180 && angle > 0 && speed >0){

		setMotorLeft(proxy, speed);
        setMotorRight(proxy, -speed);

        while( duration < temps ){
			gettimeofday(&tmv2, NULL);
            duration = (tmv2.tv_sec-tmv1.tv_sec) + (tmv2.tv_usec-tmv1.tv_usec)*1.0/1000000;
		}

		stop(proxy);
        
    }else
        g_print("Valeur d'angle ou vitesse incorrect !\n");

}

