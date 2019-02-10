#include<stdio.h>
#include<string.h>
int delete(char a[], char b[]);
int main()
{
char a[15],b[15];
printf("Enter string1: ");
gets(a);
printf("Enter string2: ");
gets(b);
delete(a,b);
printf("%s",a);
return 0;
}
int delete(char a[], char b[])
{
int i,j,k;
k=0;
for(i=0; a[i]!='\0';++i)
{
for(j=0; (a[i]!=b[j]) && b[j]!='\0' ; ++j)
if(b[j] == '\0')
a[k++] = a[i];
}
a[k]='\0';
return 0;
}
