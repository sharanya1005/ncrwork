#include<iostream>
using namespace std;
void main()
{
	int i, first=0, last=0, middle=0, n, search, array[50];
	cout << "Enter number of elements: \n";
	cin >> n;
	cout << "Enter array elements: ";
	for (i = 0;i < n;i++)
	{
		cin >> array[i];
	}
	cout << "Enter the element you want to search for: \n";
	cin >> search;
	first = 0;
	last = n - 1;
	middle = (first + last) / 2;
	while (first <= last)
	{
		if (array[middle] < search)
			first = middle + 1;
		else
			if (array[middle] == search)
			{
				cout << search << "found at location " << (middle + 1) << endl;
				break;
			}
			else
				last = middle + 1;
		middle = (first + last) / 2;
	}
	if (first > last)
		cout << "Element not found! " << search << " isn't present in the list\n";

}