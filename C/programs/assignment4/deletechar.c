#include<stdio.h>
void main()
{
	char a[10],c;
	int i=0, j,f;
	printf("enter a string: ");
	gets(a);
	printf(" enter a character: ");
	scanf("%c",&c);
	for (int k = 0; k < strlen(a)+1; k++)
	{
	
		if (a[i] == c)
		{
			f=i;
			for (j = i + 1; j < strlen(a); j++)
			{
				a[i] = a[j];
				i++;
			}
			a[i] = '\0';
			i=f;
			
		}
	else
	i++;
		
	}
	printf("%s", a);

}