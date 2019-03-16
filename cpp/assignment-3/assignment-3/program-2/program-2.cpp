#include <iostream>
using namespace std;
#define SIZE 30
template <class T>
class Stack
{
	T sta[SIZE];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push(T element)
	{
		if (top == (SIZE - 1))
			cout << "Overflow\n";
		else
		{
			sta[++top] = element;
		}
	}
	T pop()
	{
		if (top == -1)
		{
			cout << "Underflow\n"; return 0;
		}
		else
		{
			return sta[top--];
		}
	}
};
class Complex
{
	float real, img;
public:
	Complex()
	{
		real = img = 0;
	}
	Complex(float r)
	{
		real = img = r;
	}
	Complex(float r, float i)
	{
		real = r;
		img = i;
	}
};
int main()
{
	Stack <int> s_int;
	Stack <float> s_float;
	Stack <Complex> s_Comp1, s_Comp2, s_Comp3;
	Complex c1, c2(2), c3(2, 3);
	s_int.push(2);
	s_int.push(3);
	int op1 = s_int.pop();
	cout << op1;
	s_float.push(5.0);
	s_float.push(6.0);
	float op2 = s_float.pop();
	cout << op2;
	s_Comp1.push(c1);
	s_Comp2.push(c2);
	s_Comp3.push(c3);
	s_Comp3.pop();
	s_Comp2.pop();
	getchar();
	return 0;
}