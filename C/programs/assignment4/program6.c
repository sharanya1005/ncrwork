#include<stdio.h>
int reverse(char[], int , int );
int main()
{
char a[30];
printf("Enter a string: ");
gets(a);
int l= strlen(a);
reverse(a, 0, l-1);
}
int reverse(char b[], int x, int y)
{
int i = x;
int j = y;
if(i>=j)
{
printf("%s",b);
return 0;
}
char temp;
temp = b[i];
b[i]= b[j];
b[j]=temp;
i++;
j--;
reverse(b,i,j);
return 0;
}


