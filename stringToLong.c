#include <stdio.h>

/* convert string to intgers */
int stringToInt(char[] );
int main(){
    char str[10];
    int intValue;
    printf("Enter any integer as a string: ");
    scanf("%s",str);
   intValue = stringToInt(str);
    printf("Equivalent integer value: %d\n",intValue);
  //  return 0;


    char *str1 = "1234";
    int n = atoi(str1);
    printf("The string %s as an integer is = %d\n",str1,n);

    char *str2 = "314hello";
    n = atoi(str2);
    printf("The string %s as an integer is = %d\n",str2,n);

    char *str3 = "4a3d";
    n=strtol (str3,NULL,16);
    printf("The string %s as an integer is = %d\n",str3,n);
}

int stringToInt(char str[]){
    int i=0,sum=0;
    while(str[i]!='\0'){
         if(str[i]< 48 || str[i] > 57){
             printf("Unable to convert it into integer.\n");
             return 0;
         }
         else{
             sum = sum*10 + (str[i] - 48);
             i++;
         }
    }
    return sum;

}

