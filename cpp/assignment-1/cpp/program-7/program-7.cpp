/* program to define a matrix and should perform multiplication of the entered two matrices which are of the order 2*/

#include<iostream>
#include<cmath>
using namespace std;
class matrix
{
	int a[2][2];
public:
	void input()//taking input values into a matrix
	{
		
		for (int i = 0; i < 2; i++)//rows
		{
			for (int j = 0; j < 2; j++)//columns
			{
				cin >> a[i][j];
			}
		}
	}
	friend void mul(matrix, matrix);//friend function
};
void mul(matrix m1, matrix m2)//performing multiplication
{
	int c[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				c[i][j] += m1.a[i][k] * m2.a[k][j];
			}
			cout << c[i][j] << " ";
		}
		cout << endl;
	}


}
void main()
{
	int rows, columns;
	cout << "Enter no. of rows in a matrix: ";
	cin >> rows;
	cout << "Enter no. of columns in a matrix: ";
	cin >> columns;
	if (rows == columns)
	{
		if (rows && columns == 2)
		{

			cout << "2x2 matrix multiplication will be done" << endl;
			matrix x, y;
			cout << endl << "Enter the elements of first matrix: ";
			x.input();
			cout << endl << "Enter the elements of second matrix: ";
			y.input();
			mul(x, y);
		}
		else
		{
			cout << "enter a 2x2 matrix to perform multiplication" << endl;
			
		}
		
	}
	else
		cout << "Matrix multiplication is not possible as no. of rows are not equal to no. of columns"<<endl;
}