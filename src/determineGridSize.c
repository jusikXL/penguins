#include <math.h>
#include <stdio.h>
#include "determineGridSize.h"
void determineGridSize(int numberOfPlayers, int numberOfPenguins, int *totalNumberOfPenguins, int *gridSize){
    *totalNumberOfPenguins = numberOfPlayers*numberOfPenguins;
    *gridSize = ceil(sqrt(50*(*totalNumberOfPenguins)))+2;
    //printf("Size: %d\n", *gridSize);
}