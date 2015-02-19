//gcc bitOperations.c -o ./bin/bitOperations
#include <stdio.h>
#include <stdbool.h>
bool isBitOn (int, unsigned char);
void printCharToBinaryString (char);

int main() {
	unsigned char testByte = 'a';

	int bitPosition = 7;
	bool bitTest = isBitOn(bitPosition, 	testByte);
	printf("bitTest=");
	printf(bitTest ? "true" : "false");
	printf("\n");

    return 0;
}
 
bool isBitOn (int bitPositionToTest, unsigned char inByte){
	// bits are numbered right to left decending starting from 8.  e.g  8->1 
	printf("inByte=");	
	printCharToBinaryString (inByte);
	int x;
	unsigned char mask = 0b00000001;

	for(x = 1; x < bitPositionToTest; x++){  // shift the "on" bit to the correct postion
			mask = mask << 1;	
	}
	// mask will now be in the correct bit position	
	printf("mask  =");	
	printCharToBinaryString (mask);

	if ((mask & inByte) == 0){
		return false;	
	}
	return true;
}

void printCharToBinaryString (char charIn){
	unsigned char mask = 0b10000000;
	int x;

	for (x = 8; x > 0; x--){
		if (x == 4){printf(" ");}	
		if ((mask & charIn) == 0){
			printf("0");	
		}
		else {
			printf("1");	
		}
		mask = mask >> 1;
	}
	printf("\n");	
}
  

