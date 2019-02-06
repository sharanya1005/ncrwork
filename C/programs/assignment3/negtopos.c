#include<stdio.h>
int main()
{
int a[20];
int temp,i,j,n;
printf("Enter no of elements: \n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}


for(i=0;i<n;i++)
{
j=i;

if(a[i]>0)
{
}

else
{
while(j-1>=0 && a[j-1]>0)
{
temp=a[j];
a[j]=a[j-1];
a[j-1]=temp;
j--;
}
}
}
for(i=0;i<n;i++)
{
printf("Elements after arrangement: %d\n",a[i]);
}
}

