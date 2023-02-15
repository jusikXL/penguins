#include <stdio.h>
#include "structures.h"
#include "choosePenguin.h"
#include "colors.h"
#include "checkScanf.h"
#include "printGrid.h"
#include "checkPenguinMovable.h"
#include "endGame.h"

int choosePenguin(struct Players *playersArrayPointer, struct Penguins *penguinsArrayPointer, int numberOfPenguins, int *chosenPenguin, int j, int *grid, int gridSize, int phase)
{
    switch (j)
    {
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
    printf(", choose a penguin: ");
    int chosenPenguin_return = scanf("%d", chosenPenguin);
    checkScanfFourth(chosenPenguin_return, chosenPenguin, numberOfPenguins);
    int *x = &(penguinsArrayPointer[numberOfPenguins * j + (*chosenPenguin) - 1].x);
    int *y = &(penguinsArrayPointer[numberOfPenguins * j + (*chosenPenguin) - 1].y);

    checkPenguinMovable(penguinsArrayPointer, numberOfPenguins, grid, gridSize, chosenPenguin, x, y, j);

    while (penguinsArrayPointer[numberOfPenguins * j + (*chosenPenguin) - 1].MoveLable == 0)
    {
        printf("Choose another: ");
        chosenPenguin_return = scanf("%d", chosenPenguin);
        checkScanfFourth(chosenPenguin_return, chosenPenguin, numberOfPenguins);
        if (penguinsArrayPointer[numberOfPenguins * j + (*chosenPenguin) - 1].MoveLable != 0)
        {
            x = &(penguinsArrayPointer[numberOfPenguins * j + (*chosenPenguin) - 1].x);
            y = &(penguinsArrayPointer[numberOfPenguins * j + (*chosenPenguin) - 1].y);
            break;
        }
    }

    printf("Your penguin %d has coordinates: (%d,%d)\n", *chosenPenguin, *x, *y);
    printf("Here are places where you can move: \n");

    printGrid(grid, gridSize, phase, *x, *y);

    return 1;
}