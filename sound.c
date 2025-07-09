#include<windows.h>
int main()
{
	PlaySound(TEXT("Welcometop.wav"),NULL , SND_FILENAME |SND_ASYNC);
    
    return 0;
}