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
complex add_complex(complex &c1, complex &c2)//addition of two reference variablesof class complex 
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
	int operation;
	complex c1, c2,c3;
	c1.get_data();
	c2.get_data();
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