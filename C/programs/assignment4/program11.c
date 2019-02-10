#include<stdio.h>
#include<stdlib.h>
char * strtok(char * s, char *comp);
void main()
{
	char s[100], *p, delimit[20];
	int i = 0, len = 0;
	printf("Enter the input string \n");
	gets(s);
	printf("Enter the delimiter string \n");
	gets(delimit);

	while (len++ != '\0');
	p = strtok(s, delimit);
	while (p != NULL)
	{
		printf("%s \n", p);
		p = strtok(NULL, delimit);
	}
}
char * strtok(char * str, char *comp)
{
	static int pos;
	static char *s;
	int i = 0, start = pos;
	if (str != NULL)
		s = str;

	i = 0;
	int j = 0;

	while (s[pos] != '\0')
	{
		j = 0;
	
		while (comp[j] != '\0')
		{
			
			if (s[pos] == comp[j])
			{
				
				s[pos] = '\0';
				pos = pos + 1;
				
				if (s[start] != '\0')
					return (&s[start]);
				else
				{
				
					start = pos;
					pos--;
					break;
				}
			}
			j++;
		}
		pos++;
	}
	s[pos] = '\0';
	if (s[start] == '\0')
		return NULL;
	else
		return &s[start];
}