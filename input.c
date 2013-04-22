#include <stdio.h>

int main() {
	int number;
	printf ("please enter a number:");
	scanf("%d", &number);    
	printf("you enterted %d\n", number);
	getchar();
    return 0;
}
//scp ./*.c pi@10.1.1.7:/home/pi/source/C 
//gcc -o hello hello.c

