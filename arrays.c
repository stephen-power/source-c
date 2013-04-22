#include <stdio.h>

/* array samples */


int main(){
	printf("arrays.c\n");
	intArrays();
}

int intArrays()
{
	//-----------simple declare and initialise------------------------
	int arr[] = {1, 2, 3, 4, 5};

	int x = 0; 
	for(x=0; x<sizeof(arr)/sizeof(int); x++)
	{
  		printf("element at %d = %d\n", x , arr[x]);
	}


	//------------verbose declare and initialise-----------------------
	int intArr[4];		// declare an array size
	int i = 0;
	i = sizeof(intArr);

	for(i=0;i<sizeof(intArr)/sizeof(int);i++)
	{
  		intArr[i] = i; // Initializing each element seperately
	}
	return 0;
}
