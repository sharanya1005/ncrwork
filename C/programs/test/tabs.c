#include<stdio.h>
void tabs()
{
	char ch1, ch;
	FILE *fp, *fp1;
	fp = fopen("sample.txt", "r");
	fp1 = fopen("sample1.txt", "w");
	if(fp == NULL || fp1 == NULL)
	{
	printf("Cannot open file\n");
	return 0;
	}
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '\t')
		{
			ch1 = '\\';
			fputc('ch1', fp1);
			ch1 = 't';
			fputc(ch, fp1);
			ch = fgetc(fp);
		}
		fputc(ch,fp1);
	}
	printf("Replaced tabs with character\n");
	fclose(fp);
	fclose(fp1);
	return 0;
}
