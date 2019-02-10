#include<stdio.h>
int delete(char [],char);
int main()
{
char a[15];
char b;
printf("Enter a string: ");
scanf("%s",a);
printf("Enter a character: ");
scanf("%s",&b);
delete(a, b);
printf("%s",a);
return 0;
}

int delete(char a[],char b)
{
int i=0,j,k,f;
for(k=0;k<strlen(a)+1;k++)
{
if(a[i]==b)
{
	f=i;
	for(j=i+1;j<strlen(a);j++)
	{
		a[i]=a[j];
		i++;
	}
	a[i] ='\0';
	i=f;
}
else
i++;
}
return 0;
}