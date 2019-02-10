#include<stdio.h>
#include<math.h>
int main()
{
long int binary=0;
int decimal;
int i=0,rem;

printf("Enter decimal number: ");
scanf("%d",&decimal);

while(decimal!=0)
{
rem=decimal %2;
binary = binary + rem * pow(10,i);
decimal = decimal/2;
i++;
}
printf("Equivalent binary number: %ld",binary);
}

