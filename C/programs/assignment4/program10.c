#include<stdio.h>
int delete(char [],char);
int main()
{
char a[15];
char b;
printf("Enter a string: ");
scanf("%s",a);
printf("Enter a character: ");
scanf("%s",&b);
delete(a, b);
}

int delete(char a[],char b)
{
int i,j;
for(i=0;i<strlen(a);i++)
{
if(a[i]==b)
{
for(j=i+1;j<strlen(a);j++)
{
a[i]=a[j];
j++;
}
a[i] ='\0';
}
}
printf("new string: %s",a);
return 0;
}