#include "map.h"


#define TAILLE_MAX 1000



// This function takes as arguments a "string" to indicate the path to the map file and three int pointers 
// width, height and sizeCell that will be retrieved from the map file
void sizeMap(char* path, int* width, int* height, int* sizeCell){
    FILE* file = NULL;
    file = fopen(path, "r");
    
    
    if(file != NULL){
        /*
         *width = fgetc(file);
         *height = fgetc(file);
         *sizeCell = fgetc(file);
         */
        fscanf(file, "%d %d %d", width, height, sizeCell);
        //printf("Width %d, height %d, sizeCell %d\n", *width, *height, *sizeCell);
        
        fclose(file);
    }
    else{
        printf("File %s could not be opened.\n", path);
    }
}






// This function takes as arguments a "string" to indicate the path to the map file, another who will receive the map, 
// an int for the width of the map and another for the height
void toMap(char* path, char* map, int width, int height){
    
    FILE* file = NULL;
    file = fopen(path, "r");
    
    if(file != NULL){
        int i, j;
        char chaine[TAILLE_MAX] = ""; // Chaine vide de taille TAILLE_MAX
        
        fgets(chaine, TAILLE_MAX, file); // first line with width, height, sizeCell
        
        
        for(i=0; i<height; i++){
            for (j=0; j<width; j++) {
                map[i*width+j] = fgetc(file);
                //printf("%c", map[i*width+j]);
            }
            fgetc(file);
            //printf("\n");
        }
        
        fclose(file);
    }
    else{
        printf("File %s could not be opened.\n", path);
    }
    
    
}



// This function takes as arguments a "string" to indicate the path to file who will receive the map,
// another one that contains the map to write to the file and three int for the width, the height and
// the cell size of the map
void writeMap(char* path, char* map, int width, int height, int sizeCell){
    
    FILE* file = NULL;
    file = fopen(path, "w+");
    
    if(file != NULL){
        int i, j;
        
        fprintf(file, "%d %d %d\n", width, height, sizeCell);
        
        for(i=0; i<height; i++){
            for (j=0; j<width; j++) {
                fputc(map[i*width+j], file);
            }
            fputs("\n", file);
        }
        
        fclose(file);
    }
    else{
        printf("File %s could not be opened.\n", path);
    }
    
    
}

