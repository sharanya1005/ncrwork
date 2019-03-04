#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include "mylib.h"

int main()
{
	int n_op1 = 10, n_op2 = 20;
	int addition = add(n_op1, n_op2);
	int subtraction = sub(n_op1, n_op2);
	int multiplication = mul(n_op1, n_op2);
	float division = divide(n_op1, n_op2);
	printf("Addition of %d and %d is %d", n_op1, n_op2, addition);
	printf("subtraction of %d and %d is %d", n_op1, n_op2, subtraction);
	printf("multiplication of %d and %d is %d", n_op1, n_op2, multiplication);
	printf("division of %d and %d is %f", n_op1, n_op2, division);

	printf("Waiting for user input exiting the process\n");
	getchar();
	return 0;
}