#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "createGrid.h"

int randomNum(){
//returns random numbers ~20% "0" and ~80% "1-3" to fill the array
    int num = (rand() % (100 - 1 + 1)) + 1;
    int upper = 51;
    int lower = 49;
    if (num <= 20){
        return 88;
    }
    else if (num > 20){
        return (rand() % (upper - lower + 1)) + lower;
    }
    else{
        return 9;
    }
}


int randomNum1(){
//returns random numbers ~99% "0" and ~1% "1" to fill the array
    int num = (rand() % (100 - 1 + 1)) + 1;
    if (num <= 99){
        return 0;
    }
    else if (num > 99){
        return 1;
    }
    else{
        return 9;
    }
}


void createGrid(int *grid, int gridSize){
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            int *gridElement = &grid[j*gridSize + i];
            if(i==0 || i==(gridSize-1) || j==0 || j==(gridSize-1))
                *gridElement = 'X'; //*(grid + j*gridSize + i)='X'
            else
                *gridElement = randomNum();
            //printf("%d ", *(grid + j*gridSize + i));
        }
        //printf("\n");
    }
    int counter = 0;
    int counterZero = 0;
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            int gridElement = grid[j*gridSize + i];
            if(gridElement != 'X'){
                counter++;
            }
            else if(gridElement == 'X'){
                counterZero++;
            }
        }
    }
    //printf("Number of 1s,2s,3s is: %d. Number of X is: %d\n",counter,counterZero);
}