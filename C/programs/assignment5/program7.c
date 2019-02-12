#include<stdio.h>
int main(int argc,char **argv)
{
	int len;
	if (argc != 2)
	{
		printf("enter correct number of arguments");
		return 0;
	}
	FILE *fp,*rp;
	fp = fopen(argv[1], "w+");
	unsigned char ch2;
	char a[10],ch,ch1;
	gets(a);
	len = strlen(a);
	for (int i = 0; i < len; i++)
		{
			ch = a[i];
			fputc(ch,fp);
		}

	fclose(fp);
	rp = fopen(argv[1], "r");
	while (!feof(rp))
	{
		ch1 = fgetc(rp);
		printf("%c", ch1);
	}
	printf("\n");
	fclose(rp);
	rp = fopen(argv[1], "r");
	
	while (!feof(rp))
	{
		ch2 = fgetc(rp);
		printf("%u", ~ch2);
	}

	
	
	fclose(rp);

}