#include<stdio.h>
int main()
{
int hex,dec=0,rem=0,i=0,j,a[10],b[10],n,mask,res=0,res1=0,res2=0;
long int bin;
printf("Enter a hexadecimal number: \n");
scanf("%x",&hex);
n=hex;
printf("integer is %d\n",n);
dec=n;
while(dec!=0)
{
rem = dec%2;
a[i]=rem;
rem=!rem;
b[i]=rem;
i++;
dec=dec/2;
}
for(j=i-1;j>=0;j--)
{
printf("%d",b[j]);
}
printf("\n enter hexadecimal number: ");
scanf("%x",&hex);
printf("enter the masking value: ");
scanf("%x",&mask);
res=hex&mask;
res1=hex|mask;
res2=hex^mask;
printf("bitwise and operation of %x and %x is %x\n",hex,mask,res);
printf("bitwise or operation of %x and %x is %x\n",hex,mask,res1);
printf("bitwise xor operation of %x and %x is %x",hex,mask,res2);
}
