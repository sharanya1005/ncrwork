#include<stdio.h>
int main()
{
float base, gross;
printf("enter the base salary: ");
scanf("%f",&base);
if(base>=1 && base <=4000)
gross= base + base* 0.1 + base *0.5;
if(base>=4001 && base <=8000)
gross= base + base* 0.2 + base *0.6;
if(base>=8001 && base <=12000)
gross= base + base* 0.25 + base *0.7;
if(base>=12000)
gross= base + base* 0.3 + base *0.8;
printf("Gross salary of an employee: %f",gross);
return 0;
}

