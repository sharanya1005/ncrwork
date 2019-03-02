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
	_stack_(int n);//parameter passing constructor
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
_stack_::_stack_(int n)
{
	sta.top = -1;
	sta.s = new int[n];
	sta.size = n;
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


int precedence(char c)
{
	if (c == '/' || c == '*')
		return 2;
	if (c == '-' || c == '+')
		return 1;
	if (c == '(' || c == '[')
		return -2;
}
char* infix_post()
{
	char str[20];
	char *temp = new char[30];
	char ch;
	int k = 0;
	cout << "enter the expression to evaluate:  ";
	cin >> str;
	_stack_ s1(20);
	for (int i = 0; str[i] != '\0'; i++)
	{
		ch = str[i];
		if (ch == '*' || ch == '+' || ch == '-' || ch == '/')
		{
			if (s1.IsEmpty())
			{
				s1.push(ch);
			}
			else
			{
				if (precedence(ch) > precedence(s1.peek()))
				{
					s1.push(ch);
				}
				else
				{
					while ((!s1.IsEmpty()) && (precedence(ch) <= precedence(s1.peek())))
					{
						temp[k] = s1.pop();
						k++;
					}
					s1.push(ch);
				}
			}

		}
		else if (ch == '(' || (ch == '['))
		{
			s1.push(ch);
		}
		else if (ch == ')' || ch == ']')
		{
			while ((!s1.IsEmpty()) && ((s1.peek() != '['&&ch == ']') || (s1.peek() != '('&&ch == ')')))
			{
				temp[k] = s1.pop();
				k++;
			}
			s1.pop();
		}
		else
		{
			temp[k] = str[i];
			k++;
		}
	}
	while (!s1.IsEmpty())
	{

		temp[k] = s1.pop();
		k++;
	}
	if (s1.IsEmpty())
	{
		temp[k] = '\0';
		cout << "The postfix expression is:  " << temp << endl;
		return temp;
	}
	else
	{
		cout << "invalid";
		return NULL;
	}

}
int main()
{

	char *str = new char[30];
	int a, b, res;
	_stack_ s1(20);
	str = infix_post();
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 48 && str[i] < 58)
		{
			s1.push(int(str[i] - 48));
		}
		else if (str[i] == '*')
		{
			a = s1.pop();
			b = s1.pop();
			s1.push(b*a);
		}
		else if (str[i] == '-')
		{
			a = s1.pop();
			b = s1.pop();
			s1.push(b - a);
		}
		else if (str[i] == '/')
		{
			a = s1.pop();
			b = s1.pop();
			s1.push(b / a);
		}
		else if (str[i] == '+')
		{
			a = s1.pop();
			b = s1.pop();
			s1.push(b + a);
		}
	}
	res = s1.pop();
	cout << "The result is: " << res;
	getchar();
	getchar();
	return 0;
}
