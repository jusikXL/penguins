#include <stdio.h>
#include "structures.h"
#include "movePenguin.h"
#include "checkMovePenguin.h"
#include "colors.h"
#include "checkScanf.h"

void movePenguin(struct Players *playersArrayPointer, struct Penguins * penguinsArrayPointer, int numberOfPenguins, int *grid, int gridSize, int *chosenPenguin, int j){
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
    printf(", move a penguin %d. *template 1 2. Coordinates: ", (*chosenPenguin));

    int *x = &(penguinsArrayPointer[numberOfPenguins*j + (*chosenPenguin)-1].x);
    int *y = &(penguinsArrayPointer[numberOfPenguins*j + (*chosenPenguin)-1].y);
    int  c , d;

    grid[(*y - 1)*gridSize + (*x - 1)] = 'X';
    
    int coordinate_return = scanf("%d %d",&c,&d);
    checkScanfThird(coordinate_return, &c, &d, gridSize);

    while(checkMovePenguin(grid, gridSize,x,y,&c,&d) == 0){
        coordinate_return = scanf("%d %d",&c,&d);
        checkScanfThird(coordinate_return, &c, &d, gridSize);
    }
    *x = c;
    *y = d;

    penguinsArrayPointer[numberOfPenguins*j + (*chosenPenguin)-1].x = c;
    penguinsArrayPointer[numberOfPenguins*j + (*chosenPenguin)-1].y = d;

    playersArrayPointer[j].score += -48 + grid[(*y - 1)*gridSize + (*x - 1)];
            
    grid[(*y - 1)*gridSize + (*x - 1)] = 'A'+ j;
}