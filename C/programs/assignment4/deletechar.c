#include<stdio.h>
void main()
{
	char a[10],c;
	int i, j;
	printf("enter a string");
	gets(a);
	printf("\n enter a character");
	scanf("%c",&c);
	for (int k = 0; k < strlen(a); k++)
	{
		i = 0;
		if (a[i] == c)
		{
			for (j = i + 1; j < strlen(a); j++)
			{
				a[i] = a[j];
				i++;
			}
			a[i] = '\0';
			
		}
		
	}
	printf("%s", a);

}