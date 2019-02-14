#include<stdio.h>
void count()
{
	int alphabet = 0, digit = 0, space = 0, specialcharacter = 0;
	FILE *fp;
	fp = fopen("program.txt", "r");
	while (!feof(fp))
	{
		char ch;
		ch = fgetc(fp);
		if ( (ch >= 'a' && ch <= 'z') || ( ch >= 'A' && ch <= 'Z') )
			alphabet++;
		else
			if (ch >= '0' && ch <= '9')
				digit++;
			else
				if (ch == ' ')
					space++;
				else
					specialcharacter++;
	}
	printf("No. of alphabets: ", alphabet);
	printf("No. of digits: ", digit);
	printf("No. of spaces: ", space);
	printf("No. of special characters: ", specialcharacter);

}