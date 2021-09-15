#include "orientation.h"

#include "movement.h"


void orientateTo(GDBusProxy *proxy, int orientation, int orientationNeeded){
    int diffOrientation = orientation - orientationNeeded;
    int speed = 400;
    
    printf("Diff orientation : %d\n", diffOrientation);
    if(diffOrientation == 0)
        return;
    else{
        if(diffOrientation < 0){ // Turn left unless it is >= 180
            diffOrientation *= -1;
            if(diffOrientation >= 180)
                turnRight(proxy, 360 - diffOrientation, speed, 4.90);
            else
                turnLeft(proxy, diffOrientation, speed, 4.90);
            
        }
        else{ // Turn right unless it is >= 180
            if(diffOrientation >= 180)
                turnLeft(proxy, 360 - diffOrientation, speed, 4.90);
            else
                turnRight(proxy, diffOrientation, speed, 4.90);
        }
    }
    
}
