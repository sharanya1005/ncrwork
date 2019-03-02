#include<iostream>
#include<cstdio>
using namespace std;
void main()
{
	int i, j, k, n, flag = 0;
	int a[40];
	cout << "Enter the size of an array: ";
	cin >> n;
	cout << "Enter array elements: ";
	for (k = 0; k < n; k++)
	{
		cin >> a[k];
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}

		}
		if (flag == 0)
			break;
	}
	cout << "sorted array is: ";
	for (k = 0; k < n; k++)
		cout << a[k] << " ";
	getchar();

}