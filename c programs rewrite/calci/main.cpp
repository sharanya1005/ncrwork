#include<stdio.h>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
#include<stack>
float add(float, float);
float sub(float, float);
float mul(float, float);
float divi(float, float);
//for checking precednce 
float precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}
float Operation(float a, float b, char op) {
	switch (op) {
	case '+': return add(a, b); break;
	case '-': return sub(a, b); break;
	case '*': return mul(a, b); break;
	case '/': return divi(a, b); break;
	default:cout << "invalid operator\n";
	}
}

float expevaluate(char *expr)
{
	stack<float> operand;
	stack<char> operators;
	int i;
	for (i = 0; expr[i] != '\0'; i++)//i is an iterator
	{
		if (expr[i] == ' ')//if it is space ,ignore
			continue;
		else if (expr[i] == '(')
			operators.push(expr[i]);//if it is a closing paranthesis,just push it in operators stack
		else if (isdigit(expr[i]))
		{
			int var = 0;
			while (expr[i] != '\0' && isdigit(expr[i]))//if it is digits,know the value
			{
				var = var * 10 + expr[i] - '0';
				i++;
			}
			i--;
			operand.push(var);
			cout << var << endl;
		}
		else if (expr[i] == ')')
		{
			while ((!operators.empty()) && operators.top() != '(')//if it is closing paranthesis,pop out two operands and perform respective operation until you encounter '('
			{
				float op1 = operand.top();
				operand.pop();
				float op2 = operand.top();
				operand.pop();

				char op = operators.top();
				operators.pop();

				operand.push(Operation(op2, op1, op));
			}
			operators.pop();

		}
		else
		{
			while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i]))
				//if precendence of top element in stack is less than the next character in string,just pop out the operands and perform operation
			{
				float op1 = operand.top();
				operand.pop();
				float op2 = operand.top();
				operand.pop();

				char op = operators.top();
				operators.pop();
				operand.push(Operation(op2, op1, op));
			}
			operators.push(expr[i]);
		}
	}
	while (!operators.empty())//if the operators stack is not empty,repeat the operations till it becomes empty
	{
		float op1 = operand.top();
		operand.pop();
		float op2 = operand.top();
		operand.pop();

		char op = operators.top();
		operators.pop();
		cout << Operation(op2, op1, op) << endl;
		operand.push(Operation(op2, op1, op));
	}
	cout << operand.top();
	return operand.top();
}
int main()
{
	char *expr = NULL;
	int n;
	cout << "enter n\n";
	cin >> n;
	expr = (char *)malloc(n * sizeof(char));
	printf("Enter expression to evaluate\n");
	scanf("%s", expr);
	printf("Result = %d\n", expevaluate(expr));
	system("pause");
	return 0;
}