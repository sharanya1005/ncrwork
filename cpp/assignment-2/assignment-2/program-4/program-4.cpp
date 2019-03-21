/* creating a class and overloading various different operators */
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
	complex(float r, float i)//two parameter passing constructor
	{
		real = r;
		imag = i;
	}
	complex(const complex &c)//copy constructor
	{
		real = c.real;
		imag = c.imag;
	}
	complex operator-()//overloading subtraction operator
	{
		complex c;
		c.real = -real;
		c.imag = -imag;
		cout << "Output after subtraction: "<<endl;
		return c;
	}
	complex operator-(complex c)// overloading - operator and passing a complex object as a paramter
	{
		complex res;
		res.real = real - c.real;
		res.imag = imag - c.imag;
		cout << "Output after performing - : " << endl;
		return res;
	}
	complex operator+(complex c)//overloading + operator passing a complex object as a parameter
	{
		complex temp;
		temp.real = real + c.real;
		temp.imag = imag + c.imag;
		cout << "Output after performing addition: "<<endl;
		return (temp);
	}
	complex operator++()//overloading pre increment operator
	{
		complex temp;
		temp.real = ++real;
		temp.imag = ++imag;
		cout << "Output after performing pre increment operation: "<<endl;
		return (temp);
	}
	complex operator++(int x)//overloading post increment operator
	{
		complex temp;
		temp.real = real++;
		temp.imag = imag++;
		cout << "Output after performing post increment operation: "<<endl;
		return (temp);
	}
	/*complex operator=(complex c)// overloading = operator
	{
		real = c.real;
		imag = c.imag;
		cout << "Output after overloading = operator is: " << endl;
		return *this;
	}*/
	complex operator,(complex c)// overloading comma operator
	{
		cout << "output afer overloading comma operator is: " << endl;
		return c;
	}
	void display()
	{
		cout << real << "  i  " << imag << endl;
	}
	friend ostream& operator<<(ostream& cout, complex c);
	friend	istream& operator >> (istream& cin, complex& c);
};
ostream& operator<<(ostream& cout, complex c)
{
	cout << "real = " << c.real << endl;
	cout << "imag = " << c.imag << endl;
	return (cout);
}
istream& operator >> (istream& cin, complex &c)
{
	cin >> c.real;
	cin >> c.imag;
	return (cin);
}

void main()
{
	complex c1, c2(3, 5), c3(c2), c4(7), c5, c6, c7, c8,c9,c10(5,6),c11;
	c5 = -c2;
	c5.display();
	c6 = c2 + c4;
	c6.display();
	c7 = c2 - c4;
	c7.display();
	c8 = ++c2;
	c8.display();
	c9 = c2++;
	c9.display();
	cout << c10;
	c11 = (c1, c2);
	c11.display();

	

}