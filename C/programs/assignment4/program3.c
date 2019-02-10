#include<stdio.h>
void main()
{
int count=0, overallcount=0;
char *a;
char *s [ ] = {"we will teach you how to ", "Move a mountain ", "Level a building " , "Erase the past ", "Make a million "};
for(int j=0; j<5; j++)
{
	char *a = *(s + j);
	for(int i=0; a[i]!='\0'; i++)
	{
		if(a[i] == 'e')
			{
			count++;
			}
	}
overallcount = count + overallcount;
printf(" count[%d] = %d\n",j,count);
count=0;
}
printf("\n overall count of e is %d", overallcount);
}



