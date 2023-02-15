#include <stdio.h>
#include "structures.h"
#include "printScore.h"

void printScore(struct Players *playersArrayPointer, int numberOfPlayers){
    printf("Scores of Players: ");
    for(int i=0; i<numberOfPlayers; i++){
        printf("%d ", playersArrayPointer[i].score);
    }
    printf("\n");
}