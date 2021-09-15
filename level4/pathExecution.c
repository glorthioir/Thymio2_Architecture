#include "pathExecution.h"

#include "movement.h"
#include "computePath.h"




// This function takes as argument a "GDBusProxy", four int "speed", "sizePath", "sizeCell", "orientation"
// and an int tabular "pathToFollow". The function allows the robot to follow the path "pathToFollow" at the speed "speed"
// and the parameters of the path are defined by the "orientation" of the robot, the size of
// the path "sizePath" and the size of each cell of the path "sizeCell" 
// The value of "speed" must be between -500 and 500
// The value of "orientation" must be 0 or 90 or 180 or 270, it's a angle
void executePathUnchecked(GDBusProxy *proxy, int speed, int* pathToFollow, int sizePath, int sizeCell, int orientation){
    
    if(sizePath == -1){
        printf("Trying to execute an unchecked path, but path is empty.\n");
        return;
    }
    
    int i;
    
    for(i=0; i<sizePath-1; ++i){
        
        // 4 possibles cases : top, right, bottom, left AND ORIENTED TOP <= need to be modified at some point
        
        // TOP
        if(pathToFollow[i] > pathToFollow[i+1] && pathToFollow[i] > pathToFollow[i+1]+1) {
            if(orientation == 0){
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 90){
                turnRight(proxy, 90, speed, 4.90);
                orientation = 0;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 180){
                turnRight(proxy, 180, speed, 4.90);
                orientation = 0;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 270){
                turnLeft(proxy, 90, speed, 4.90);
                orientation = 0;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
        }
        
        
        
        
        
        
        // RIGHT
        if(pathToFollow[i] < pathToFollow[i+1] && pathToFollow[i]+1 == pathToFollow[i+1]) {
            if(orientation == 0){
                turnRight(proxy, 90, speed, 4.90);
                orientation = 270;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 90){
                turnRight(proxy, 180, speed, 4.90);
                orientation = 270;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 180){
                turnLeft(proxy, 90, speed, 4.90);
                orientation = 270;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 270){
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
        }
        
        
        
        
        
        
        
        
        // BOTTOM
        if(pathToFollow[i] < pathToFollow[i+1] && pathToFollow[i]+1 < pathToFollow[i+1]) {
            if(orientation == 0){
                turnRight(proxy, 180, speed, 4.90);
                orientation = 180;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 90){
                turnLeft(proxy, 90, speed, 4.90);
                orientation = 180;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 180){
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 270){
                turnRight(proxy, 90, speed, 4.90);
                orientation = 180;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
        }
        
        
        
        
        
        // LEFT
        if(pathToFollow[i] > pathToFollow[i+1] && pathToFollow[i] == pathToFollow[i+1]+1) {
            if(orientation == 0){
                turnLeft(proxy, 90, speed, 4.90);
                orientation = 90;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 90){
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 180){
                turnRight(proxy, 90, speed, 4.90);
                orientation = 90;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            if(orientation == 270){
                turnRight(proxy, 180, speed, 4.90);
                orientation = 90;
                linearMoveDistanceUnchecked(proxy, speed, sizeCell);
            }
            
            
        }
        
        //printf("%d -> %d\n",pathToFollow[i], pathToFollow[i+1]);
        
        
    }
    
}
















// This function takes as argument a string "map" and three int "width", "height" and "index"
// The function try to put a obstacle in the position "index" of the map "map"
// The map is defined by the parameters "width" and "height"
void addXMap(char* map, int width, int height, int index){
    if(index < 0 || index >= height*width){
        printf("Trying to put an X on a map but index is out of the map.\n");
        return;
    }
    
    map[index] = 'x';
}



// This function takes as argument a string "map" and three int "width", "height" and "index"
// The function try to move the marker "B" in the position "index" of the map "map"
// The map is defined by the parameters "width" and "height"
void moveBMap(char* map, int width, int height, int index){
    
    if(index < 0 || index >= height*width){
        printf("Trying to move B on a map but index is out of the map.\n");
        return;
    }
    
    int i, j;
    for(i=0; i<height; ++i){
        for(j=0; j<width; ++j){
            if(map[i*width+j] == 'b')
                map[i*width+j] = 'o';
        }
    }
    map[index] = 'b';
}








// This function takes as argument a "GDBusProxy", five int "speed", "width", "height", "sizeCell", "orientation",
// an int tabular "pathToFollow", an int pointer "sizePath" and a string "map". The function allows 
// the robot to follow the path "pathToFollow" at the speed "speed"
// and the parameters of the path are defined by the "orientation" of the robot, the size of
// the path "sizePath" and the size of each cell of the path "sizeCell"
// if the robot encounter a obstacle he update the map "map" which is defined by
// the parameters "width", "height" and "sizeCell"
// The value of "speed" must be between -500 and 500
// The value of "orientation" must be 0 or 90 or 180 or 270, it's a angle

// STATIC ENVIRONMENT
int executePathChecked(GDBusProxy *proxy, int speed, char* map, int width, int height, int* pathToFollow, int* sizePath, int sizeCell, int orientation){
    
    if (*sizePath == -1){
        printf("Trying to execute a checked path, but path is empty.\n");
        return orientation;
    }
    
    
    
    
    int i, j, indexActual, indexEndPoint;
    int distanceTravelled = 0;
    
    for(i=0; i<height; ++i){
        for(j=0; j<width; ++j){
            if(map[i*width+j] == 'b')
                indexActual = i*width+j;
            
            if(map[i*width+j] == 'e')
                indexEndPoint = i*width+j;
        }
    }
    
    
    
    bool endReached = false;
    
    while (!endReached){
        
        if (*sizePath == -1){
            printf("No existing path to end point.\n");
            addXMap(map, width, width, indexEndPoint);
            moveBMap(map, width, height, indexActual);
            
            // For debug :
            int k;
            for(k=0; k<width; ++k){
                for(j=0; j<width; ++j){
                    printf("%c",map[k*width+j]);
                }
                printf("\n");
            }
            
            return orientation;
        }
        
        for(i=0; i<(*sizePath)-1; ++i){
            //printf("FOR : %d, %d -> %d\n", i, pathToFollow[i], pathToFollow[i+1]);
            // 4 possibles cases : top, right, bottom, left AND ORIENTED TOP <= need to be modified at some point
            
            printf("New step : %d -> %d\n", pathToFollow[i], pathToFollow[i+1]);
            indexActual = pathToFollow[i];
            indexEndPoint = pathToFollow[(*sizePath)-1];
            
            // TOP
            if(pathToFollow[i] > pathToFollow[i+1] && pathToFollow[i] > pathToFollow[i+1]+1) {
                
                if(orientation == 90){
                    turnRight(proxy, 90, speed, 4.90);
                    orientation = 0;
                }
                
                if(orientation == 180){
                    turnRight(proxy, 180, speed, 4.90);
                    orientation = 0;
                }
                
                if(orientation == 270){
                    turnLeft(proxy, 90, speed, 4.90);
                    orientation = 0;
                }
                
                
            }
            
            
            
            
            
            
            // RIGHT
            if(pathToFollow[i] < pathToFollow[i+1] && pathToFollow[i]+1 == pathToFollow[i+1]) {
                if(orientation == 0){
                    turnRight(proxy, 90, speed, 4.90);
                    orientation = 270;
                }
                
                if(orientation == 90){
                    turnRight(proxy, 180, speed, 4.90);
                    orientation = 270;
                }
                
                if(orientation == 180){
                    turnLeft(proxy, 90, speed, 4.90);
                    orientation = 270;
                }
                
                
            }
            
            
            
            
            
            
            
            
            // BOTTOM
            if(pathToFollow[i] < pathToFollow[i+1] && pathToFollow[i]+1 < pathToFollow[i+1]) {
                if(orientation == 0){
                    turnRight(proxy, 180, speed, 4.90);
                    orientation = 180;
                }
                
                if(orientation == 90){
                    turnLeft(proxy, 90, speed, 4.90);
                    orientation = 180;
                }
                
                
                if(orientation == 270){
                    turnRight(proxy, 90, speed, 4.90);
                    orientation = 180;
                }
                
            }
            
            
            
            
            
            // LEFT
            if(pathToFollow[i] > pathToFollow[i+1] && pathToFollow[i] == pathToFollow[i+1]+1) {
                if(orientation == 0){
                    turnLeft(proxy, 90, speed, 4.90);
                    orientation = 90;
                }
                
                if(orientation == 180){
                    turnRight(proxy, 90, speed, 4.90);
                    orientation = 90;
                }
                
                if(orientation == 270){
                    turnRight(proxy, 180, speed, 4.90);
                    orientation = 90;
                }
                
                
            }
            
            
            
            distanceTravelled = linearMoveDistanceChecked(proxy, speed, sizeCell);
            if(distanceTravelled != -1){ // Has been stopped by an obstacle
                
                addXMap(map, width, width, pathToFollow[i+1]);
                moveBMap(map, width, height, pathToFollow[i]);
                if(*sizePath != -1){ // Should always be, or everything before is just weird.
                    free(pathToFollow);
                    printf("Liberee\n");
                }
                linearMoveDistanceUnchecked(proxy, -speed, distanceTravelled); // Step back from the obstacle, to the previous cell
                
                printf("Size path before : %d\n", *sizePath);
                pathToFollow=pathToTarget(sizePath, map, width, height); // re-compute a new path, but it may be non-existant now ; checked at the beginning of the while()
                printf("Size path after : %d\n", *sizePath);
                endReached = false;
                break;
            }
            if(distanceTravelled == -1){
                endReached = true;
                indexActual = pathToFollow[i+1];
                moveBMap(map, width, height, indexActual);
            }
            
            
            // For debug :
            int k;
            for(k=0; k<width; ++k){
                for(j=0; j<width; ++j){
                    printf("%c",map[k*width+j]);
                }
                printf("\n");
            }
            
            //printf("%d -> %d\n",pathToFollow[i], pathToFollow[i+1]);
        }
    }
    
    // For debug :
    int k;
    for(k=0; k<width; ++k){
        for(j=0; j<width; ++j){
            printf("%c",map[k*width+j]);
        }
        printf("\n");
    }
    return orientation;
}




