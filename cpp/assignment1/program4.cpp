#include<iostream>
using namespace std;
inline int add(int a, int b)
{
	return (a + b);
}
inline int sub(int a, int b)
{
	return (a - b);
}
inline int mul(int a, int b)
{
	return (a * b);
}
inline int divi(int a, int b)
{
	return (a / b);
}
inline int mod(int a, int b)
{
	return (a % b);
}
void main()
{
	int a, b;
	cout << "Enter two numbers";
		cin >> a >> b;
	cout << "\n add = " << add(a, b);
	cout << "\n sub = " << sub(a, b);
	cout << "\n mul = " << mul(a, b);
	cout << "\n div = " << divi(a, b);
	cout << "\n mod = " << mod(a, b);
}