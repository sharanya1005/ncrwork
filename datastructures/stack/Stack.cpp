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
void main()
{
	int operation, n;
	_stack_ s1;
	cout << "Enter the size of stack: ";
	cin >> n;
	s1.getsize(n);
	cout << "Select an operation that needs to be performed. 1. push  2. pop  3. peek  4.display \n";
	cin >> operation;
	while (operation <= 4 && operation != 0)
	{
		switch (operation)
		{
		case 1:
			cout << "Enter the element to push onto the stack: ";
			cin >> n;
			s1.push(n);
			break;
		case 2:
			s1.pop();
			cout << "An element is popped out of the stack\n";
			break;
		case 3:
			cout << "peek element: " << s1.peek() << endl;
			break;
		case 4:
			s1.display();
			break;
		}
		cin >> operation;
	}
	getchar();
}