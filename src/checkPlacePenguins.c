#include <stdio.h>
#include "structures.h"
#include "placePenguins.h"
#include "checkPlacePenguins.h"
#include "checkScanf.h"

void checkPlacePenguins(struct Penguins * penguinsArrayPointer, int numberOfPlayers, int numberOfPenguins, int * grid, int gridSize,int i,int j, struct Players *playersArrayPointer){
    if (*(grid + ((*(penguinsArrayPointer + numberOfPenguins*j + i)).y - 1)*gridSize + ((*(penguinsArrayPointer + numberOfPenguins*j + i)).x - 1))=='2' 
                    || *(grid + ((*(penguinsArrayPointer + numberOfPenguins*j + i)).y - 1)*gridSize + ((*(penguinsArrayPointer + numberOfPenguins*j + i)).x - 1))=='3'
                    || *(grid + ((*(penguinsArrayPointer + numberOfPenguins*j + i)).y - 1)*gridSize + ((*(penguinsArrayPointer + numberOfPenguins*j + i)).x - 1))=='X'){
                    printf("You can only place your penguin on the float with one fish!!! \n");
                    printf("%s, place a penguin again! *template: 'x y'\n", (*(playersArrayPointer + j)).name);
                    printf("Coordinates: ");
                    int coordinate_return = scanf("%d %d", 
                    &((*(penguinsArrayPointer + numberOfPenguins*j + i)).x), 
                    &((*(penguinsArrayPointer + numberOfPenguins*j + i)).y)
                    );
                    checkScanfThird(coordinate_return, &((*(penguinsArrayPointer + numberOfPenguins*j + i)).x), &((*(penguinsArrayPointer + numberOfPenguins*j + i)).y), gridSize);               
                }   
                else {
                    printf("You can't place your penguin on another penguin!!! \n");
                    printf("%s, place a penguin! *template: 'x y'\n", (*(playersArrayPointer + j)).name);;
                    printf("Coordinates: ");
                    int coordinate_return = scanf("%d %d", 
                    &((*(penguinsArrayPointer + numberOfPenguins*j + i)).x), 
                    &((*(penguinsArrayPointer + numberOfPenguins*j + i)).y)
                    );
                    checkScanfThird(coordinate_return, &((*(penguinsArrayPointer + numberOfPenguins*j + i)).x), &((*(penguinsArrayPointer + numberOfPenguins*j + i)).y), gridSize);              
                }
}