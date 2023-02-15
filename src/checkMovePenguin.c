#include <stdio.h>
#include <math.h>
#include "structures.h"
#include "movePenguin.h"
#include "checkMovePenguin.h"

int checkMovePenguin(int *grid, int gridSize,int *a,int *b,int *c,int *d){
       
        if (*a == *c && *b == *d){
            printf("are you kiding me? you want to stay at same grid? \n");
            printf("try again: ");
            return 0;
            

        }
        else if(*(grid + (*d - 1)*gridSize + (*c - 1))=='A'||*(grid + (*d - 1)*gridSize + (*c - 1))=='B'||*(grid + (*d - 1)*gridSize + (*c - 1))=='C'||*(grid + (*d - 1)*gridSize + (*c - 1))=='D'){
            printf("you can't move your penguin to another penguin, are you stupid ?! \n");
            printf("try again: ");
            return 0;

        }
        else if (*a != *c && *b != *d){
            printf("you can only move along y-axis or x-axis !!! \n");
            printf("try again: ");
            return 0;

        }

        else if(*(grid + (*d - 1)*gridSize + (*c - 1))=='X'){
            printf("you can't go on places with X !!! \n");
            printf("try again: ");
            return 0;
        }
        else{
            if(*a != *c && *a > *c){//go left
                for(int a1 = *c+1;a1 < *a;a1++){
                    if(*(grid + (*d - 1)*gridSize + (a1-1)) == 'A'||*(grid + (*d - 1)*gridSize + (a1-1)) == 'B'||*(grid + (*d - 1)*gridSize + (a1-1)) == 'C'||*(grid + (*d - 1)*gridSize + (a1-1)) == 'D'){
                        printf("you can't move your penguin after another penguin! \n");
                        printf("try again: ");
                        return 0; 
                                   
                    }
                    else if(*(grid + (*d - 1)*gridSize + (a1-1)) == 'X'){
                        printf("you can't move your penguin after an ice float \n");
                        printf("try again: ");
                        return 0;

                    }
                }
            }
            else if(*a != *c && *a < *c){//go right
                for(int a1 = *a+1;a1 < *c;a1++){
                    if(*(grid + (*d - 1)*gridSize + (a1-1)) == 'A'||*(grid + (*d - 1)*gridSize + (a1-1)) == 'B'||*(grid + (*d - 1)*gridSize + (a1-1)) == 'C'||*(grid + (*d - 1)*gridSize + (a1-1)) == 'D'){
                        printf("you can't move your penguin after another penguin! \n");
                        printf("try again: ");
                        return 0;
                       
                    }
                    else if(*(grid + (*d - 1)*gridSize + (a1-1)) == 'X'){
                        printf("you can't move your penguin after an ice float \n");
                        printf("try again: ");
                        return 0; 
                      
                    }
                }
            }
            else if(*b != *d && *b > *d){//go up
                for(int a1 = *d+1;a1 < *b;a1++){
                    if(*(grid + (a1 - 1)*gridSize + (*a-1)) == 'A'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'B'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'C'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'D'){
                        printf("you can't move your penguin after another penguin! \n");
                        printf("try again: ");
                        return 0;
                       
                    }
                    else if(*(grid + (a1 - 1)*gridSize + (*a-1)) == 'X'){
                        printf("you can't move your penguin after an ice float \n");
                        printf("try again: ");
                        return 0;
                       
                    }
                }
            }
            else if(*b != *d && *b < *d){//go down
                for(int a1 = *b+1;a1 < *d;a1++){
                    if(*(grid + (a1 - 1)*gridSize + (*a-1)) == 'A'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'B'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'C'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'D'){
                        printf("you can't move your penguin after another penguin! \n");
                        printf("try again: ");
                        return 0; 
                      
                    }
                    else if(*(grid + (a1 - 1)*gridSize + (*a-1)) == 'X'){
                        printf("you can't move your penguin after an ice float \n");
                        printf("try again: ");
                        return 0;
                       
                    }
                }
            }
        }       
        
                  
    
    return 7;
}