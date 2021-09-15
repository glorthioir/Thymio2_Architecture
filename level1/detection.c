#include <stdlib.h>

#include "detection.h"
#include "proxSensors.h"
#include "otherSensors.h"

/*****************************
 *
 *
 *	Obstacles detection 
 *
 *
 ******************************/


// This function takes as argument a "GDBusProxy" and return a boolean which is equal 
// to "true" if the front sensors of the Thymio detect an obstacle at a standard distance "false" if not
bool detectFrontObstacle(GDBusProxy *proxy){

	int* proxH=malloc(7*sizeof(int));
    proximityHorizonSensor(proxy, proxH);

	if(proxH[1]>2000 || proxH[2]>3000 || proxH[3]>2000){
		free(proxH);
		return true;
	}else{
		free(proxH);
		return false;
	}
}



// This function takes as argument a "GDBusProxy" and return a boolean which is equal 
// to "true" if the back sensors of the Thymio detect an obstacle at a standard distance "false" if not
bool detectBackObstacle(GDBusProxy *proxy){

	int* proxH=malloc(7*sizeof(int));
    proximityHorizonSensor(proxy, proxH);

	if(proxH[5]>2000 || proxH[6]>2000){
		free(proxH);
		return true;
	}else{
		free(proxH);
		return false;
	}
}



// This function takes as argument a "GDBusProxy" and return a boolean which is equal 
// to "true" if the left sensors of the Thymio detect an obstacle at a standard distance "false" if not
bool detectLeftObstacle(GDBusProxy *proxy){

	int* proxH=malloc(7*sizeof(int));
    proximityHorizonSensor(proxy, proxH);

	if(proxH[0]>3000 || proxH[1]>2000){
		free(proxH);
		return true;
	}else{
		free(proxH);
		return false;
	}
}



// This function takes as argument a "GDBusProxy" and return a boolean which is equal 
// to "true" if the right sensors of the Thymio detect an obstacle at a standard distance "false" if not
bool detectRightObstacle(GDBusProxy *proxy){

	int* proxH=malloc(7*sizeof(int)); 
    proximityHorizonSensor(proxy, proxH);	

	if(proxH[3]>2000 || proxH[4]>3000){
		free(proxH);
		return true;
	}else{
		free(proxH);
		return false;
	}
}




// This function takes as arguments a "GDBusProxy" and an int "max", return a boolean which is equal 
// to "true" if the front sensors of the Thymio return a higher than "max", "false" if not
bool detectFrontObstacleMax(GDBusProxy *proxy, int max){

	int* proxH=malloc(7*sizeof(int));
    proximityHorizonSensor(proxy, proxH);

	if(proxH[1]>(int)(max*0.8) || proxH[2]>max || proxH[3]>(int)(max*0.8)){
		free(proxH);
		return true;
	}else{
		free(proxH);
		return false;
	}
}



// This function takes as arguments a "GDBusProxy" and an int "max", return a boolean which is equal 
// to "true" if the back sensors of the Thymio return a higher than "max", "false" if not
bool detectBackObstacleMax(GDBusProxy *proxy, int max){

	int* proxH=malloc(7*sizeof(int));
    proximityHorizonSensor(proxy, proxH);

	if(proxH[5]>max || proxH[6]>max){
		free(proxH);
		return true;
	}else{
		free(proxH);
		return false;
	}
}



// This function takes as arguments a "GDBusProxy" and an int "max", return a boolean which is equal 
// to "true" if the left sensors of the Thymio return a higher than "max", "false" if not
bool detectLeftObstacleMax(GDBusProxy *proxy, int max){

	int* proxH=malloc(7*sizeof(int));
    proximityHorizonSensor(proxy, proxH);

	if(proxH[0]>max || proxH[1]>(int)(max*0.8)){
		free(proxH);
		return true;
	}else{
		free(proxH);
		return false;
	}
}



// This function takes as arguments a "GDBusProxy" and an int "max", return a boolean which is equal 
// to "true" if the right sensors of the Thymio return a higher than "max", "false" if not
bool detectRightObstacleMax(GDBusProxy *proxy, int max){

	int* proxH=malloc(7*sizeof(int)); 
    proximityHorizonSensor(proxy, proxH);	

	if(proxH[3]>(int)(max*0.8) || proxH[4]>max){
		free(proxH);
		return true;
	}else{
		free(proxH);
		return false;
	}
}



// This function takes as argument a "GDBusProxy" and return a boolean which is equal 
// to "true" if the ground sensors of the Thymio detect the ground at a standard distance "false" if not
bool detectGround(GDBusProxy *proxy){

	int* proxR=malloc(2*sizeof(int));
	int* proxA=malloc(2*sizeof(int));
    proximityGroundReflectedSensor(proxy, proxR);
	proximityGroundAmbiantSensor(proxy, proxA);

	if((proxR[0]>500 && proxR[1]>500) || (proxA[0]>500 && proxA[1]>500)){
		free(proxR);
		free(proxA);
		return true;
	}else{
		free(proxR);
		free(proxA);
		return false;
	}
}



// This function takes as arguments a "GDBusProxy" and an int "max", return a boolean which is equal 
// to "true" if the sound sensors of the Thymio detect a sound intensity higher than "max", "false" if not
bool detectSound(GDBusProxy *proxy, int max){

	int sound=soundIntensity(proxy);

	if(sound >= max)
		return true;
	else
		return false;

}




bool detectTilt(GDBusProxy *proxy){
// a faire
}
