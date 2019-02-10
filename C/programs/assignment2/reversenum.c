#include<stdio.h>

int main()
{
	int num,rev,r;
	rev=0;

	printf("Enter a number: ");
	scanf("%d",&num);
	
	while(num!=0)
	{	
	r=num%10;
	num=num/10;
	rev = rev*10+r;
	
	}

	printf("Reversed Number: %d",rev);
	
}
