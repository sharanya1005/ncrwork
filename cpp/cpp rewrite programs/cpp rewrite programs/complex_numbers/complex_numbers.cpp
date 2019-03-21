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
	void get_data()
	{
		cout << "Enter the real and imaginary part: " << endl;
		cin >> real >> imag;
	}
	friend complex add_complex(complex &c1, complex &c2);
	friend complex mul_complex(complex &c1, complex &c2);
};
complex add_complex(complex &c1, complex &c2)//addition of two reference variables of class complex 
{
	complex c3;
	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;
	cout << "add_real: " << c3.real << endl;
	cout << "add_imag: " << c3.imag << endl;
	cout << "Result of addition of two complex numbers is: " << c3.real << "  +i  " << c3.imag << endl;
	return c3;
}
complex mul_complex(complex &c1, complex &c2)//multiplication of two reference variables of class complex
{
	complex c3;
	c3.real = (c1.real * c2.real) - (c1.imag * c2.imag);
	c3.imag = (c1.real * c2.imag) + (c2.real * c1.imag);
	cout << "mul_real: " << c3.real << endl;
	cout << "mul_imag: " << c3.imag << endl;
	cout << "Result of multiplication of two complex numbers is: " << c3.real << "  +i  " << c3.imag << endl;
	return c3;
}

int main()
{
	int operation,construct,real,imag;
	complex c1, c2(real),c3(real,imag),c4(complex);
	c1.get_data();
	c2.get_data();
	cout << "choose the constructor which you want to select. 1.default constructor\n 2. single parameter passing\n 3. parameter passing constructor\n 4. copy constructor\n";
	cin >> construct;
	switch (construct)
	{
	case 1: 
		c1;
		break;
	case 2:
		c2;
		break;
	case 3:
		c3;
		break;
	case 4:
		c4;
		break;
	default:
		cout << "enter valid input" << endl;

	}
	cout << "choose the operation you want to perform: 1. addition\n 2.multiplication\n";
		cin >> operation;
		
		switch (operation)
		{
		case 1:
			c3 = add_complex( c1, c2);
			break;
		case 2:
			c3 =  mul_complex(c1,c2);
			break;
		default:
			cout << "Enter a valid input" << endl;
		}
}