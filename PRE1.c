#include<stdio.h>
#include<string.h>
#define max 100 //max =100
int main()
{
	int menu,menuin,menuin1,old;
	float weight,bmi,height,BMR;
	char name [max],password[max],gender,advice;
	while(1)
	{	
		printf("\n");
		printf("   ------welcome to pun body to first -------   \n");
		printf("\n");
		printf(" 1.Login \n 2.Name of programming \n 3.Exite program\n");
		printf (" You choose Menu :");
		scanf("%d",&menu);
		switch (menu)
	{
		case 1 : system("cls");
		printf("\n");
		printf("   ------welcome to pun body to first -------   \n\n");
		printf("\n");
		printf("Enter your name :");
		scanf("%s",name);
		printf("Enter your password :");
		scanf("%s",password);
			
				
					printf("\n1.Next to page \n2.Undo program \n");
					printf ("You choose Menu :");
					
					scanf("%d",&menuin1);
					if (menuin1==1)
					system("cls");
					else
					break;
				
			//in program
			do	
			{ 	
			    
				printf("\n");
				printf("------welcome to pun body to first ------- \n       Hello  %s\n",name);
				
				printf(" 1.BMI \n 2.BMR \n 3.Advice \n 4.Search\n 5.Undo program \n");
				printf (" You choose Menu :");
				scanf("%d",&menuin);
			switch(menuin)
			{
				case 1 : system("cls"); //BMI
						 printf("       Menu  BMI         \n");
						 printf("you weight (Kg) :");
						 scanf("%f",&weight);
						 printf("you height (cm) :");
						 scanf("%f",&height);
						 height=height/100;
						 bmi = weight/(height*height);
						 printf(" Bmi of you :%.2f\n",bmi);
						 //if
						  if (bmi<18.5)
						 printf("You are small, my dear. Eat something\n\n");
						 else if ((bmi == 18.5 )&&(bmi<=22.9))
						 printf("Your body is amazing, my dear. You doing great\n\n");
						 else if ((bmi == 23 )&&(bmi<=24.9))
						 printf("You are getting a bit chubby! Let go to the gym together today!\n\n");
						 else if ((bmi == 25.0 )&&(bmi<=29.9))
						 printf("You have gained some weight, my love, but no worries we will work on it together!\n\n");
						 else 
						 printf("You have gained a lot of weight, but I believe in you got this!\n\n");
				
				        ;break;
				//BMR
				case 2 : system("cls");
						printf("       Menu  BMR         \n");
						printf("you weight (Kg) :");
						scanf("%f",&weight);
						printf("you height (cm) :");
						scanf("%f",&height);
						printf("How old are you:");
						scanf("%d",&old);
						printf("you gender M/F:");
						scanf(" %c",&gender);
						if(gender=='M'|| gender == 'm')
						BMR=(66)+(13.7*weight)+(5*height)-(6.8*old);
						if(gender=='F'|| gender == 'f') 
						BMR=(665)+(9.6*weight)+(1.8*height)-(1.7*old);
						printf("Your calorie burn rate is:%.2f\n",BMR);
						
						printf(" 1. \n 2. \n 3. \n 4.\n 5.\n");
						scanf("%d",&menuin1);
						switch (menuin1)
						{
						  case 1: BMR = BMR*1.2;
						  			
						  case 3: BMR = BMR*1.55;
						  case 4: BMR = BMR*1.;
						  case 5: BMR = BMR*1.2;
					
						} 
				break;
				//	        
				case 3 :system("cls"); 
						printf("       Menu   Advice     \n");
						printf("   What kind of advice do you need?\n   ");
						printf(":");
						scanf("%c",&advice);
						
				break;
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				case 4 : 
				case 5 : system("cls"); break;
				default :printf(" choose try again \n");
				break;
			} 
			}while (menuin != 5);
			break;
			
		case 2 : system("cls");
				printf("------welcome to pun body to first ------- \n \n");
				printf("Thanapol kpp , Jiramet \n ");
				printf ("You choose Menu :");
				printf("1.Undo program \n");
				scanf("%d",&menuin);
				switch(menuin)
				{
					case 1 : system("cls"); break;
					default :printf(" choose try again \n");
					break;
				}
				break;
		case 3 :  printf ("End of program"); return 0 ; break;
		default :system("cls");printf(" choose try again \n");
		
		}
	}

}