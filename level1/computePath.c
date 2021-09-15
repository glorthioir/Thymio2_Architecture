#include "computePath.h"





int* pathToTarget(int* sizePath, char* map, int width, int height){
    
    int i, j, iEnd, jEnd, iBeg, jBeg;
    int iActual, jActual;
    int iDiffEnd, jDiffEnd;
    bool initF = false, eFound=false, bFound=false;
    //printf("Plus tot\n");
    
    Cell* mapCell = malloc(width*height*sizeof(Cell));
    
    //printf("Debut\n");
    
    
    // Initilizating mapCell
    for(i=0; i<height; ++i){
        for(j=0; j<width; ++j){
            
            mapCell[i*width+j].i = i;
            mapCell[i*width+j].j = j;
            
            
            mapCell[i*width+j].open = false; // All cells are closed except for the b cell
            mapCell[i*width+j].father = NULL;
            mapCell[i*width+j].g = 0;
            
            // Initializing obstacles
            if(map[i*width+j] == 'o')
                mapCell[i*width+j].obstacle = false;
            if(map[i*width+j] == 'x')
                mapCell[i*width+j].obstacle = true;
            
            if(map[i*width+j]=='e'){
                mapCell[i*width+j].obstacle = false;
                mapCell[i*width+j].open = true;
                
                mapCell[i*width+j].father = &(mapCell[i*width+j]); // Father of the begenning point is itself
                iActual = i;
                jActual = j;
                iBeg = i;
                jBeg = j;
                eFound = true;
            }
            if (map[i*width+j]=='b') {
                mapCell[i*width+j].obstacle = false;
                iEnd = i;
                jEnd = j;
                bFound = true;
            }
            
        }
    }
    
    if(!eFound){
        *sizePath = -1;
        printf("No \"e\" on the map. Robot don't know where to go.\n");
        return NULL;
    }
    
    if(!bFound){
        *sizePath = -1;
        printf("No \"b\" on the map. Robot is lost.\n");
        return NULL;
    }
    
    
    
    
    // Initializing h
    for(i=0; i<height; ++i){
        for(j=0; j<width; ++j){
            
            iDiffEnd = i - iEnd;
            jDiffEnd = j - jEnd;
            
            if(iDiffEnd < 0)
                iDiffEnd = -iDiffEnd;
            if(jDiffEnd < 0)
                jDiffEnd = -jDiffEnd;
            
            mapCell[i*width+j].h = iDiffEnd + jDiffEnd;
            
        }
    }
    
    
    // Only g is not initialized yet
    
    //printf("Middle\n");
    
    // 4 directions to check : top, right, bottom, left
    bool endReached = false;
    int f = -1;
    //int iBefore, jBefore;
    
    while (!endReached) {
        
        //printf("TOP\n");
        // TOP
        if(iActual-1 >= 0){ // Cell of the table
            if(mapCell[(iActual-1)*height+jActual].obstacle == false){ // No obstacle
                if(mapCell[(iActual-1)*height+jActual].g == 0 && (iActual-1 != iBeg || jActual != jBeg)){ // Never been explored
                    mapCell[(iActual-1)*height+jActual].g = mapCell[iActual*height+jActual].g + 1;
                    mapCell[(iActual-1)*height+jActual].father = &(mapCell[iActual*height+jActual]);
                    mapCell[(iActual-1)*height+jActual].open = true; // open it
                }
                else{ // Has been explored
                    if( mapCell[(iActual-1)*height+jActual].g > mapCell[iActual*height+jActual].g + 1){ // if better, update
                        mapCell[(iActual-1)*height+jActual].g = mapCell[iActual*height+jActual].g + 1;
                        mapCell[(iActual-1)*height+jActual].father = &(mapCell[iActual*height+jActual]);
                    }
                }
            }
        }
        
        
        
        
        
        //printf("RIGHT\n");
        // RIGHT
        if(jActual+1 < width){ // Cell of the table
            if(mapCell[iActual*height+(jActual+1)].obstacle == false){ // No obstacle
                if(mapCell[iActual*height+(jActual+1)].g == 0 && (iActual != iBeg || jActual+1 != jBeg)){ // Never been explored
                    mapCell[iActual*height+(jActual+1)].g = mapCell[iActual*height+jActual].g + 1;
                    mapCell[iActual*height+(jActual+1)].father = &(mapCell[iActual*height+jActual]);
                    mapCell[iActual*height+(jActual+1)].open = true; // open it
                }
                else{ // Has been explored
                    if( mapCell[iActual*height+(jActual+1)].g > mapCell[iActual*height+jActual].g + 1){ // if better then update
                        mapCell[iActual*height+(jActual+1)].g = mapCell[iActual*height+jActual].g + 1;
                        mapCell[iActual*height+(jActual+1)].father = &(mapCell[iActual*height+jActual]);
                    }
                }
            }
        }
        
        
        
        
        //printf("Bottom\n");
        // BOTTOM
        if(iActual+1 < height){ // Cell of the table
            //printf("Test1\n");
            if(mapCell[(iActual+1)*height+jActual].obstacle == false){ // No obstacle
                //printf("Test2\n");
                if(mapCell[(iActual+1)*height+jActual].g == 0 && (iActual+1 != iBeg ||jActual != jBeg)){ // Never been explored
                    mapCell[(iActual+1)*height+jActual].g = mapCell[iActual*height+jActual].g + 1;
                    mapCell[(iActual+1)*height+jActual].father = &(mapCell[iActual*height+jActual]);
                    mapCell[(iActual+1)*height+jActual].open = true; // open it
                }
                else{ // Has been explored
                    //printf("Test3\n");
                    if( mapCell[(iActual+1)*height+jActual].g > mapCell[iActual*height+jActual].g + 1){ // if better, update
                        printf("Test4\n");
                        mapCell[(iActual+1)*height+jActual].g = mapCell[iActual*height+jActual].g + 1;
                        mapCell[(iActual+1)*height+jActual].father = &(mapCell[iActual*height+jActual]);
                    }
                }
            }
        }
        
        
        
        
        //printf("LEFT\n");
        // LEFT
        if(jActual-1 >= 0){ // Cell of the table
            if(mapCell[iActual*height+(jActual-1)].obstacle == false){ // No obstacle
                if(mapCell[iActual*height+(jActual-1)].g == 0 && ( iActual != iBeg || jActual-1 != jBeg)){ // Never been explored
                    mapCell[iActual*height+(jActual-1)].g = mapCell[iActual*height+jActual].g + 1;
                    mapCell[iActual*height+(jActual-1)].father = &(mapCell[iActual*height+jActual]);
                    mapCell[iActual*height+(jActual-1)].open = true; // open it
                }
                else{ // Has been explored
                    if( mapCell[iActual*height+(jActual-1)].g > mapCell[iActual*height+jActual].g + 1){ // if better, update
                        mapCell[iActual*height+(jActual-1)].g = mapCell[iActual*height+jActual].g + 1;
                        mapCell[iActual*height+(jActual-1)].father = &(mapCell[iActual*height+jActual]);
                    }
                }
            }
        }
        
        
        
        
        
        
        //printf("Close it and check if end\n");
        // Close it and check if end
        mapCell[iActual*height+jActual].open = false;
        
        if(iActual == iEnd && jActual == jEnd)
            endReached = true;
        
        
        // Choose a new one
        int iBefore = iActual, jBefore = jActual;
        f = 100000;
        initF = false;
        for(i=0; i<height; ++i){
            for(j=0; j<width; ++j){
                if(mapCell[i*width+j].open == true){ // for all open cells
                    if(!initF){
                        f = mapCell[i*width+j].g + mapCell[i*width+j].h;
                        iActual = i;
                        jActual = j;
                        initF = true;
                    }
                    
                    if(mapCell[i*width+j].g + mapCell[i*width+j].h < f){ // look for the smallest f
                        f = mapCell[i*width+j].g + mapCell[i*width+j].h;
                        iActual = i;
                        jActual = j;
                    }
                }
            }
        }
        
        if(iBefore == iActual && jBefore == jActual){
            *sizePath = -1;
            return NULL;
        }
        
    }
    
    
    /*for(i=0; i<width; ++i){
     for(j=0; j<height; ++j){
     printf("%c ",map[i*width+j]);
     }
     printf("\n");
     }
     printf("\n\n\n");
     for(i=0; i<width; ++i){
     for(j=0; j<height; ++j){
     printf("%d ",mapCell[i*width+j].h);
     }
     printf("\n");
     }
     */
    
    //printf("Ici\n");
    *sizePath = mapCell[iEnd*height+jEnd].g +1;
    int* pathToFollow = malloc((*sizePath) * sizeof(int));
    
    Cell actualCell = mapCell[iEnd*height+jEnd];
    //printf("La\n");
    for(i=0; i<*sizePath; ++i){
        pathToFollow[i] = actualCell.i * height + actualCell.j;
        actualCell = *(actualCell.father);
    }
    //printf("Finalement\n");
    
    free(mapCell);
    return pathToFollow;
    
}

