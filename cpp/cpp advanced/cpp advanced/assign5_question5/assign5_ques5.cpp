#include<iostream>
using namespace std;
/*int Add(int x, int y)
{
	return x + y;
 }
int Mul(int x, int y)
{
	return x * y;
}
int operate(int x, int y, int(*f)(int, int))
{
	return (*f)(x, y);
}*/
class operate
{
public:
	operate()
	{

	}
	virtual int operator()(int, int) = 0;
};
class Add :public operate
{
public:
	Add()
	{

	}
	 int operator()(int x, int y)
	{
		return x + y;
	}
};
class Mul :public operate
{
public:
	Mul()
	{

	}
	 int operator()(int x, int y)
	{
		return x * y;
	}
};
int operate_fun(int x, int y, operate *obj)
{
	return (*obj)(x, y);
}
int main()
{
	operate *obj = new Add();
	operate *obj1 = new Mul();
	int operand1, operand2, result1, result2;
	cout << "Enter the operands to perform addition" << endl;
	cin >> operand1;
	cin >> operand2;
	result1 = operate_fun(operand1, operand2, obj);
	cout << "Enter the operands to perform addition" << endl;
	cin >> operand1;
	cin >> operand2;
	result2 = operate_fun(operand1, operand2, obj1);
	cout << "Result of addition is: " << result1<<endl;
	cout << "Result of multiplication is: " << result2<<endl;
	return 0;
}