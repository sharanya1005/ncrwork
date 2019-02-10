#include<stdio.h>

int main()
{

	int res;
	int a,b,c;
	int val=0xCAFE;
	int test=0x000F;

	res=val&test;
	if(res==16||res==14||res==13||res==11||res==7)
		printf("Atleast 3 of 4 LSB on\n");
	else
		printf("Atleast 3 of 4 LSB not on\n");



	c=0x00FF;
	a=val&c;
	a=a<<8;
	b=val>>8;
	
	res=a+b;

	printf("%X   %X   %X \n",a,b,res);




	res = val>>4;

	res = res + 0xE000;
	
	printf("%X\n",res);

	
	return 0;
}
