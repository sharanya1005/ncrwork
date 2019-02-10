#include<stdio.h>

int main()
{
	int min,max,flag,i,j;
	

	printf("Enter a min number: ");
	scanf("%d",&min);
	printf("Enter a max number: ");
	scanf("%d",&max);

	for(i=min;i<=max;i++)
	{
		flag=1;
		for(j=2;j<=i/2;j++)
		{	
			if(i%j==0)
			{flag=0;
			break;}
		}
		if(flag==1)
		printf(" %d ",i);
		
	}
	return 0;
}
