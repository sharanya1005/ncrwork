#include<stdio.h>
void main()
{
	int len, i=0, j, sum,res;
	printf("enter the size of array: ");
	scanf("%d", &len);
	int a[10];
	printf("\n enter array elements: ");
	int n = len;
	for (int k = 0; k < n; k++)
	{
		scanf("%d", &a[k]);

	}
	printf("\n enter the sum: ");
	scanf("%d", &sum);
	for (i = 0;i < n; i++)
	{
		res = a[i];
		for (j = i + 1; j < n; j++)
		{
			if (res == sum)
			{
				printf("Sum found between indexes %d and %d", i, j - 1);
				break;
			}
			else if ((res > sum && j == n)||(sum==0&&res!=0))
			{
				printf("\n no sub array found");
				break;
			}
			res = res + a[j];
		}

	}


}