#include<stdio.h>
#include<math.h>

int main()
{
	int bin,dec,i,r;
	bin=0;

	printf("Enter decimal number between 0 and 32: ");
	scanf("%d",&dec);
	if(0<=dec && dec<32)
	{	
		for(i=0;i<5;i++)
		{
			r=dec%2;
			bin=bin + r*pow(10,i);
			dec=dec/2;
		}
		if(r==1)
			printf("Binary has leading bit 1: %d",bin);
		else
			printf("Binary doesn't have leading bit 1: %d",bin);
	}

	return 0;

			
}

