#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int stringlength(char *string)//function to find the length of the given string
{
	char *str = string;
	while (*str != '\0')
	{
		str++;
	}
	return (str - string);
}

char* stringconcat(char* dest, const char*source)//function to concatenate two strings
{
	while (*dest != '\0')
	{
		dest++;
	}
	while ((*dest = *source) != '\0')
	{
		dest++;
		source++;
	}

	*dest = '\0';

	return dest;
}

char* stringcopy(char* dest, const char*source)//function to copy from one string to other
{
	while (*dest = *source)
	{
		if (*dest == '\0')
			break;

		source++;
		dest++;

	}
	return dest;
}

int stringcompare(char * dest, const char* source)//function to compare two strings
{
	while (*dest == *source)
	{
		if (*dest == '\0')
			break;

		dest++;
		source++;
	}

	if ((*dest - *source) > 0)

		return 1;

	else

		return -1;
}

char* stringreverse(char *str)//function to reverse a string
{
	char *ptr1, *ptr2, temp;
	for (ptr1 = str, ptr2 = str + stringlength(str) - 1; ptr1 < ptr2; ptr1++, ptr2--)
	{
		temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
	}
	return str;
}


int main()
{
	
	int operation, result;
	char string3[50] = "";
	char *temp;
	char *string1;
	char *string2;
	string1 = NULL;
	string2 = NULL;
	string1 = (char*)malloc(25 * sizeof(char));
	string2 = (char*)malloc(25 * sizeof(char));
	printf("Enter string1: ");
	gets_s(string1, 24);
	printf("Enter string2: ");
	gets_s(string2, 24);
	temp = string1;

	
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
			result = stringcompare(string1, string2);
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
			printf("Reversal of second string is %s\n", stringreverse(string2));
			break;

		}
		getchar();
		getchar();
		//printf("Select an operation to be performed: ");
		//scanf_s("%d", &operation);
		//printf("\n");
	}
	free(string1);
	free(string2);
	return 0;
}