#include<iostream>
using namespace std;
void main()
{
	int arr[20], i, searchele,n;
	cout << "Enter the size of an array: ";
	cin >> n;
	cout << "Enter array elements: " << endl;
	for (i = 0; i < n;i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the element to search in the given array: ";
	cin >> searchele;
	for (i = 1;i < n;i++)
	{
		if (searchele == arr[i])
			cout << "Element " << searchele << " is found at " << (i + 1) << endl;
	}

	//cout << "The element which we want to search is not present in the array\n";
}