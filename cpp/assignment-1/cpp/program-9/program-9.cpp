﻿
#include<iostream>
using namespace std;
class change
{
public:
	int swap_value(int a, int b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
		cout << "Values after applying swap by value method are: " << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		return 0;
	}
	int swap_reference(int &a, int &b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
		cout << "Values after applying swap by reference method are: " << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		return 0;
	}
};
int main()
{
	int inp, a, b;
	change s1;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "Enter a number to choose the method: " << endl;
	cin >> inp;

	switch (inp)
	{
	case 0:
		s1.swap_value(a, b);
		break;
	case 1:
		s1.swap_reference(a, b);
		break;
	default:
		cout << "Enter a valid input" << endl;
	}
	cout << "a= " << a << "  " << "b= " << b << endl;
}