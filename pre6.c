#include<stdio.h>
#include"string.h"
#include "stdlib.h"




//
void sound(){
	system("start Welcometop.wav");
}


//ส่งค่าpositionไป
void position(int row,int co){
		printf("\033[%d;%dH",row,co);
	}

//สีคัวwelcome
void colorm(){
		position(3,40);//ต่ำแหน่ง
		printf("\033[33m ___________________________________________________ ");//สีเหลือง
		position(4,40);//ต่ำแหน่ง
		printf("|");
		position(5,40);//ต่ำแหน่ง
		printf("|");
		position(4,92);//ต่ำแหน่ง
		printf("|");
		position(5,92);//ต่ำแหน่ง
		printf("|");
		position(5,50);//ต่ำแหน่ง
		printf("\033[1;34m  Welcome to 'Pun body to first' \033[0m ");//สีน้ำเงืน
		position(6,40);
        printf("\033[33m|___________________________________________________|\033[0m");
		}

//เคลียหน้าจอ
void cls()
	{
		system("cls");
	}
	
//หน้า BMI
void sBMI() {
    float weight = 0, bmi = 0, height = 0;
	int menu=0;

    cls(); 
    position(3, 40);
    printf("\033[33m ___________________________________________________ ");
    position(4, 40);
    printf("|");
    position(5, 40);
    printf("|");
    position(4, 92);
    printf("|");
    position(5, 92);
    printf("|");
    position(5, 58);
    printf("\033[1;34mMenu BMI\033[0m ");
    position(6, 40);
    printf("\033[33m|___________________________________________________|\033[0m");

    position(8, 40);
    printf("\033[1;0mEnter your weight (Kg): ");
    scanf(" %f", &weight);

    position(9, 40);
    printf("Enter your height (cm): ");
    scanf(" %f", &height);

    if (height == 0) {
        position(11, 40);
        printf("Error: Height cannot be zero!\n");
    }

    height = height / 100; 
    bmi = weight / (height * height);

    position(12, 40);
    printf("Your BMI is: %.2f\n", bmi);

	position(13,40);
	if (bmi < 18.5) {
		printf("You are small, my dear. Eat something\n\n");
	} 
	else if (bmi >= 18.5 && bmi <= 22.9) {
		printf("Your body is amazing, my dear. You doing great\n\n");
	} 
	else if (bmi >= 23 && bmi <= 24.9) {
		printf("You are getting a bit chubby! Let go to the gym together today!\n\n");
	} 
	else if (bmi >= 25 && bmi <= 29.9) {
		printf("You have gained some weight, my love, but no worries we will work on it together!\n\n");
	} 
	else {
		printf("You have gained a lot of weight, but I believe in you got this!\n\n");
	}
	
    getchar();
    printf("\nEnter 0 undo"); scanf("%d",&menu); if (menu==0) getchar; cls();
}
	 


	
//หน้า BMR
void sBMR()
	{
		float weight=0,BMR =0,height=0;
		int old=0,menu;
		char gender;
		
		cls(); 
    position(3, 40);
    printf("\033[33m ___________________________________________________ ");
    position(4, 40);
    printf("|");
    position(5, 40);
    printf("|");
    position(4, 92);
    printf("|");
    position(5, 92);
    printf("|");
    position(5, 58);
    printf("\033[1;34mMenu BMR\033[0m ");
    position(6, 40);
    printf("\033[33m|___________________________________________________|\033[0m");
						position(8, 40);
						printf("you weight (Kg) :");
						scanf("%f",&weight);
						position(9, 40);
						printf("you height (cm) :");
						scanf("%f",&height);
						position(10, 40);
						printf("How old are you:");
						scanf("%d",&old);
						position(11, 40);
						printf("you gender M/F:");
						scanf(" %c",&gender);
						if(gender=='M'|| gender == 'm'){BMR=(66)+(13.7*weight)+(5*height)-(6.8*old);}
						if(gender=='F'|| gender == 'f') {BMR=(665)+(9.6*weight)+(1.8*height)-(1.7*old);}
						
						
						position(13, 40);
						printf("Your calorie burn rate is:% .2f calorie",BMR);
						printf("\nEnter 0 undo"); scanf("%d",&menu); if (menu==0) getchar; cls();
						

						
						
	}
	
void stdee()
	{
		float BMR,TDEE=0;
		int menuin;
		cls();
		printf("       Menu  Total Daily Energy Expenditure (TDEE)    \n");
		printf(" \n1.Little to no exercise \n\n 2.Light exercise (1-3 days per week)\n\n 3.Moderate exercise (4-5 days per week) \n\n 4.Heavy exercise (6-7 days per week)\n\n 5.Very intense exercise (twice a day or more)\n\n");
		printf (" You choose Menu :");
		scanf("%d",&menuin);
						switch (menuin)
						{
						  case 1: TDEE = BMR*1.2;break;
				          case 2: TDEE = BMR*1.375;break;			
						  case 3: TDEE= BMR*1.55;break;
						  case 4: TDEE= BMR*1.725;break;
						  case 5: TDEE = BMR*1.2;break;
						  default: break;
						} 
		printf("The energy you will use %.2f  cal per day ",TDEE);
	}







//Create accont
void account ()
	{
		char name[100],password[100];
		printf("Enter your name :");
		scanf("%s",name);
		printf("Enter your password :");
		scanf("%s",password);

	}

void login(){
	char name[100],password[100];
	int i;
	   
		 do
		 {	colorm();
			position(8,40);
			printf("Enter your name :");
			scanf("%s",name);
			position(9,40);
			printf("Enter your password :");
			scanf("%s",password);
			position(11,40);
        	printf("LOGIN PROGRAM Enter 0");
			position(12,40);
			scanf("%d",&i);
			printf("\033[1;31mLOGIN FAIL");
			cls();
		 } while (i!=0);
		 cls();
	 
	}


	int fmenu (){

		int menu=0;
		colorm();
		position(8,40);
		printf("\033[1;33m1.Login Accont \n" );
		position(9,40);
		printf("2.Create Account\n");
		position(10,40);
		printf("3.Exite program\n\033[0m");
		position(12,40);
		printf (" You choose Menu :");
			scanf("%d",&menu);
			return (menu);
	}



	void inlog (){
      
	int menuin=0,menu=0;
	    
		while (1)
		{
			colorm();
			position(8,40);
		printf("\033[1;33m1.BMI \n" );
		position(9,40);
		printf("2.BMR and TDEE\n");
		position(10,40);
		printf("3.History\n");
		position(11,40);
		printf ("4.Search for exercies");
		position(13,40);
		printf ("5.Undo program\033[0m");
		position(15,40);
				printf (" You choose Menu :");
				scanf("%d",&menuin);
		
				switch(menuin){
				case 1 :sBMI();break;
				case 2 :sBMR();break;
				case 3 : break;
				case 4 :
				case 5 :cls();fmenu();break;
			}
			
				
		}
		


}
  


int main()
{  
	
	while(1){
		sound();
	    int menu = fmenu();
		switch (menu)
		{
			case 1 :cls();login();inlog();break;
			case 2 :cls();account();break;
			case 3 :
					position(15,60);
					printf ("\033[1;31mEnd of program\033[0m");return(0); break;


			default :cls();printf(" choose try again \n");
			break;
		
	}}
			
		
}





