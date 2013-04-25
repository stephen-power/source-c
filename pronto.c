//gcc pronto.c -o ./bin/pronto
#include <stdio.h>
#include <string.h>

char testInArr[] = "+0,73,0,12,F,A,6,A,6,16,6,A,6,A,6,1C,6,16,6,A,6,A,6,16,6,16,6,10,6,16,6,A,6,A,6,A,6,10,6,E12-"; // simulate USART data in
unsigned int nbrCommas;		// on the atmega this number will be determined as the input stream is read. 
char inputArr[500];		//this will hold what comes in from USART
int inputArrLen;    //will be the number of chars loaded into the arrray (one bigger than the end index)
int inputArr_maxIndex;
int testInArrSize = sizeof(testInArr);

unsigned int prontoIntArr[500];
unsigned int prontoIntArr_maxIndex;

 
int main() {
    printf("charArray\n");
	loadInputArray();
	charArrToIntArr();
	//printCharArray();
	//simulateReadingFromUSART();

    return 0;
}

charArrToIntArr()
{
	printf("charArrToIntArr\n");

/*	long n;
//	char *str3 = "4a3d";
  	char *str3;
	str3 = "ff";
	n=strtol (str3,NULL,16);
    printf("The string %s as an integer is = %d\n",str3,n);

	str3 = "0A";
	n=strtol (str3,NULL,16);
    printf("The string %s as an integer is = %d\n",str3,n);

	char s1[] =  "000A";
	n=strtol (s1,NULL,16);
    printf("The string %s as an integer is = %d\n",s1,n);

	unsigned long strLong;
	unsigned int strInt;
	s1[0] = '0';
	s1[1] = '0';
	s1[2] = 'F';
	s1[3] = 'E';
	strLong=strtol (s1,NULL,16);
    printf("The string %s as a long is = %d\n",s1,strLong);
*/
	char s1[] = "0000";
	unsigned int strInt;
	int x;
	for (x = 0; x < 4; x++) {s1[x] = '0';}	// zero the array	
	s1[3] = 'F';
	strInt = (unsigned int) strtol(s1,NULL,16);	// caste to an integer
    printf("The string %s as an int is = %d\n",s1,strInt);

	/* start reading the string array backwards and convert it to an integer array
	   the input string contains commas and these will be used as delimiters
	*/
	printf("inputArr<%s>\n", inputArr); 	
	printf("inputArrLen=%d\n", inputArrLen);
	printf("inputArr_maxIndex=%d\n", inputArr_maxIndex);
	printf("inputArr[0]=%c\n", inputArr[0]);
	printf("inputArr[inputArr_maxIndex]=%c\n", inputArr[inputArr_maxIndex]);




//	str3[0] = '0';
//	str3[1] = '0';
//	str3[2] = 'f';
//	str3[3] = 'e';

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
	inputArrLen = i2;	// one greater than the file index
	inputArr_maxIndex = i2 - 1;	
	printf("nbrCommas=%d\n", nbrCommas);   
    printf("inputArr<%s>\n", inputArr);
 	prontoIntArr_maxIndex = nbrCommas;
   	printf("inputArrLen=%d\n", inputArrLen);
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
