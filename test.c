#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    char password[100], gender;
    float weight, height, bmi, bmr, tdee,goal;
    int old;
} data;



// ส่งค่า position
void position(int row, int co) {
    printf("\033[%d;%dH", row, co);
}

// ส่งค่าสี
void color(int b, int c) {
    printf("\033[%d;%dm", b, c);
    // 31m red
    // 32m green
    // 33m yellow
    // 34m blue
    // 35m violet
    // 0m recolor
}
// ฟังก์ชัน UI
void fream() {
    position(3, 40);  // ตำแหน่ง
    color(0, 33); // สีเหลือง
    printf(" ___________________________________________________ ");
    position(4, 40); // ตำแหน่ง
    printf("|");
    position(5, 40); // ตำแหน่ง
    printf("|");
    position(4, 92); // ตำแหน่ง
    printf("|");
    position(5, 92); // ตำแหน่ง
    printf("|");
    position(6, 40);
    printf("|___________________________________________________|");
    color(0, 0);
}
void fadvice() {
    fream();
    position(5, 50); // ตำแหน่ง
    color(1, 34);    // สีน้ำเงิน
    printf("        Program ");
    color(1, 31); // สีน้ำเงิน
    printf(" ADVICE ");
    color(0, 0); // คืนค่า
}




void advice(data *user) {
    
    float wg=0,cal=0,call; 
    int food;
    char n;
    user->tdee=2350.0;

 
    fadvice();
    position(8, 40);
    color(1, 34);
    printf("Enter Goal (KG): ");
    scanf("%f",&user->goal);
    printf("Enter Goal (KG): ");
    scanf("%f",&user->weight);
    color(0, 0);
    color(1, 31);
    position(9, 40);
    printf("Have you calculated your BMR? Y/n:"); 
    scanf(" %c",&n);
    color(0, 0);
    if(n=='N'||n=='n'){
    fadvice();
    position(11, 40);  
    color(1, 33);
    printf("User weight : %.2f KG ",user->weight);
    position(12, 40);
    printf("User Goal : %.2f KG ",user->goal);
    }
    if(n=='Y'||n=='y'){
     position(10,40);
     color(1,32);
     printf("GOOD!!!!!");
     color(0,0); 
    fadvice();
    position(11, 40);  
    color(1, 33);
    printf("User weight : %.2f KG ",user->weight);
    position(12, 40);
    printf("User Goal : %.2f KG ",user->goal);
    }
    wg =  user->goal - user->weight;
    position(14, 40);
    if(wg>0){
        printf("User Gain weight : %.2f KG ",wg);
        cal = 500*(wg/0.5);}
    else{
        position(14, 40);
        printf("User Lose weight : %.2f KG ",-wg);
        cal= -500*(-wg/0.5);
        } 
    color(0,0);
    call = user->tdee + cal;
    position(16,40);
    color(1,31);
    printf("Recommended daily :%.2f",cal);


    }
int main() {
    data user;
    advice(&user);
}
