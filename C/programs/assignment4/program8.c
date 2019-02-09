#include<stdio.h>
#include<string.h>
int main()
{
int n;
char *b[60];
char name[15];
printf("Enter number of strings: ");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
printf("Enter the name of %d string: ",i);
scanf("%s", name);
int len = strlen(name);
b[i]= (char *)malloc( (len+1)*sizeof(char) );

if(b[i]==NULL)
{
for( int j=i;j>=0;j--)
{
free(b[j]);
}
return -1;
}
strcpy(b[i],name);
}
for(int k=0;k<n;k++)
{
printf("%s", b[k]);
}
}