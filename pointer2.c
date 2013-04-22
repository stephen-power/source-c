#include <stdio.h>


void go_south_east(int *lat, int *lon)	//takes a pointer as an argument
{
	printf("go_south_east\n");
	*lat = *lat - 1;
	*lon = *lon + 1;
	

}

int main()
{
	printf("pointer2:started\n");
	
	int latitude = 32;
	int *address_of_latitude = &latitude;			//pointer variable
	int longitude = -64;
	int *address_of_longitude = &longitude;			//pointer variable
	

	printf("latitude=%d   lonitude=%d\n", latitude, longitude);

	go_south_east(address_of_latitude, address_of_longitude);	// use the pointer variables

	printf("latitude=%d   lonitude=%d\n", latitude, longitude);

	go_south_east(&latitude, &longitude);						// dereference and call the function

	printf("latitude=%d   lonitude=%d\n", latitude, longitude);
	printf("address of latitude=%p     address of longitude=%p\n", &latitude, &longitude);
	printf("sizeof int=%d\n", sizeof(latitude));
	printf("sizeof pointer=%d\n", sizeof(address_of_latitude)); 
	return 0;

}


