#include <stdio.h>
#include "structures.h"
#include "askForNames.h"
#include "checkScanf.h"


void askForNames(struct Players *playersArrayPointer, int numberOfPlayers){
    for(int i=0; i<numberOfPlayers; i++){
        printf("The name of player %d is: ", i+1);
        int name_return = scanf(" %s", playersArrayPointer[i].name);
        checkScanfSecond(name_return, playersArrayPointer[i].name);
        //printf("%s\n", (*(playersArrayPointer + i)).name);
    }
}