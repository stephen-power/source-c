//gcc bitOperations.c -o ./bin/bitOperations
#include <stdio.h>
#include <stdbool.h>
bool isBitOn (int, unsigned char);
void printCharToBinaryString (char);

int main() {
    printf("---bitOperations start---\n");

	unsigned char testByte = 'a';
	printCharToBinaryString (testByte);
	
	int bitNumber = 1;
	isBitOn(bitNumber, 	testByte);


    printf("---bitOperations end---\n");
    return 0;
}
 
bool isBitOn (int bitNumberToTest, unsigned char inByte){
	printf("-isBitOn\n");	
	// bits are numbered right to left decending starting from 8.  e.g  8->1 
	printf("bitNumberToTest=%d    inByte=%x\n", bitNumberToTest, inByte);	


	return true;
}

void printCharToBinaryString (char charIn){
	printf("-printCharToBinaryString\n");	
	printf("charIn=%x\n", charIn);	
	
	int onOff = 0;
	unsigned char mask = 0b10000000;
	printf("mask=%x\n", mask);	
	
	onOff = mask & charIn;
	printf("\n");	
	
	int x;
	for (x = 8; x > 0; x--){
		if (x == 4){printf(" ");}	
		onOff = mask & charIn;
		if (onOff == 0){
			printf("0");	
		}
		else {
			printf("1");	
		}
		mask = mask >> 1;
	}
	printf("\n");	
}
  

