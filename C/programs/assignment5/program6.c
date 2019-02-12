#include<stdio.h>
int main()
{
FILE *fp;
fp = fopen("program.c", "r");
while(!feof(fp))
{
char ch;
ch = fgetc(fp);
printf("%c", ch);
}
return 0;
fclose(fp);
}