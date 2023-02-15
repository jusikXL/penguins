#include <stdio.h>
#include "structures.h"
#include "checkPenguinMovable.h"

int checkPlayerMovable(struct Players *playersArrayPointer, struct Penguins *penguinsArrayPointer, int numberOfPenguins, int numberOfPlayers, int *grid, int gridSize)
{
    
    for (int players = 0; players < numberOfPlayers; players++)
    {   
        int flag = 0;
        for (int a = 1; a < numberOfPenguins+1; a++)
        {
            
            int x1 = penguinsArrayPointer[numberOfPenguins * players + a - 1].x;
            int y1 = penguinsArrayPointer[numberOfPenguins * players + a - 1].y;

            if (checkPenguinMovable(penguinsArrayPointer, numberOfPenguins, grid, gridSize, &a, &x1, &y1, players) == 0)
            {   
                
                flag++;
            };
        }
        if (flag == numberOfPenguins)
        {
            return players;
        }
    }
    
    return 10;
}