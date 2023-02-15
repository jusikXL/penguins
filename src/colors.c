#include <stdio.h>
#include "colors.h"
void green(){
  printf("\033[0;32m");
};

void red(){
  printf("\033[1;31m");
};

void blue(){
  printf("\033[0;34m");
};

void reset(){
  printf("\033[0m");
};

void black(){
  printf("\033[0;90m");
};

void cyan(){
  printf("\033[0;36m");
};

void yellow(){
  printf("\033[0;33m");
};

void purple(){
  printf("\033[0;35m");
};