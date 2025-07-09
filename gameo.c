#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define MAX_PLAYERS 2 // กำหนด max players

// ตำแหน่งการขึ้นลง
int Head_snack[] = {13,23,25,48,51,63,82,91,98}; // ตำแหน่งของหัวงู
int tail_snack[] = {10,19,3,34,29,60,80,88,85}; // ตำแหน่งหางงูเมื่อเหยียบหัวงูและจะตกลงมาเรียงตามลำดับเลย เช่นเหยียบ 13 ก็จะลงมาหาง 10
int ladder[] ={2,6,12,24,32,42,45,71};//ตำแหน่งฐานบรรไดถ้าเหยียบตรงนี้จะขึ้นไปด้านบนบรรได
int up_ladder[] = {21,67,30,38,94,100,83,92}; //ตำแหน่งด้านบนบรรได อันนี้ก็เหมือนกับหัวงูเรียงเหมือนกัน เช่น เหยียบ 2 จะมา 21 ตามลำดับ


// คำสั่ง set สีเป็นสีต่างๆ
void set_color(int color){
    printf("\033[1;%dm",color);
}
// คำสั่งรีสีให้กลับมาเป็นเหมือนเดิม
void reset_color(){
    printf("\033[0m");
}

// function show_boardgame
void show_boardgame_snack(int positipms[MAX_PLAYERS]){
    int board[SIZE][SIZE];
    int num = 100; //เพราะตารางมี 100 ช่อง
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 2 == 0)
        {
            // แถวเลขคี่ ที่เป็น i % 2== 0 เป็นเลขคี่เพราะให้ user มองเริ่มจาก 1 นั้น แถวเลขคู่และเลขคี่เลยสลับกัน
            //ใส่ตัวเลขจากซ้ายไปขวา
            for (int j = 0 ; j < SIZE; j++) // 0--> 9
            {
                board[i][j] = num--;
            }
        }else // แถวเลขคู่
        {
            for (int j = SIZE - 1/*ที่ให้ -1 เพราะ Index อยู่ที่ 9 ในแถวมีขนาด 10 ช่อง */; j >= 0; j--) // ใส่เลขจากขวามาซ้าย
            {
                board[i][j] = num--;
            }
        }
    }
    //แสดงตาราง
    for (int i = 0; i < SIZE; i++)
    {
        printf("|"); // ตกแต่ง แสดงข้องความคั่น
        for (int j = 0; j < SIZE; j++)
        {
            int found_snack = 0;/******************************************** */
            int player1_here = (board[i][j] == positipms[0]);
            int player2_here = (board[i][j] == positipms[1]);
            // แสดงตำแหน่งผู้เล่น
            if (player1_here && player2_here)
            {
                set_color(34);
                printf("P1");
                set_color(35);
                printf("P2|");
                reset_color();
            }else if (player1_here)
            {
                set_color(34);
                printf(" P1 | ");
                reset_color();
            }else if (player2_here)
            {
                set_color(35);
                printf(" P2 | ");
                reset_color();
            }

            // นี้คือ set สีช่อง 31 เป็นสีแดง จะกำหนดให้สีแดงเป็นหัวงูไว้ ตก เหลือสร้างสีเขียวไว้เป็นทางขึ้น สีทองจะเป็นเส้นชัย   (32 จะเป็นสีเขียว)
            else if (board[i][j] == 13 || board[i][j] == 23 || board[i][j] == 25 || board[i][j] == 48 || board[i][j] == 51 || board[i][j] == 63 || board[i][j] == 82 ||board[i][j] == 91 || board[i][j] == 98 )
            {
               set_color(31); // เปลี่ยนเป็นสีแดง
               printf("%3d | ",board[i][j]);
               reset_color(); // ต้องรีกลับให้มาเป็นสีเดิมด้วยไม่นั้นตัวเลขหลังจากนั้นจะติดสีอื่นนี้ไปด้วย
        
            }
            else if (board[i][j] == 100) // เปลี่ยนสีตำแแหน่งเส้นชัย
            {
                set_color(33); //เปลี่ยนเป็นสีเหลือง
                printf("%3d | ",board[i][j]);
                reset_color();
            }
            
            //ท่อนเปลี่ยนสีเอาไว้แสดงตำแหน่งที่เป็นบรรได ถ้าลงช่องนี้จะขึ้นไปที่ตำแหน่งไหน (สีฟ้าคือตำแหน่งที่สีเขียวจะขึ้นไปถึง)
            else if (board[i][j] == 2 || board[i][j] == 6 || board[i][j] == 12 || board[i][j] == 24 ||  board[i][j] == 32 ||  board[i][j] == 42 ||  board[i][j] == 45 ||  board[i][j] == 71 )
            {
                set_color(32); // เปลี่ยนเป็นสีเขียว
                printf("%3d | ",board[i][j]);
                reset_color();
            }
            // ตำแหน่งปกติ ที่ไม่ได้เป็นบรรไดหรือหัวงู
            else
            {
                printf("%3d |",board[i][j]);
            }    
        }
        printf("\n===================================================\n");
    }
}

// function ทอยเต๋า
int roll(){
    return (rand() % 6) + 1 ;
} 

// function เช็คตำแแหน่ง ว่าลงหูงูหางงูรึเปล่า
int check_snake_or_kadder(int position){
    for (int i = 0; i < 9 ; i++)
    {
        // เช็คว่าตกหัวงูไม่
        if (position == Head_snack[i])
        {
            printf("no!!! Snake at %d. go down to %d!\n",position,tail_snack[i]); // ใช้แบบนี้ได้เลยเพราะเราเรียงตำแหน่ง array ให้เท่ากันอยู่แล้วแบบลง 13ก็ ไป10 ได้เลย
            return tail_snack[i]; // เปลี่ยนตำแหน่งไปหางงูแทน
        }
        
    }
    for (int i = 0; i < 8 ; i++)
    {
        //เช็คว่าตกช่องบรรไดไม่
        if (position == ladder[i])
        {
            printf("Wow let's go Ladder at %d. go up to %d!\n",position,up_ladder[i]);
            return up_ladder[i];
        }
        
    }
    return position; //กรณีไม่ตกทั้งหัวงูและบรรได ให้อยู่ตำแหน่งเดิม
}

//function การเล่น
void paly_game_snack(){
    int positions[MAX_PLAYERS] = {1,1};
    int turn = 0;
    srand(time(NULL));
    while (1) //วนเรื่อยๆ
    {
        show_boardgame_snack(positions); // show board game
        printf("\nplayer %d's turn . Press enter to roll.. ",turn +1);
        getchar(); // รับ user กด enter
        int dice = roll(); // ทอยลูกเต๋า
        printf("Player %d rolled a %d\t",turn+1,dice);
    
        positions[turn] += dice; // update ตำแหน่งผู้เล่น
        printf("player %d at Channel %d\n",turn+1,positions[turn]);
        if (positions[turn] > 100)
        {
            positions[turn] -= dice; //กรณีทอยแล้วตำแหน่งเกิน 100 จะไม่นับการทอยครั้งนั้น
        }
        positions[turn] = check_snake_or_kadder(positions[turn]); // ส่งค่าไป check กับตำแหน่งว่าลงหัวงูหรือบรรไดไม่
        if (positions[turn] == 100)
        {
            printf("\nPlayer %d win!!!!!\n",turn+1);
            break;  
        }
        turn = (turn + 1) % MAX_PLAYERS; // สลับturn ผู้เล่น 0,1 ไปมา
        system("cls"); // เคลียร์หน้าจอ
        
    }
    
}


int main()
{
    printf("\nWelcome to Board Game Snack!!!!!!!\n");
    printf("\nplayer 1 blue color\tplayer 2 purple color\n");
    paly_game_snack();
}