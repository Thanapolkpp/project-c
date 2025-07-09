#include<stdio.h>


void go (int row,int collum){
  printf("\033[%d;%dH",row,collum);
}


int main ()
{
    go(2,50);
    printf("\033[32mhello");
}