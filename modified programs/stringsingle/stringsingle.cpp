#include <stdio.h>
#include <string.h>


char *stringcopy(char *str1, const char *str2)
{
	char *dest = str1;
	const char *src = str2;
	while ((*dest++ = *src++) != '\0');
	return str1;
}

char *stringconcat(char *str1, const char *str2)
{
	char *s = str1;
	while (*s != '\0')
		s++;
	stringcopy(s, str2);
	return str1;
}

int stringlength(const char *str)
{
	const char *s = str;
	while (*s != '\0')
		s++;
	return (s - str);
}

int stringcomp(const char *str1, const char *str2)
{
	unsigned char unch1, unch2;
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	unch1 = (*(unsigned char *)str1);
	unch2 = (*(unsigned char *)str2);
	return ((unch1 < unch2) ? -1 : (unch1 > unch2));
}

char *stringreverse(char *str)
{
	char *p1, *p2, temp;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	return str;
}

int main()
{
	char string1[25], string2[25];
	int operation = 0, result;
	printf("Enter string1: ");
	gets_s(string1);
	printf("\nEnter string2: ");
	gets_s(string2);
	printf("\nSelect an operation to be performed.\n 1.Find length of a given string\n");
	printf(" 2.concatenation of strings\n 3.copying a string\n 4.comparison of strings\n 5.Reverse a string\n");
	scanf_s("%d", &operation);
	char temp[40];
	if (operation <= 5 && operation != 0)
	{
		switch (operation)
		{

		case 1:
		{
			printf("length of first string is %d\n", stringlength(string1));
			printf("length of second string is %d\n", stringlength(string2));
			break;

		}
			
		case 2:
			stringconcat(string1, string2);
			printf("The concatenated string is = %s\n", string1);
			break;
			
		case 3:
			stringcopy(temp, string2);
			printf("The string is copied  %s,%s\n", temp, string2);
			break;
		case 4:
			result = stringcomp(string1, string2);
			if (result <= -1)
			{
				printf("first string is lexographically less than the second\n");
			}
			else if (result >= 1)
			{
				printf("second string is lexographically less than the first\n");
			}
			else if (result == 0)
			{
				printf("Both the strings are equal\n");
			}

			break;
		case 5:
			printf("Reversal of first string is %s\n", stringreverse(string1));
			break;

		}
		getchar();
		getchar();
		//printf("Select an operation to be performed: ");
		//scanf_s("%d", &operation);
		//printf("\n");
	}
}