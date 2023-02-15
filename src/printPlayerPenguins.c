#include <stdio.h>
#include "structures.h"
#include "printPlayerPenguins.h"
#include "colors.h"
#include "checkPenguinMovable.h"

void printPlayerPenguins(struct Players *playersArrayPointer, struct Penguins *penguinsArrayPointer, int numberOfPenguins, int j, int *grid, int gridSize)
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
    printf(", your turn! You have penguins with coordinates: \n");
    for (int i = 1; i <= numberOfPenguins; i++)
    {
        int *x = &(penguinsArrayPointer[numberOfPenguins * j + (i - 1)].x);
        int *y = &(penguinsArrayPointer[numberOfPenguins * j + (i - 1)].y);
        switch (checkPenguinMovable(penguinsArrayPointer, numberOfPenguins, grid, gridSize, &i, x, y, j))
        {
        case 1:
            green();
            break;
        case 0:
            red();
            break;
        }
        printf("(%d,%d)\n", *x, *y);
        reset();
    }
    printf("\n");
}