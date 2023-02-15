#include <stdio.h>
#include"structures.h"

void decideWinner (struct Players *playersArrayPointer, int numberOfPlayers){
    int winnerscore = 0,winner[numberOfPlayers], i=0;
    for(int a = 0;a < numberOfPlayers;a++){
        if(playersArrayPointer[a].score > winnerscore){
            winnerscore = playersArrayPointer[a].score;
        }
    }
    // get the highest score
    printf("The highest score is %d.",winnerscore);
    for(int a = 0;a < numberOfPlayers;a++){
        if(playersArrayPointer[a].score == winnerscore){
            winner[i] = a;
            i ++;
        }
    }
    // get the number of players have the highest score
    if (i > 1){
        for(int a = 0;a < i;a++){
            if(a == 0){
                printf("\n%s and ",playersArrayPointer[winner[a]].name);
            }
            else if(a == i-1){
                printf("%s are winners \n",playersArrayPointer[winner[a]].name);
            }
            else
                printf("%s , ",playersArrayPointer[winner[a]].name);
        }
    }
    else
        printf("\n%s is a winner! Congratulations! \n",playersArrayPointer[winner[0]].name);
    // if there are two or more winners then use if(i>1)...
    // if only one then use else....
}