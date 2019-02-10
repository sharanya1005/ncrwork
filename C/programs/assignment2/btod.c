#include<stdio.h>
#include<math.h>
int main()
{
int decimal=0;
long int binary;
int i=0,rem;

printf("Enter binary number: ");
scanf("%ld",&binary);

while(binary!=0)
{
rem=binary %10;
decimal = decimal + rem * pow(2,i);
binary = binary/10;
i++;
}
printf("Equivalent decimal number: %d",decimal);
}

