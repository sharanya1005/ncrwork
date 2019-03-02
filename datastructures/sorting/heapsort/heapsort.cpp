﻿
/*heap sorting*/

#include<iostream>
using namespace std;
class sort
{

	int a[20], n, i, j;
public:
	void input()
	{
		cout << "enter size: "<<endl;
		cin >> n;
		cout << "enter " << n << " elements ";
		for (int p = 0; p < n; p++)
		{
			cin >> a[p];
		}
		cout << endl;
	}
	void heapsort()
	{
		for (i = (n / 2) - 1; i >= 0; i--)
			buildheap(i, n);
		for (j = 1; j <= n - 1; j++)
		{
			swap(a[0], a[n - j]);
			buildheap(0, n - j);
		}
	}

	void buildheap(int i, int n)
	{
		int temp = a[i];
		int c;
		for (; 2 * i + 1 < n; i = c)
		{
			c = 2 * i + 1;
			if ((c + 1) < n && a[c + 1] > a[c])
				c++;
			if (a[c] > temp)
				a[i] = a[c];
			else
				break;
		}
		a[i] = temp;
	}
	void swap(int &a, int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	void display()
	{
		cout << "Sorted elements are: ";
		for (int p = 0; p < n; p++)
		{
			cout << a[p] << " ";
		}
	}
};

void main()
{
	sort s;
	s.input();
	s.heapsort();
	s.display();
}