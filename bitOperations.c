//gcc bitOperations.c -o ./bin/bitOperations
#include <stdio.h>
#include <stdbool.h>
//******************************************************************************
//  GLOBAL VARIABLES                                                           *
//******************************************************************************
char tapsOnAsString[3] = "x,x";   // length 3.  e.g "2,6" or "5  " or "   "

//******************************************************************************
//  FUNCTION DEFINITIONS                                                       *
//******************************************************************************
bool isBitOn (int, unsigned char);
void printCharToBinaryString (char);
void setTapsOnAsString(unsigned char);

//******************************************************************************
//  MAIN                                                                       *
//******************************************************************************

int main() {
	unsigned char testByte = 'a';

	int bitPosition = 7;
	bool bitTest = isBitOn(bitPosition, 	testByte);
	printf("bitTest=");
	printf(bitTest ? "true" : "false");
	printf("\n");

	tapsOnAsString[2] = 'y';
	printf("tapsOnAsString=%s\n", tapsOnAsString);
	setTapsOnAsString(testByte);


    return 0;
}
//******************************************************************************
//  FUNCTIONS                                                                  *
//******************************************************************************
void setTapsOnAsString(unsigned char inByte){
	int tapsOnAsStringIDX = 0;
	tapsOnAsString[0] = ' ';
	tapsOnAsString[1] = ' ';
	tapsOnAsString[2] = ' ';

	int bitPosition;
	for(bitPosition = 1; bitPosition < 7; bitPosition++){  // only look at the first 6 bits
		if(isBitOn(bitPosition, inByte)){
			//printf("true");
					
		}
	}
 	
}
//******************************************************************************
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
//******************************************************************************
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
//******************************************************************************
  

