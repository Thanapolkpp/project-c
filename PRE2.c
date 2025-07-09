#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    
    fp = fopen("test.txt", "w");

    if (fp == NULL) {
        printf("error file\n");
        return 1; 
    }
else {
	scanf(" %c",&ch);
	 
}
    
    if (fclose(fp) == EOF) {
        printf("error closing file\n");
    }

    return 0;
}
