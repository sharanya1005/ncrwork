#include<stdio.h>
int main()
{
char a[15],b[15];
int i,j;
printf("Enter two strings:");
scanf("%s",a);
scanf("%s",b);
for(i=0;i<strlen(a);i++)
{
for(j=0;j<strlen(b);j++)
{
if(a[i]==b[j])
{
printf("Match found at %d",i);
return 0;
}
}
}
}