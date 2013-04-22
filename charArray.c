//gcc charArray.c -o ./bin/charArray
#include <stdio.h>

char testInArr[] = "+0,73,0,12,F,A,6,A,6,16,6,A,6,A,6,1C,6,16,6,A,6,A,6,16,6,16,6,10,6,16,6,A,6,A,6,A,6,10,6,E12-"; // simulate USART data in
char inputArr[500];
int inputArrLen;    //will be the number of chars loaded into the arrray (one bigger than the end index)
int testInArrSize = sizeof(testInArr);

 
int main() {
    printf("charArray\n");
	printCharArray();
	simulateReadingFromUSART();

    return 0;
}

printCharArray()
{
	printf("printCharArray\n");
	printf("%s\n", (char*) testInArr);
	printf("sizeof testInArr including the NULL terminator=%d\n", testInArrSize);

//	inputArr[0] = '+';
	printf("%s\n", (char*) inputArr);
	printf("0 char=%c\n", testInArr[0]);
}

simulateReadingFromUSART()
{//  instead of reading from USART we will read from testInArr
	int inSize = testInArrSize -2;
	printf("i=%d\n", inSize); 
	
	int i;
	for(i = 1; i < inSize; i++)
	{
		//printf("char=%c", testInArr[i]);
		inputArr[i - 1] = testInArr[i];
	}
	inputArrLen = i -1;	// save the length
	printf("inputArr<%s>\n", inputArr); 	
	printf("inputArrLen=%d\n", inputArrLen);
}
