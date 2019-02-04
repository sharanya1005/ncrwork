#include<stdio.h>

int main()
{
	int n;
	int count,max,min,sum;
	float avg;

	count=0;
	max=0;
	min=99999;
	sum=0;
	avg=0;

	while(1)
	{
		printf("Enter number:");
		scanf("%d",&n);
		if(n<0)
		 break;
		
		if(n>max)
		 max=n;
		if(n<min)
		 min=n;
		sum+=n;
		count++;
	}
		
	avg=(float)sum/count;
	
	printf("Count Pos = %d\n Max = %d\n Min = %d\n Sum = %d\n Avg = %f\n",count,max,min,sum,avg);
	return 0;
}
