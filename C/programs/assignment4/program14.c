#include<stdio.h>
#include<string.h>
void main()
{
char a[15],temp;
int i=0,j=0,k;
printf("Enter a string: ");
scanf("%s",a);
k = strlen(a);
	while(k!='\0')
	{
	temp = a[0];
	for(i=0;i<strlen(a) - 1;i++)
	{
	a[i] = a[i+1];
	}
	a[i] = temp;
	printf("\n %s",a);
	k--;
}
}