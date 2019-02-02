#include<stdio.h>
#include<conio.h>
void main()
{
	int n,reversed integer=0, remainder, original integer;
	clrscr();
	printf("Enter an integer: ");
	scanf("%d",&n);
	original integer=n;
	while(n!=0)
	{
		remainder=n/10;
		reversed integer= reversed integer*10 + remainder;
		n/=10;
	}
	if(original integer == reversed integer)
		printf("%d is a palindrome", original integer);
	else
		printf("%d is not a palindrome", original integer);
	getch()
}

