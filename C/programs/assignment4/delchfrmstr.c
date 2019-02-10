#include<stdio.h>
void main()
{
	char s1[10], s2[10],s3[10];
	int f;
	printf("enter string 1 ");
	scanf("%s", s1);
	printf("\n enter string 2");
	scanf("%s", s2);
	for (int i = 0; i < strlen(s1); i++)
	{
		for (int j = 0; j < strlen(s2); j++)
		{
			if (s1[i] == s2[j])
			{
				f = i;
				for (int k = i + 1; k < strlen(s1); k++)
				{
					s1[i] = s1[k];
					i++;
				}
				s1[i] = '\0';
				i = f;
			}
			else
				i++;
			

		
		}
	}
	printf("%s", s1);
}