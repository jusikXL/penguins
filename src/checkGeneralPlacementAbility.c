#include <stdio.h>
#include "checkGeneralPlacementAbility.h"
#include "createGrid.h"

int checkGeneralPlacementAbility(int *grid, int gridSize, int totalNumberOfPenguins){
    int counterOne = 0;
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            int gridElement = grid[j*gridSize + i];
            if(gridElement == '1'){
                counterOne++;
            }
        }
    }
    //printf("Number of 1s is: %d\n", counterOne);
    if(counterOne<totalNumberOfPenguins){
        printf("Not enough places to put penguins. Regenaration array...\n");
        createGrid(grid,gridSize);
        checkGeneralPlacementAbility(grid,gridSize,totalNumberOfPenguins);
        return 0;
    }
    return 1;
}