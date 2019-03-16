﻿


#include<iostream>
using namespace std;
class complex
{
	float real;
	float imag;
public:
	complex()
	{
		real = 0;
		imag = 0;
	}
	complex(float r)
	{
		real = imag = r;
	}
	complex(float r, float i)
	{
		real = r;
		imag = i;
	}
	void add_complex(complex &c1, complex &c2)
	{
		real = c1.real + c2.real;
		imag = c1.imag + c2.imag;
		cout << "add_real: " << real << endl;
		cout << "add_imag: " << imag << endl;
	}
	void mul_complex(complex &c1, complex &c2)
	{
		real = (c1.real * c2.real) - (c1.imag * c2.imag);
		imag = (c1.real * c2.imag) + (c2.real * c1.imag);
		cout << "mul_real: " << real << endl;
		cout << "mul_imag: " << imag << endl;
	}
};
int main()
{
	complex c1(9, 5), c2(4, 6), c3, c4;
	c3.add_complex(c1, c2);
	c4.mul_complex(c1, c2);
	return 0;
}