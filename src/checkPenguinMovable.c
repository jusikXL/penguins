#include <stdio.h>
#include "structures.h"
#include "checkMovablePlace.h"
#include "checkPenguinMovable.h"

int checkPenguinMovable(struct Penguins * penguinsArrayPointer,int numberOfPenguins, int * grid, int gridSize, int *chosenPenguin,int *x,int *y,int j){
    
    int movementAbility;

    for (int a = 0; a < gridSize; a++){
        for (int b = 0; b < gridSize; b++){
            if(checkMovablePlace(grid, gridSize,x,y,&a,&b) != 0){
                movementAbility = 1;
                penguinsArrayPointer[numberOfPenguins*j + (*chosenPenguin)-1].MoveLable = 1;
                return movementAbility;                          
            }
            else if(a == gridSize-1 && b == gridSize-1 && checkMovablePlace(grid, gridSize,x,y,&a,&b) == 0 ){
                movementAbility = 0;
            }
        }
    }

    penguinsArrayPointer[numberOfPenguins*j + (*chosenPenguin)-1].MoveLable = 0;
    return movementAbility;

}