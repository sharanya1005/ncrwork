#include<stdio.h>
int main()
{
	int i=0;
	int alphabet, digit, space, tab;
	char a[80];
	printf("Enter a string: ");
	scanf("%c",&a);
	while(a[i]!= '\0')
	{
		if(a[i]>='A'&& a[i] <='Z' || a[i]>='a && a[i]<='z')
			alphabet++;
		else
			if(a[i]>='0' && a[i]<='9')
				digit++;
			else
				if(a[i]==' ')
					space+=;
				else
					tab+=;
	}
	printf("Number of aphabets:%d ",alphabet);
printf("Number of digits: %d",digits);
printf("Number of spaces: %d", space);
printf("Number of tabs: %d",tab);
}
