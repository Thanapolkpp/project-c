#include <stdio.h>
#include <stdlib.h>

int main() {
    // ใช้ start เพื่อเปิดไฟล์เสียงใน background โดยไม่ต้องเปิดหน้าต่างโปรแกรม
    system("start /min wmplayer.exe Welcometop.wav");

    printf("Program continues to run...\n");
    // โค้ดอื่น ๆ ของคุณที่ต้องการให้ทำงานต่อ
    return 0;
}