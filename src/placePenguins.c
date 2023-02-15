#include <stdio.h>
#include "structures.h"
#include "printGrid.h"
#include "placePenguins.h"
#include "checkPlacePenguins.h"
#include "colors.h"
#include "checkScanf.h"

void placePenguins(struct Penguins * penguinsArrayPointer, int numberOfPlayers, int numberOfPenguins, int * grid, int gridSize, struct Players *playersArrayPointer){
    for(int i=0; i<numberOfPenguins; i++){
        for(int j=0; j<numberOfPlayers; j++){
            int *x = &(penguinsArrayPointer[numberOfPenguins*j + i].x);
            int *y = &(penguinsArrayPointer[numberOfPenguins*j + i].y);
            playersArrayPointer[j].score = numberOfPenguins;
            switch(j){
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
            printf("%s", playersArrayPointer[j].name);
            reset();
            printf(", place a penguin! *template: 'x y'\n");
            printf("Coordinates: ");
            int coordinate_return = scanf("%d %d",x,y);
            checkScanfThird(coordinate_return, x, y, gridSize);
            //asks for place and assigns it to variables
            while(grid[(*y - 1)*gridSize + (*x - 1)] != '1'){
                checkPlacePenguins(penguinsArrayPointer, numberOfPlayers, numberOfPenguins, grid, gridSize,i,j,playersArrayPointer);
            }

            grid[(*y - 1)*gridSize + (*x - 1)] = 'A'+ j;
            printGrid(grid,gridSize, phase,0,0);
            //updates and prints board with penguins on it
        }
    }
}