#include<stdio.h>
#include"structures.h"
#include"colors.h"
#include"decideWinner.h"

void endGame(struct Players *playersArrayPointer,int numberOfPlayers,int endnumber,int blockedPlayer){
                
        red();
        printf("\n*****end phase*****\n\n");
        reset();
        if(endnumber == 0){
                switch(blockedPlayer){
            case 0:
                yellow();
                break;
            case 1:
                cyan();
                break;
            case 2:
                purple();
                break;
            case 3:
                red();
                break;    
            }
            printf("%s", playersArrayPointer[blockedPlayer].name);
            reset();

            printf(", you can't move. \n");
            decideWinner(playersArrayPointer,numberOfPlayers);     
        }
        else if(endnumber == 100){
            printf("\ngame end after placemnet,because %s can't move, please restart this game \n",playersArrayPointer[blockedPlayer].name);
        }
        
        
}