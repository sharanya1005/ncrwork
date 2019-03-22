#include<iostream>
using namespace std;
#include "Normal_add_sub.h"
#include "Absolute_add_sub.h"
using namespace Normal_ADD_SUB;
using namespace Absolute_ADD_SUB;
int main()
{
	Operation opobj;
	Operation_Abs abobj;
	float operand1, operand2;
	cout << "Enter the operands to perform normal addition: " << endl;
	cin >> operand1;
	cin >> operand2;
	cout<<"Result of addition is: "<<opobj.add(operand1, operand2)<<endl;
	cout << "Enter the operands to perform normal subtraction: " << endl;
	cin >> operand1;
	cin >> operand2;
	cout << "Result of normal subtraction is: " << opobj.sub(operand1, operand2) << endl;
	cout << "Enter the operands to perform absolute addition: " << endl;
	cin >> operand1;
	cin >> operand2;
	cout << "Result of absolute addition is: " << abobj.abs_add(operand1, operand2) << endl;
	cout << "Enter the operands to perform absolute subtraction: " << endl;
	cin >> operand1;
	cin >> operand2;
	cout << "Result of absolute subtraction is: " << abobj.abs_sub(operand1, operand2) << endl;
	return 0;
}