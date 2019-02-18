#include<iostream>
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
	_stack_();
	void push(int);
	int pop();
	int peek();
	bool IsEmpty();
	bool IsFull();
	void display();
	~_stack_();
	void getsize(int);
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
	sta.s = new int[n];
}
bool _stack_::IsFull()
{
	return (sta.top == (sta.size - 1));
}
bool _stack_::IsEmpty()
{
	return (sta.top == -1);
}
void _stack_::push(int ele)
{
	if (!IsFull())
		sta.s[++sta.top] = ele;
	else
		cout << "Stack is Full\n";
}
int _stack_::pop()
{
	int x = -999;
	if (!IsEmpty())
		x = sta.s[sta.top--];
	else
		cout << "Stack is Empty\n";
	return x;
}
int _stack_::peek()
{
	int x = -999;
	if (!IsEmpty())
		x = sta.s[sta.top];
	else
		cout << "Stack is Empty\n";
	return x;
}
void _stack_::display()
{
	for (int i = 0; i <= sta.top; i++)
		cout << "Elements in the stack: "<< "\t" << sta.s[i]<<endl;
}
_stack_::~_stack_()
{
	delete sta.s;
}
void main()
{
	int n;
	cout << "Enter the size of stack";
	cin >> n;
	_stack_ s1;
	s1.getsize(n);
	s1.push(10);
	s1.push(05);
	s1.pop();
	s1.push(19);
	s1.push(98);
	cout << "peek element: " << s1.peek() << endl;
	s1.display();
}