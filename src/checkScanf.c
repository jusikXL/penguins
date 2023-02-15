#include <stdio.h>
#include "checkScanf.h"

void checkScanfFirst(int value_return, int *value){
    while(value_return != 1) {
        scanf("%*[^\n]");
        printf("Try again: ");
        value_return = scanf(" %d", value);
    }
}

void checkScanfSecond(int value_return, char *value){
    while(value_return != 1) {
        scanf("%*[^\n]");
        printf("Try again: ");
        value_return = scanf(" %s", value);
    }
}

void checkScanfThird(int value_return, int *value_1, int *value_2, int gridSize){
    while(value_return != 2 || *value_1<1 || *value_1>gridSize || *value_2<1 || *value_2>gridSize) {
        scanf("%*[^\n]");
        printf("Try again: ");
        value_return = scanf("%d %d", value_1, value_2);
    }
}

void checkScanfFourth(int value_return, int *value, int numberOfPenguins){
    while(value_return != 1 || *value<1 || *value>numberOfPenguins) {
        scanf("%*[^\n]");
        printf("Try again: ");
        value_return = scanf(" %d", value);
    }
}