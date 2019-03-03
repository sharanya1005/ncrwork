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
	complex(const complex &c)
	{
		real = c.real;
		imag = c.imag;
	}
	complex operator-()
	{
		complex c;
		c.real = -real;
		c.imag = -imag;
		cout << "Output after subtraction: ";
		return c;
	}
	complex operator+(complex c)
	{
		complex temp;
		temp.real = real + c.real;
		temp.imag = imag + c.imag;
		cout << "Output after performing addition: ";
		return (temp);
	}
	complex operator++()
	{
		complex temp;
		temp.real = ++real;
		temp.imag = ++imag;
		cout << "Output after performing pre increment operation: ";
		return (temp);
	}
	complex operator++(int x)
	{
		complex temp;
		temp.real = real++;
		temp.imag = imag++;
		cout << "Output after performing post increment operation: ";
		return (temp);
	}
	void display()
	{
		cout << real << "  i  " << imag << endl;
	}
	/*friend ostream& operator<<(ostream& cout, complex c);
	friend	istream& operator >> (istream& cin, complex &c);*/
};
/*ostream& operator<<(ostream& cout, complex c)
{
	cout << "real = " << c.real << endl;
	cout << "imag = " << c.imag << endl;
	return (cout);
}
istream& operator >> (istream& cin, complex &c)
{
	cin >> c.real << endl;
	cin >> c.imag<<endl;
	return (cin);
}*/

void main()
{
	complex c1, c2(3, 5), c3(c2), c4(7), c5, c6, c7, c8;
	c5 = -c2;
	c5.display();
	c6 = c2 + c4;
	c6.display();
	c7 = ++c2;
	c7.display();
	c8 = c2++;
	c8.display();
	/*cout << c3;
		cin >> c4;*/


}