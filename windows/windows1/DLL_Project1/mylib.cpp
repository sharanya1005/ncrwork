#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

#include<iostream>
#include "mylib.h"
using namespace std;

int main()
{
	int n_op1, n_op2,operation;
	int addition, subtraction, multiplication;
	float division;
	cout<<"Enter two operands to perform arithmetic operations\n";
	cout<<"operand 1: ";
	cin >> n_op1;
	cout << "operand 2: ";
	cin >> n_op2;
	cout << "Choose the operation you want to perform. 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n";
	cin >> operation;

	while (operation <= 4 && operation != 0)
	{
		switch (operation)
		{
		case 1:
			 addition = add(n_op1, n_op2);
			printf("Addition of %d and %d is %d\n", n_op1, n_op2, addition);
			break;
		case 2:
			 subtraction = sub(n_op1, n_op2);
			printf("subtraction of %d and %d is %d\n", n_op1, n_op2, subtraction);
			break;
		case 3:
			 multiplication = mul(n_op1, n_op2);
			printf("multiplication of %d and %d is %d\n", n_op1, n_op2, multiplication);
			break;
		case 4:
			 division = divide(n_op1, n_op2);
			printf("division of %d and %d is %f\n", n_op1, n_op2, division);
			break;
		default:
			printf("Enter valid input\n");

		}
		cin >> operation;
	}
	
}