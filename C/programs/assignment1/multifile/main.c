#include<stdio.h>
int add(int a, int b);
int sub(int a, int b);
long int mul(int a, int b);
float divi(int a, int b);
int res = -1;
int main()
{
int a=10, b=6;
long int res1;
float res2;
res = add(a,b);
printf("addition: %d\n", res);

res = sub(a,b);
printf("subtraction: %d\n", res);

res1 = mul(a,b);
printf("multiplication: %ld\n", res1);

res2 = divi(a,b);
printf("division: %f\n", res2);
}


