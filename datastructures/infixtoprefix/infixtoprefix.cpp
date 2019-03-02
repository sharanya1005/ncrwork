#include<iostream>
#include<cstdio>
using namespace std;
struct __stack__
{
	int top;
	int *s;
	int size;
};
class _stack_
{
	struct __stack__ sta;
public:
	_stack_();//constructor
	void push(int);//push operation
	int pop();//pop operation
	int peek();//peek operation
	bool IsEmpty();//a function to check whether the stack is empty or not
	bool IsFull();//a function to check whether the stack is full or not
	void display();// to display what all elements are present in stack
	~_stack_();//destructor
	void getsize(int);//function to take stack size
};
_stack_::_stack_()
{
	sta.top = -1;
	sta.s = NULL;
	sta.size = 0;
}
void _stack_::getsize(int n)
{
	sta.size = n;
	sta.s = new int[n];//allocating memory
}
bool _stack_::IsFull()
{
	return (sta.top == (sta.size - 1));//condition which tells either full or not
}
bool _stack_::IsEmpty()
{
	return (sta.top == -1);//if the condition satisfies then the stack is empty
}
void _stack_::push(int ele)
{
	if (!IsFull())//to place an element stack should not be full
		sta.s[++sta.top] = ele;// placing an element
	else
		cout << "Stack is Full\n";//throwing a msg to user when stack is full
}
int _stack_::pop()
{
	int x = -999;
	if (!IsEmpty())//to pop an element stack should not be empty
		x = sta.s[sta.top--];//retriving the element
	else
		cout << "Stack is Empty\n";//if the stack is empty and we can't perform pop operation then throwing this msg to user
	return x;
}
int _stack_::peek()
{
	int x = -999;
	if (!IsEmpty())
		x = sta.s[sta.top];//pointing to the element that is on top of stack
	else
		cout << "Stack is Empty\n";
	return x;
}
void _stack_::display()//to print the elements in the stack
{
	for (int i = 0; i <= sta.top; i++)
		cout << "Elements in the stack: " << "\t" << sta.s[i] << endl;
}
_stack_::~_stack_()
{
	delete sta.s;
}
int value(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '(':
		return 1;
	case ')':
		return 4;
	}
}

void main()
{
	char *input, output[30], *input1;
	int length;
	cout << "Enter length";
	cin >> length;
	input = new char[length];
	cout << "Enter the input in infix notation: \n";
	for (int i1 = 0; i1 < length; i1++)
	{
		cin >> input[i1];
	}
	input1 = new char[length];
	for (int p1 = 0, p = length - 1; p >= 0; p1++, p--)
	{
		input1[p1] = input[p];

	}


	int j = 0, val, count = 0;
	_stack_ a;
	a.getsize(length);
	for (int x = 0; x < length; x++) 
	{

		if (input[x] == '(')
		{
			input1[x] = ')';
			x++;
		}
		else if (input[x] == ')') 
		{
			input1[x] = '(';
			x++;
		}
	}

	for (int i = 0; i < length; i++)
	{
		char ch = input1[i];
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&& ch <= 'Z'))
		{
			output[j] = ch;
			j++;
		}
		else
		{
			if (a.IsEmpty())
			{
				a.push(ch);

			}
			else

			{


				if (value(ch) > value(a.peek()))
				{
					if (value(ch) == 4)
					{
						while (a.peek() != '(')
						{
							output[j] = a.peek();
							j++;
							a.pop();
						}
						a.pop();

					}
					else
						a.push(ch);
				}

				else
				{
					if (value(ch) == 1)
					{
						a.push(ch);
					}
					else
					{
						while (!a.IsEmpty())
						{
							output[j] = a.peek();
							j++;
							a.pop();
						}
						a.push(ch);
					}
				}
			}
		}
	}
	while (!a.IsEmpty())
	{
		output[j] = a.peek();
		j++;
		a.pop();
	}
	cout << "Prefix notation is: ";
	for (int k = j - 1; k >= 0; k--)
		
		cout << output[k];
	delete(input);
	delete(input1);
}
