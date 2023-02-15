#include <stdio.h>
#include "askInput.h"
#include "checkScanf.h"

void askInput(int *numberOfPlayers, int *numberOfPenguins){

    printf("Input the number of players: ");
    int numberOfPlayers_return = scanf(" %d", numberOfPlayers);
    checkScanfFirst(numberOfPlayers_return, numberOfPlayers);


    printf("Input the number of penguins per each player: ");
    int numberOfPenguins_return = scanf(" %d", numberOfPenguins);
    checkScanfFirst(numberOfPenguins_return, numberOfPenguins);
}