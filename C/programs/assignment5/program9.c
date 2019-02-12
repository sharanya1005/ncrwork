#include<stdio.h>
int main()
{
FILE *fp;
char a[30],ch;
int len;
gets(a);
fp = fopen("input.txt", "w");
len = strlen(a);
for( int i=0; i<len;i++)
{
ch = a[i];
if(ch >='a' && ch<= 'z')
{
ch = ch - 32;
}
else
{
ch = ch + 32;
}
fputc(ch, fp);
}
fclose(fp);
return 0;
}



