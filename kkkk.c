#include <stdio.h>
int main(){
int i = 0;
char str[1000];
printf("Enter text :");
 gets(str);
 while(str[i] != '\0'){
     if(str[i] >= 'a' && str[i] <= 'z'){
        str[i] = str[i] - ('a' - 'A');
    }else if(str[i] >= 'A' && str[i] <= 'Z'){
        str[i] = str[i] + ('a' - 'A');
   }
    i++;}
 
 printf("text is : %s\n",str);
char x = 'a';
char y ='A';
printf(" %c ",99);
}