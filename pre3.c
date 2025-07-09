#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h> // เพิ่มเพื่อใช้ system("cls")
#define max 100

int main() {
    int i, n;
    char name[max], password[max];
    int len,upper=0,digit=0;
    printf("hello");
    gets(name);
    printf("Enter your password  more than 8 and number : ");
    gets(password);

    do {
        if (strcmpi(name, password) == 0) {
            system("cls"); // ล้างหน้าจอ
            printf("Enter your name new: ");
            gets(name);
            printf("Enter your password new: ");
            gets(password);
        }

        len = strlen(password);
        while (len < 8) {
            printf("Enter your password more than 8 and number : ");
            gets(password);
            len = strlen(password);
        }

    } while (strcmpi(name, password) == 0);
    
    for (i = 0; password[i] != '\0'; i++) 
	{
    	
        if (isdigit(password[i])) 
		{
            digit = 1 ;
        }
        else
		(digit=0);
    }
    do {
	if (digit=1)
		{
        printf("is good\n");
        break;
    	} 
	if (digit!=1)
		{
       	
    	printf("Enter your password more than 8 and number  new !!!! :");
       	    gets(password);
		   
    	}
	}while(digit<1);

    

    do {
        printf("Login enter zero (0): ");
        scanf("%d", &n);
    } while (n != 0);

    return 0;
}
