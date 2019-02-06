#include<stdio.h>
int main()
{
int count=0,rem;
long int num;
printf("Enter a 8-bit number: ");
scanf("%ld",&num);
while(num!=0)
{
rem=num%10;
if(rem==1)
count++;
num=num/10;
}
printf("The number of 1's in a given 8-bit number: %d",count);
}

