#include<stdio.h>
#include<conio.h>
void main()
{
	int n,sum=0,rem;
	clrscr();
	printf("Enter a number: ");
	scanf("%d", &n);
	while(n>0)
	{
		rem = n% 10;
		sum = sum + rem;
		n = n/10;
	}
	printf("sum of digits in a given number = %d", sum);
	getch();
}

