#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

#include "checkInput.h"
#include "askInput.h"
#include "createGrid.h"
#include "determineGridSize.h"
#include "checkGeneralPlacementAbility.h"
#include "printGrid.h"
#include "printPenguinsArray.h"
#include "placePenguins.h"
#include "colors.h"
#include "printScore.h"
#include "printPlayerPenguins.h"
#include "choosePenguin.h"
#include "movePenguin.h"
#include "askForNames.h"
#include "CheckMovablePlace.h"
#include "CheckPenguinMovable.h"
#include "decideWinner.h"
#include "endGame.h"
#include "checkPlayerMovable.h"

int main()
{

//STAGE 1: GENERATING BOARD

    red();
    phase = Generation;
    printf("\n*****Generation phase*****\n\n");
    reset();

    int numberOfPlayers=0;
    int numberOfPenguins=0;
    int totalNumberOfPenguins = 0;
    
    askInput(&numberOfPlayers, &numberOfPenguins);
    //asks user for input and assigns it to the variables;

    while(checkInput(numberOfPlayers, numberOfPenguins) == 0){
        askInput(&numberOfPlayers, &numberOfPenguins);
    }
    //checks if input is correct, returns 0 if NOT -> program asks again for input;


    struct Players playersArray[numberOfPlayers];
    struct Players *playersArrayPointer;
    playersArrayPointer = &playersArray[0];

    askForNames(playersArrayPointer, numberOfPlayers);
    

    int gridSize=0;
    determineGridSize(numberOfPlayers, numberOfPenguins, &totalNumberOfPenguins, &gridSize);


    int *grid;
    grid = calloc(gridSize*gridSize, sizeof(int));

    srand(time(NULL));
    //necessary to generate random numbers
    createGrid(grid,gridSize);
    //creates and fills array with values for future board generation;
    printGrid(grid,gridSize, phase,0,0);

//STAGE 2: PLACEMENT
    
    red();
    phase = Placement;
    printf("\n*****Placement phase*****\n\n");
    reset();

    checkGeneralPlacementAbility(grid,gridSize,totalNumberOfPenguins);
    //checks if there is enough places with 1 fish to put each player;
    //If YES -> returns 1. If NOT -> returns 0, regenerates board until there is enough 1s;

    struct Penguins penguinsArray[numberOfPlayers][numberOfPenguins];
    //2D array of penguins' structures (each element of array contains x and y coordinate). 
    //axises - numberOfPlayers, numberOfPenguins 
    struct Penguins *penguinsArrayPointer;
    penguinsArrayPointer = &penguinsArray[0][0];
    //pointer to penguinsArray

    placePenguins(penguinsArrayPointer, numberOfPlayers, numberOfPenguins, grid, gridSize, playersArrayPointer);
    //places penguins
    
    printPenguinsArray(penguinsArrayPointer, numberOfPlayers, numberOfPenguins);
    //prints penguinsArray

    printScore(playersArrayPointer, numberOfPlayers);

//STAGE 3: MOVEMENT

    int chosenPenguin=0,endflag=0,endnumber,blockedPlayer,p;
    // endflag == ;1 game end;0 game continue;
    // endnumber is for identify game end after placemnet or during movement
    // blockedplayer is for show who can't move
    // p get the number from checkPlayerMovable,if one player can't move it output the number of player,if normal output 10

    p = checkPlayerMovable(playersArrayPointer,penguinsArrayPointer,numberOfPenguins,numberOfPlayers,grid,gridSize);
    if(p != 10){
        endflag = 1;
        endnumber = 100;
        blockedPlayer = p;
        endGame(playersArrayPointer,numberOfPlayers,endnumber,blockedPlayer);
        return 0;                
    }
    //check whether game can continue or not after placement

    phase = Movement;
    red();
    printf("\n*****Movement phase*****\n\n");
    reset();

    while(endflag == 0 /*while game continues*/ ){

        for(int j=0; j<numberOfPlayers; j++){
            //goes player-by-player
           
            printPlayerPenguins(playersArrayPointer, penguinsArrayPointer, numberOfPenguins, j,grid,gridSize);
            //prints the player's penguins to be chosen

            phase = Choose;
            choosePenguin(playersArrayPointer, penguinsArrayPointer, numberOfPenguins, &chosenPenguin, j,grid,gridSize,phase);
            phase = Movement;
            //asks to choose penguin and checks if chosen penguin can move    

            movePenguin(playersArrayPointer, penguinsArrayPointer, numberOfPenguins, grid, gridSize, &chosenPenguin, j);
            //asks to move penguin and checks if move is legal

            p = checkPlayerMovable(playersArrayPointer,penguinsArrayPointer,numberOfPenguins,numberOfPlayers,grid,gridSize);
            if(p != 10){
                endflag = 1;
                endnumber = 0;
                blockedPlayer = p;
            } 
            //checks if one player can't move

            printGrid(grid,gridSize,phase,0,0);
            //prints board

            printScore(playersArrayPointer, numberOfPlayers);
            //prints scores of players
      
        }
        if(endflag == 1){
            endGame(playersArrayPointer,numberOfPlayers,endnumber,blockedPlayer);
            // let game end until one turn
            //starts ending phase in other case: determines winner, prints the end of the game            
        }
        
    }


    return 0;
}