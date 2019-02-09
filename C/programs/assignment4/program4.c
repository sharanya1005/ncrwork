#include<stdio.h>
int replace(char *);
void main()
{
char *cat= "The cat sat";
int n;
n=replace(cat);
printf(" number of spaces replaced: %d\n",n);
}
int replace(char *a)
{
int i=0, n=0;
	for(i=0; a[i]!='\0'; i++)
	{
	if(a[i] == ' ')
	{
	 a[i] = '-';
	n++;
	}
	}

printf("new string is: %s\n", a);
return n;
}

