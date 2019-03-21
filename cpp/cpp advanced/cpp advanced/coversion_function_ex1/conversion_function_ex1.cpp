#include<iostream>
using namespace std;
class pwr
{
	double base;
	int exponent;
	double result;
public:
	pwr(double b, int exp)//parameterized constructor
	{
		base = b;
		exponent = exp;
		result = 1;
		for (; exp != 0; exp--)
		{
			result = base * result;
		}
	}
	double operator+(pwr p)//overloading + operator
	{
		double result_val;
		result_val = result + p.result;
		cout << "Inside operator overloading" << endl;
		return result_val;
	}
	operator double()//conversion function
	{
		cout << "Inside conversion function" << endl;
		return result;
	}
};
int main()
{
	double base;
	int exponent;
	cout << "Enter the base and exponent of object1: " << endl;
	cout << "Base: ";
	cin >> base;
	cout << "Exponent: ";
	cin >> exponent;
	pwr obj(base, exponent);
	cout << "Enter the base and exponent of object2: " << endl;
	cout << "Base: ";
	cin >> base;
	cout << "Exponent: ";
	cin >> exponent;
	pwr obj2(base, exponent);
	double result_conv_funcn = obj + 11.5;
	cout << "Result of conversion function is: " << result_conv_funcn << endl;
	double result_two_objects = obj + obj2;
	cout << "Result of operator overloading i.e., adding two objects is: " << result_two_objects << endl;
	return 0;
}