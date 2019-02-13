#include<stdio.h>
enum arithmetic
{
	addition,
	subtraction,
	multiplication,
	division
};
int main()
{
	int a, b, c, d;
	int real, imaginary;
	enum arithmetic operation;
	printf("Enter a number to choose the reqd operation: ");
	scanf("%d", &operation);
	printf("Enter first complex number a+ib\n");
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("Enter first complex number c+id\n");
	printf("c = ");
	scanf("%d", &c);
	printf("d = ");
	scanf("%d", &d);

	switch (operation)
	{
		case addition:
		{
		real = a + c;
		imaginary = b + d;
		printf("real: %d\n", real);
		printf("imaginary: %d\n", imaginary);
		break;
		}
		case subtraction:
		{
		real = a - c;
		imaginary = b - d;
		printf("real: %d\n", real);
		printf("imaginary: %d\n", imaginary);
		break;
		}
		case multiplication:
		{
			real = ( (a*c) - (b*d) );
			imaginary = ((a*d) + (b*c));
			printf("real: %d\n", real);
			printf("imaginary: %d\n", imaginary);
			break;
		}
		case division:
		{
			float real1, imaginary1;
			float temp;
			temp = ((c*c) + (d*d) );
			real1 = ((a*c) + (b*d)) / temp;
			imaginary1 = ( (b*c) - (a*d) )/temp;
			printf("real: %f\n", real1);
			printf("imaginary: %f\n", imaginary1);
			break;

		}
		default:
			printf("Enter a valid input\n");
		
	}
}