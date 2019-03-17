/* program to swap two numbers either using swap by value or swap by reference*/

#include<iostream>
using namespace std;
class change
{
public:
	int swap_value(int a, int b)//functionfor swap by value
	{
		a = a + b;
		b = a - b;
		a = a - b;
		cout << "Values after applying swap by value method are: " << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		return 0;
	}
	int swap_reference(int &a, int &b)//function for swap by reference
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
	cout << "First operand a = ";
	cin >> a;
	cout << "Second operand b = ";
	cin >> b;
	cout << "Enter a number to choose the method: " << endl;
	cin >> inp;

	switch (inp)
	{
	case 1:
		s1.swap_value(a, b);
		break;
	case 2:
		s1.swap_reference(a, b);
		break;
	default:
		cout << "Enter a valid input" << endl;
	}
	cout << "a= " << a << "  " << "b= " << b << endl;
}