#include<iostream>
using namespace std;
extern float division(float operand1, float operand2)
{
	float result;
	if (operand2 == 0)
	{
		cout << "Enter a non-zero number in the denominator" << endl;
		system("pause");

	}
	result = operand1 / operand2;
	return result;
}