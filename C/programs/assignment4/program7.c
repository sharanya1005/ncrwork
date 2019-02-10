#include<stdio.h>
#include<string.h>
int main()
{
int n,i,len,j,x,y,k;
char *s[60];
char name[15];
printf("Enter number of strings: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("Enter name of %d string: ",i);
	scanf("%s",name);
	len = strlen(name);
	s[i] = (char *)malloc( (len +1) * sizeof (char));

if(s[i]==NULL)
{
	for(j=i;j>=0;j--)
{
	free(s[j]);
}
	return -1;
}
strcpy(s[i],name);
}
	for(x=0;x<n-1;x++)
{
	for(y=0;y<n-x-1;y++)
{
	if( strcmp(s[y],s[y+1])>0)
{
	char *temp;
	temp = s[y];
	s[y] = s[y+1];
	s[y+1] = temp;
}
}
}
for(k=0;k<n;k++)
{
printf("%s",s[k]);
}
}

