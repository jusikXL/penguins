#include <stdio.h>
#include <math.h>
#include "structures.h"
#include "movePenguin.h"
#include "checkMovePenguin.h"

int checkMovablePlace(int *grid, int gridSize,int *a,int *b,int *c,int *d){

        if (*a == (*c+1) && *b == (*d+1)){
            
            return 0;
            

        }
        else if(*(grid + ((*d+1) - 1)*gridSize + ((*c+1) - 1))=='A'||*(grid + ((*d+1) - 1)*gridSize + ((*c+1) - 1))=='B'||*(grid + ((*d+1) - 1)*gridSize + ((*c+1) - 1))=='C'||*(grid + ((*d+1) - 1)*gridSize + ((*c+1) - 1))=='D'){
            
            return 0;

        }
        else if (*a != (*c+1) && *b != (*d+1)){
            
            return 0;

        }

        else if(*(grid + ((*d+1) - 1)*gridSize + ((*c+1) - 1))=='X'){
            
            return 0;
        }
        else{
            if(*a != (*c+1) && *a > (*c+1)){//go left
                for(int a1 = (*c+1)+1;a1 < *a;a1++){
                    if(*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'A'||*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'B'||*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'C'||*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'D'){
                        
                        return 0; 
                                   
                    }
                    else if(*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'X'){
                        
                        return 0;

                    }
                }
            }
            else if(*a != (*c+1) && *a < (*c+1)){//go right
                for(int a1 = *a+1;a1 < (*c+1);a1++){
                    if(*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'A'||*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'B'||*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'C'||*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'D'){
                        
                        return 0;
                       
                    }
                    else if(*(grid + ((*d+1) - 1)*gridSize + (a1-1)) == 'X'){
                        
                        return 0; 
                      
                    }
                }
            }
            else if(*b != (*d+1) && *b > (*d+1)){//go up
                for(int a1 = (*d+1)+1;a1 < *b;a1++){
                    if(*(grid + (a1 - 1)*gridSize + (*a-1)) == 'A'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'B'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'C'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'D'){
                       
                        return 0;
                       
                    }
                    else if(*(grid + (a1 - 1)*gridSize + (*a-1)) == 'X'){
                        
                        return 0;
                       
                    }
                }
            }
            else if(*b != (*d+1) && *b < (*d+1)){//go down
                for(int a1 = *b+1;a1 < (*d+1);a1++){
                    if(*(grid + (a1 - 1)*gridSize + (*a-1)) == 'A'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'B'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'C'||*(grid + (a1 - 1)*gridSize + (*a-1)) == 'D'){
                        
                        return 0; 
                      
                    }
                    else if(*(grid + (a1 - 1)*gridSize + (*a-1)) == 'X'){
                       
                        return 0;
                       
                    }
                }
            }
        }       
        
                  
    
    return 7;
}