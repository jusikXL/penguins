#include <stdio.h>
#include "structures.h"
#include "printPenguinsArray.h"

void printPenguinsArray(struct Penguins * penguinsArrayPointer, int numberOfPlayers, int numberOfPenguins){
    printf("Array of penguins: \n");
    for(int i=0; i<numberOfPenguins; i++){ 
        for(int j=0; j<numberOfPlayers; j++){
            int *x = &(penguinsArrayPointer[numberOfPenguins*j + i].x);
            int *y = &(penguinsArrayPointer[numberOfPenguins*j + i].y); 
            printf("(%d,%d)", *x, *y);
        }
        printf("\n");
    }
}