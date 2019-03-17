/* program to add and multiply two complex numbers*/

#include<iostream>
using namespace std;

class complex
{
	float real;
	float imag;
public:
	complex()//default constructor
	{
		real = 0;
		imag = 0;
	}
	complex(float r)//single parameter passing
	{
		real = imag = r;
	}
	complex(float r, float i)//parameter passing constructor
	{
		real = r;
		imag = i;
	}
	void add_complex(complex &c1, complex &c2)//addition of two complex numbers
	{
		real = c1.real + c2.real;
		imag = c1.imag + c2.imag;
		cout << "add_real: " << real << endl;
		cout << "add_imag: " << imag << endl;
	}
	void mul_complex(complex &c1, complex &c2)//multiplication of two complex numbers
	{
		real = (c1.real * c2.real) - (c1.imag * c2.imag);
		imag = (c1.real * c2.imag) + (c2.real * c1.imag);
		cout << "mul_real: " << real << endl;
		cout << "mul_imag: " << imag << endl;
	}
};
int main()
{
	float num1_real, num2_real, num1_imag, num2_imag;
	cout << "Enter the real and imaginary part of number 1: " << endl;
	cin >> num1_real >> num1_imag;
	cout << "Enter the real and imaginary part of number 2: " << endl;
	cin >> num2_real >> num2_imag;
	complex c1(num1_real,num1_imag), c2(num2_real, num2_imag), c3, c4;
	c3.add_complex(c1, c2);
	c4.mul_complex(c1, c2);
	return 0;
}