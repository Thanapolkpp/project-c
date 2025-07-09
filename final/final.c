#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char name[100];
    char password[100],gender;
    float weight,height,bmi,bmr,tdee,goal;
    int old;
    
} data;

// fuction  UI//

// ส่งค่า position
void position(int row, int co)
{
    printf("\033[%d;%dH", row, co);
}

// ส่งค่าสี
void color(int b, int c)
{
    printf("\033[%d;%dm", b, c);
    // 31m red
    // 32m green
    // 33m yellow
    // 34m blue
    // 35m violet
    // 0m recolor
}

//ส่งค่ากรอบ
void fream(){
    system("cls");
    position(3, 40); // ต่ำแหน่ง
    color(0, 33);//สีเหลือง
    printf(" ___________________________________________________ ");
    position(4, 40);            
    printf("|");
    position(5, 40); // ต่ำแหน่ง
    printf("|");
    position(4, 92); // ต่ำแหน่ง
    printf("|");
    position(5, 92); // ต่ำแหน่ง
    printf("|");
    position(6, 40);
    printf("|___________________________________________________|");
    color(0, 0);
}

// หน้า Welcome
int welcome()
{
    int choice = 0;
    fream();
    position(5, 50); // ต่ำแหน่ง
    color(1, 35);
    printf(" Welcome to 'Pun body to first'");
    color(0, 0); // คืนค่า
    color(1, 34);
    position(8, 40);
    printf("1.Login Accont ");
    color(1, 32);
    position(10, 40);
    printf("2.Create Account");
    color(1, 33);
    position(12, 40);
    printf("3.Exite program");
    color(1, 31);
    position(14, 40);
    printf(" You choose Menu :");
    color(0, 0);
    scanf("%d", &choice);
    return (choice);
}

// หน้า inprogram แสดงค่าชื่อ
int fmenu(data *user){ 
    fream();
    int menuin=0;
    position(5, 50); // ต่ำแหน่ง
    color(1, 34);    // สีน้ำเงิน
    printf("  Hello");
    color(1, 31); // สีแดง
    printf("   %s my dear ",user->name);
    color(0, 0); // คืนค่า
        color(1,31);
        position(8,40);
    printf("1.BMI" );
    position(10,40);color(1,32);
    printf("2.BMR and TDEE");
    position(12,40);color(1,33);
    printf("3.Advice");
    position(14,40);color(1,34);
    printf ("4.Undo program");
    position(16,40);color(1,35);
            printf (" You choose Menu :");
            scanf("%d",&menuin); 
    return menuin;
}

// ตัวข้างบนbmi
void fbmi(){
    fream();
    color(0, 0);
    position(5, 50); // ต่ำแหน่ง
    color(1, 34);    // สีน้ำเงิน
    printf("        Program ");
    color(1, 31); // สีน้ำเงิน
    printf(" BMI ");
    color(0, 0); // คืนค่า
}

// ตัวข้างบนbmr
void fbmr(){
    fream();
    position(5, 50); // ต่ำแหน่ง
    color(1, 34);    // สีน้ำเงิน
    printf("        Program ");
    color(1, 31); // สีน้ำเงิน
    printf(" BMR ");
    color(0, 0); // คืนค่า
}

// ตัวข้างบนTdee
void ftdee()
{
    fream();
    position(5, 50); // ต่ำแหน่ง
    color(1, 34);    // สีน้ำเงิน
    printf("        Program ");
    color(1, 31); // สีน้ำเงิน
    printf(" TDEE ");
    color(0, 0); // คืนค่า

    position(8, 40); color(1,31);
    printf("1.Little to no exercise");
    position(10, 40); color(1,32);
    printf("2.Light exercise (1-3 days per week)");
    position(12, 40);color(1,32);
    printf("3.Moderate exercise (4-5 days per week)");
    position(14, 40); color(1,34);
    printf("4.Heavy exercise (6-7 days per week)");
    position(16, 40);color(1,34);
    printf("5.Very intense exercise (twice a day or more)");
}

// ตัวข้างบนaccont
void faccount()
{
    fream();
    position(5, 50); // ต่ำแหน่ง
    color(1, 34);    // สีน้ำเงิน
    printf("        Program Craet");
    color(1, 31); // สีน้ำเงิน
    printf(" ACCOUNT ");
    color(0, 0); // คืนค่า
}

// ตัวข้างบนadvice
void fadvice()
{
    fream();
    position(5, 50); // ต่ำแหน่ง
    color(1, 34);    // สีน้ำเงิน
    printf("        Program ");
    color(1, 31); // สีน้ำเงิน
    printf(" ADVICE ");
    color(0, 0); // คืนค่า
}

// ตัวข้างบนLOGIN
void flogin()
{
    fream();
    position(5, 50); // ต่ำแหน่ง
    color(1, 34);    // สีน้ำเงิน
    printf("        Program ");
    color(1, 31); // สีน้ำเงิน
    printf(" LOGIN ");
    color(0, 0); // คืนค่า
}

// function ในโปรแกรม//

// save username

int save(data *user)
{
    FILE *f = fopen("User and password.txt", "a");
    if (f == NULL)
    {
        position(18, 40);
        printf("Error opening file\n");
        return 1;
    }

    fprintf(f, "%s %s\n", user->name, user->password);
    fclose(f);

    return 0;
}


//check Username 
int ckn(data*user){

    FILE *f = fopen("User and password.txt", "r"); 
    char fname[1000]; char fpassword[1000];
    if (f == NULL)
    {  
        position(18, 40);               //check file error
        printf("Error opening file\n");
        return 1;
    }
    while(fscanf(f,"%s %s",fname,fpassword)!=EOF){
    if(strcmp(fname,user->name)==0)
   { 
    position(9, 40);
        color(1,31);
        printf("NAME FAIL");
        color(0,0); 
     fclose(f); 
    return 1;   
    }
     // ชื่อตรง
    }

    // ชื่อไม่เหมื่อน
    fclose(f);
        position(9, 40);
        color(1,32);
        printf("NAME PASS");
        color(0,0);
    return 0;
}


// check password
int ckp(data *user)
{
    int len = 0, num = 0, i, lo,u;

    len = strlen(user->password);
    for (i = 0; i < len; i++)
    {
        if (isdigit(user->password[i])){num = 1;}
           //หาตัวเลข ถ้าเจอ num = 1 
        if(isupper(user->password[i])){u=1;}
           //หาตัวใหญ่ ถ้าเจอ u = 1 
        if(islower(user->password[i])){lo=1;}
    }      //หาอักษรเล็ก ถ้าเจอ a = 1 

    color(1, 32);
    if(len >= 8){position(13, 40);printf("1 : Enter 8 characters   -PASS- ");}
    if(num ==1) {position(14, 40);printf("2 : Enter number   -PASS-   ");}
    if(u ==1 && lo==1) {position(15, 40);printf("3 : Enter Upper and  Lower character      -PASS-    ");}
    color(0,0);

    if (len >= 8 && num ==1 && lo==1 && u==1)
    {   
        position(12, 40);
        color(1, 32);
        printf(" ========================  Password Pass  =======================\n");
        
        if(len >= 8){position(13, 40);printf("1 : Enter 8 characters   -PASS- ");}
        if(num ==1) {position(14, 40);printf("2 : Enter number   -PASS-   ");}
        if(u ==1 && lo==1) {position(15, 40);printf("3 : Enter Upper and  Lower character      -PASS-    ");}
        
        
        color(0,0);
        return 0;
    }

     

    if (len < 8 || num !=1 || lo!=1 || u!=1)
    {  
        position(12, 40);
        color(1, 31);
        printf("Please enter a new password with 8 characters (EX.Test1234)");
        if(len < 8){
            position(13, 40);
            printf("1 : Enter more than 8 characters");} 

        if(num!=1){
        position(14, 40);
        printf("2 : Enter more than 1 number");}

        if(u !=1 || lo !=1 ){
        position(15, 40);
        printf("3 : Enter more than 1 Upper and 1 Lower character");}
        color(0, 0);
        return 1;
    }
}

//check login
int cklog(data *user){
    char fname[1000],fpassw[1000];
    FILE *f = fopen("User and password.txt", "r");
    if (f == NULL)
    {
        position(18, 40);               //check file error
        printf("Error opening file\n");
        return 1;
    }
    while(fscanf(f,"%s %s",fname,fpassw)!=EOF){
    if(strcmp(fname,user->name)==0 && strcmp(fpassw,user->password)==0 )
   {
    fclose(f);
    return 0;  // การเข้าสู่ระบบสำเร็จ
    }}
     
    // ถ้าไม่พบข้อมูลตรงกับชื่อและรหัสผ่าน
    fclose(f);
    return 1;
}




// fuction BMI

void dbmi(data *user){
    color(1, 33);
    if (user->bmi < 18.5)
    {
        printf("You are small, my dear. Eat something\n\n");
    }
    else if (user->bmi <= 22.9)
    {
        printf("Your body is amazing, my dear. You doing great\n\n");
    }
    else if (user->bmi <= 24.9)
    {
        printf("You are getting a bit chubby! Let go to the gym together today!\n\n");
    }
    else if (user->bmi <= 29.9)
    {
        printf("You have gained some weight, my love, but no worries we will work on it together!\n\n");
    }
    else
    {
        printf("You have gained a lot of weight, but I believe in you got this!\n\n");
    }
}




void sBMI(data *user)
{

    fbmi();
    position(8, 40);
    printf("Enter your weight (Kg): ");
    scanf("%f", &user->weight);

    while (1)
    {
        position(9, 40);
        printf("Enter your height (cm): ");
        scanf("%f", &user->height);

        if (user->height == 0)
        {
            position(11, 40);
            printf("Error: Height cannot be zero!\n"); // set error
        }
        if (user->height != 0)
            break;
    }

    user->height = user->height / 100;
    user->bmi = user->weight / (user->height * user->height);

    position(12, 40);
    printf("Your BMI is: %.2f\n", user->bmi);
    

    position(13, 40);
    
    dbmi(user);
}




// fuction BMR
void sBMR(data *user)
{
    fbmr();
    position(8, 40);
    printf("you weight (Kg) :");
    scanf("%f", &user->weight);
    position(9, 40);
    printf("you height (cm) :");
    scanf("%f", &user->height);
    position(10, 40);
    printf("How old are you:");
    scanf("%d", &user->old);
    while(1){
    position(11, 40);
    printf("you gender M/F:");
    scanf(" %c", &user->gender);
    if ((user->gender == 'M' || user->gender == 'm' ) || (user->gender == 'F' || user->gender == 'f'))
    break;
    position(12, 40);
    color(1,31);
    printf("FAIL input. Please enter M or F.");color(0,0);}

    if (user->gender == 'M' || user->gender == 'm')
    {
        user->bmr = (66) + (13.7 * user->weight) + (5 * user->height) - (6.8 * user->old);
    }

    if (user->gender == 'F' || user->gender == 'f')
    {
        user->bmr = (665) + (9.6 * user->weight) + (1.8 * user->height) - (1.7 * user->old);
    }

    position(13, 40);
    color(1,33);
    printf("Your calorie burn rate is:%.2f calorie", user->bmr);
    color(0,0);
}

// fuction  โปรแกรม tdee
void tdee(data *user)
{
    int menuin, next;
    sBMR(user); 
    while (1)
    {
        position(14, 40);
        color(1,33);
        printf(" Next to TDEE  Enter  0 :");
        scanf("%d", &next);
        color(0,0);
        if (next == 0)
        {
            ftdee();
            position(18, 40); // ต่ำแหน่ง
            color(1,34);
            printf("Enter choice:");
            color(0,0);
            scanf("%d", &menuin);

            switch (menuin)
            {
            case 1:
            user->tdee = user->bmr * 1.2;
                break;
            case 2:
            user->tdee = user->bmr  * 1.375;
                break;
            case 3:
            user->tdee = user->bmr  * 1.55;
                break;
            case 4:
            user->tdee = user->bmr  * 1.725;
                break;
            case 5:
            user->tdee = user->bmr  * 1.9;
                break;
            } break;
        }
        else{
            position(20, 40);
            color(1,31);
            printf("ENTER NEW");
            color(1,0);
        }
    }
    
   
            color(1, 33);
            position(20, 50);
            printf("The energy you will use  %.2f  Kcal per day ", user->tdee);
            color(0, 0);
}


//fuction advice
void advice(data *user) {
    
    float wg=0,cal=0,pt=0,cb=0,o=0; 
    int food,next=0;
    char n;

    
    do{
    sBMI(user);
    position(15,40);
    color(1, 33);
    printf("Enter 0 undo :"); 
    scanf("%d",&next); 
    }while(next!=0);

    fadvice();
    position(8, 40);
    color(1, 33);
    printf("User BMI :%.2f",user->bmi);
    position(9, 40);
    dbmi(user);
    color(1, 33);
    position(10,40);
    printf("Enter weight (KG): ");
    scanf("%f",&user->goal);
    color(0, 0);

    color(1, 33);
    position(11,40);
    printf("Enter Goal (KG): ");
    scanf("%f",&user->goal);
    color(0, 0);
    
    
    
    do{
    color(1, 31);
    position(13, 40);
    printf("Have you calculated your BMR? Y/n:"); 
    scanf(" %c",&n);
    color(0, 0);
    }while(n!='N'&& n!='n'&&n!='Y'&&n!='y');


    if(n=='N'||n=='n'){
     tdee(user);
     position(22,40);
     color(1, 34);
     printf("Enter 0 undo :"); 
     scanf("%d",&next); 
     if (next==0){
        fadvice();
        color(1, 32);
        position(8, 40);
        printf("User BMI :%.2f",user->bmi);
        position(9, 40);
        dbmi(user);
        position(14, 40);
        
        printf("User TDEE is %.2f",user->tdee);
        position(15, 40);
    
        printf("User BMR is %.2f",user->bmr);
        color(0, 0);
    }
    }


    if(n=='Y'||n=='y'){
        color(1,32);
     position(16,40);
     printf("User BMR is %.2f",user->bmr);
     position(17,40);
     printf("User TDEE is %.f per/day",user->tdee);
     color(0,0); 
    }

     position(18, 40);  
     color(1, 32);
     printf("User weight : %.2f KG ",user->weight);
     position(19, 40);
     printf("User Goal : %.2f KG ",user->goal); 
     color(0,0);
    wg = user->weight - user->goal;
    
    color(1,33);
    if (wg < 0) {
        position(20, 40);
        printf("Gain weight : %.2f KG ",-wg); 
        cal = user->tdee + 500; 
        food = 1; 
    } else {
        position(20, 40);
        printf("Lose weight : %.2f KG ",wg); 
        cal = user->tdee - 500;  
        food = 0; 
    }
   color(0,0);

    pt =  1.5* user->weight;
    o = 0.5*user->weight;
    cb=(cal-(pt*4 + o*9))/4;
    
    color(1,33);
    position(23, 40);
    printf("Protein to eat : %.2f g", pt);
    position(24, 40);
    printf("Fat to eat: %.2f g", o);
    position(25, 40);
    printf("Carbohydrate to eat: %.2f g", cb);
    color(0,0);
    
    
   
    if (food == 0) { 
        
        color(1,31); 
        position(27, 40);
        printf(" Weight Loss %.2f kcal",cal);
        color(0,0);
        color(1,32);
        position(28, 40);
        printf("- Lean protein: Egg whites, chicken breast, fish, tofu");
        position(29, 40);
        printf("- Healthy fats: Avocado, olive oil, nuts, seeds");
        position(30, 40);
        printf("- Complex carbs: Quinoa, sweet potato, whole wheat bread");
        position(31, 40);
        printf("- High-fiber vegetables: Broccoli, spinach, asparagus, kale");
        color(0,0);} 
        
        else { 
        color(1,31);
        position(27, 40);
        printf("Weight Gain %.2fkcal",cal);
        color(0,0);

        color(1,32);
        position(28, 40);
        printf("- High-protein: Whole eggs, beef, chicken thighs, salmon");
        position(29, 40);
        printf("- Healthy fats: Peanut butter, coconut oil, cheese, avocado");
        position(30, 40);
        printf("- High-calorie carbs: White rice, oats, bananas, sweet potato");
        position(31, 40);
        printf("- Dairy products: Whole milk, yogurt, cheese");
        color(1,32);}
    }
  
    




// funtion account
void sac(data *user)
{
    int i,t=0;

        faccount();
        
    do{
        position(8, 40);
        printf("Enter your name :");
        scanf("%s",user->name);
        t = ckn(user);
    }while(t!=0);

    do
    {
        position(10, 40);
        printf("Enter your password (character more than  8 and number more than 1) :");
        scanf("%s",user->password);
        t = ckp(user);
    } while (t != 0);
    
}

//clear data
void clear(data *user){
    user->name[0] = '\0';  // เคลียร์ค่าใน user->name
    user->password[0] = '\0';  // เคลียร์ค่าใน user->password
    
}


//faction save
void sac2(data *user){
    int create, next,x;
    while (1)
    {     position(17, 40);
        printf(" Undo Enter new 1 / Next to Enter 0:");
        scanf("%d", &next);
        if (next == 1)
        {
            clear(user);
            sac(user);
            sac2(user);
            break;
        }
       if(next==0)
       {
        position(19, 40);
        color(1,33);
        printf("User : %s  Password : %s",user->name,user->password);
        color(0,0);
        position(21, 40);
        printf("Create accont enter 0 /Undo front menu enter 1 :");
        scanf("%d", &create);

        if (create == 0)
        {
            x = save(user);
            if (x==0){
                position(23, 40);
                color(1, 32);
                printf("Save successful\n");
                color(0, 0);
            }
            else {
                position(23, 40);
                color(1, 31);
                printf("Save unsuccess\n");
                color(0, 0);
            }
        }
                color(1,35);
                position(24,40);
                printf("Undo front menu enter 1 :");
                scanf("%d", &create);
                color(0,0);
                if(create==1){break;}
        }

        if(create==1){
            break;
        }
    }

        
}


//fuction Login
int login(data *user){
        
    int menulog=0,i=0,loop=0;
    flogin();
    do{
        position(8,40);
		printf("Enter your name :");
		scanf("%s",user->name);
		position(9,40);
		printf("Enter your password :");
		scanf("%s",user->password);

        i = cklog(user);
        if(i==1){

            loop++;
            position(11, 40);
            color(1,31);
            printf("LOGIN PROGRAM FAIL %d Loop",loop);
            color(0,0);
            
        }

            if(loop==3){
                
                position(12,60);
                color(1,31);
                printf("END PROGRAM");
                color(0,0);
                system("start end.wav");
                exit(0);}
    
        }while(i!=0);
    
    if(i==0){ 
        position(11, 40);
        color(1,32);
        printf("LOGIN PROGRAM PASS             ");
        
        position(13, 60);
        printf("Enter 0 to LOGIN :");
        scanf("%d",&menulog); 
        color(0,0);}
    
    return menulog;
}





int main()
{
    data user;//data ที่เป็น struct เก็บโดย user
    
    while (1)
    {
        int menu,end;
        int menulog,menupro;
        int next=0,cho=0;
         menu = welcome();
        switch (menu)
        {

        case 1:
        menulog = login(&user);
        
        if (menulog==0){ 
            while(1){
            menupro = fmenu(&user);
            switch(menupro){

                case 1 :sBMI(&user);   
                position(15,40);
                color(1, 33);
                printf("Enter 0 undo :"); 
                scanf("%d",&next); 
                if (next==0){break;}break;
                
                case 2 :tdee(&user);
                position(22,40);
                color(1, 34);
                printf("Enter 0 undo :"); 
                scanf("%d",&next); 
                if (next==0){break;}break;
                
                case 3 :advice(&user);
                position(35,40);
                color(1, 34);
                printf("Enter 0 undo :"); 
                scanf("%d",&next); 
                if (next==0){break;}break;
                
                case 4 :
                end =0; break;// end=0 และหยุด 
            }if(end==0) break;//ถ้า end == 0 จะหยุด while
        }
    }if(end==0)break; break;//ถ้า end ==0 จะหยุดswitch case และหลุดไปทำ menu = welcome();

        
        
        
        case 2: sac(&user);
                sac2(&user);
                break;





        case 3:
            position(15, 60);
            color(1, 31);
            printf("End of program");
            color(0,0);
            system("start end.wav");
            exit(0);
            break;
    }
}
    return 0;
}
