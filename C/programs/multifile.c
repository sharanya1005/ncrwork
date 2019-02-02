int addofnumbers(int x, int y);
int subofnumbers(int x, int y);
int mulofnumbers(int x, int y);
int diviofnumbers(int x, int y);
int addofnumbers(int x, int y)
{
	int add;
	add=x+y;
	return add;
}
int subofnumbers(int x, int y)
{
	int sub;
	sub=x-y;
	return sub;
}
int mulofnumbers(int x, int y)
{
	int mul;
	mul=x*y;
	return mul;
}
int diviofnumbers(int x, int y)
{
	int divi;
	divi=x/y;
	return divi;
}

#include<stdio.h>
int main()
{
	int a, b;
	int add, sub, mul, divi;
	printf("Enter first number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);
	add=addofnumbers(a,b);
	sub=subofnumbers(a,b);
	mul=mulofnumbers(a,b);
	divi=diviofnumbers(a,b);
	printf("add=%d \n sub=%d \n mul=%d \n divi=%d \n",add,sub,mul,divi);
	return 0;
}
