#include <stdio.h>
#include "checkInput.h"
int checkInput(int numberOfPlayersCheck, int numberOfPenguinsCheck){
    //check if the input is correct
    if(numberOfPlayersCheck<=1 || numberOfPenguinsCheck<=0){
        printf("Invalid number of players or penguins \n");
        return 0;
    }
    else if(numberOfPlayersCheck > 4){
        printf("The number of players is between 2 and 4 \n");
        return 0;
    }
    else if(numberOfPlayersCheck==2 && numberOfPlayersCheck*numberOfPenguinsCheck>10){
        printf("For 2 players the maximum number of penguins per each player is 5 \n");
        return 0;
    }
    else if(numberOfPlayersCheck==3 && numberOfPlayersCheck*numberOfPenguinsCheck>9){
        printf("For 3 players the maximum number of penguins per each player is 3 \n");
        return 0;
    }
    else if(numberOfPlayersCheck==4 && numberOfPlayersCheck*numberOfPenguinsCheck>12){
        printf("For 4 players the maximum number of penguins per each player is 3 \n");
        return 0;
    }
    else{
        //printf("Input is OK. ");
        //printf("Total number of Penguins is: %d.\n", numberOfPlayersCheck*numberOfPenguinsCheck);
        return 1;
    }
}