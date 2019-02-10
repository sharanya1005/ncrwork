#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n;
	unsigned long factorial =1;
	clrscr();
	printf("Enter an integer: ");
	scanf("%d",&n)
		if(n<0)
			printf("Error! Factorial of a negative number doesn't exist");
		else 
		{
			for(i=1;i<n;i++)
			{
				factorial * = i;
			}
			printf("Factorial of %d = %lu", n, factorial);
		}
	getch();
}

