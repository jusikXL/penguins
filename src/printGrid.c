#include <stdio.h>
#include "CheckMovablePlace.h"
#include "printGrid.h"
#include "colors.h"
void printGrid(int *grid, int gridSize, int phase,int x,int y){

    printf("\n");
    printf("    ");
    int iterations = 0;
    int k=0;
    int count = 0;
    while(iterations < gridSize){
        
        if(k==9){
            k=-1;
        }
        printf("%d ", k+1);
        iterations++;
        k++;
    }

    printf("\n");
    printf("\n");
    for (int j = 0; j < gridSize; j++){
        if(j>=0 && j<9){
            printf("%d   ", j+1);
        }
        else{
            printf("%d  ", j+1);
        }
        for (int i = 0; i < gridSize; i++){
            
            int gridElement = grid[j*gridSize + i];

            if(gridElement=='X'){
                black();
            }

            if(phase==0 || phase==1){
                switch(gridElement){
                    case '1':
                        green();
                        break;
                }
            }

            if(phase==0 || phase==1 || phase==2|| phase==3){
                switch(gridElement){
                    case 'A':
                        yellow();
                        break;
                    case 'B':
                        cyan();
                        break;
                    case 'C':
                        purple();
                        break;
                    case 'D':
                        red();
                        break;
                }
            }
            

            if(phase == 3 && checkMovablePlace(grid, gridSize,&x,&y,&i,&j) != 0){
                
                green();
                count++;
                               
            }
            printf("%c ", gridElement);
            reset();
        }
        printf("\n");
    }
    printf("\n");
   
}