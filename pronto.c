//gcc pronto.c -o ./bin/pronto
#include <stdio.h>
#include <string.h>

char testInArr[] = "+0,73,0,12,F,A,6,A,6,16,6,A,6,A,6,1C,6,16,6,A,6,A,6,16,6,16,6,10,6,16,6,A,6,A,6,A,6,10,6,E12-"; // simulate USART data in
unsigned int nbrCommas;		// on the atmega this number will be determined as the input stream is read. 
char inputArr[500];		//this will hold what comes in from USART
int inputArrLen;    //will be the number of chars loaded into the arrray (one bigger than the end index)
int testInArrSize = sizeof(testInArr);

unsigned int prontoIntArr[500];
int prontoIntArr_size;
 
int main() {
    printf("charArray\n");
	loadInputArray();
	//printCharArray();
	//simulateReadingFromUSART();

    return 0;
}

loadInputArray()   // this function loads up the array as the USART would. removes '+' and '-'. Also counts the commas which is also the max index 
{
	nbrCommas = 0;
	printf("loadInputArray\n");

    int inSize = testInArrSize - 1;
	printf("i=%d\n", inSize); 
    
	int i2 = 0;
	int i;
    for(i = 0; i < inSize; i++)
    {    // load the test array into inputArr; this is only done to simulate USART input
		// and remove '+' and '-' chars
        //printf("char=%c", testInArr[i]);
		if (testInArr[i] == '+' || testInArr[i] == '-'); //drop these
		else
			{
			inputArr[i2] = testInArr[i];
			if (inputArr[i2] == ',') nbrCommas++;
			i2++;
			}
    }
	printf("nbrCommas=%d\n", nbrCommas);   
    printf("inputArr<%s>\n", inputArr);

    //printf("inputArrLen=%d\n", inputArrLen);
/*	printf("<");
	for (i = inSize; i > -1; i--) 	
	{
		printf("%c", inputArr[i]);
		//printf("i=%d", i);
	}
	printf(">\n");
*/
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
{
	/* this routine will read the charArray and convert the chars to ints and remove the comma's.
	the array will be read backwards to assist in the conversion process
	testInArr[] holds the input data as comma delimited hex chars  which need to be converted.
	*/ 
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

	char *pos = strchr(testInArr, 'u');
	if (pos)
    	printf("Character 'u' found at position %d.\n", pos - testInArr);
  	else
    	printf("Character 'u' not found.\n");

}
