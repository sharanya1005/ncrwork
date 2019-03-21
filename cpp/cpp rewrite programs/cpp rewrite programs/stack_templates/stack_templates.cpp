/* template stack class. using template class creating stack objects of int, char* and float type */

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
template <typename T>
struct _stack_
{
	int size;
	T *s;
	int top;
};
template <class T>
class Stack
{
	struct _stack_<T> sta;
public:
	Stack(int);//constructor
	void push(T);//function to perform push operation
	void pop();//function to perform pop operation
	T peek();//function to show the peek element
	bool IsEmpty();//which returns a value saying whether the stack is empty or not
	bool IsFull();//function which returns a value saying whether the stack is full or not
	void display();//funcion to display the elements in the stack
	~Stack();//destructor
};
template <class T>
Stack<T>:: ~Stack()
{
	delete sta.s;
}
template <class T>
Stack<T>::Stack(int s)
{
	sta.top = -1;
	sta.size = s;
	sta.s = new T[s];
}
template <class T>
bool Stack<T>::IsFull()
{
	return (sta.top == (sta.size - 1));
}

template <class T>
bool Stack<T>::IsEmpty()
{
	return (sta.top == -1);
}
template <class T>
void Stack<T>::push(T ele)
{
	if (!IsFull())
	{
		sta.s[++sta.top] = ele;
		cout << "An element " << ele << " is pushed on to the stack" << endl;
	}
	else
		cout << "Stack is full: overflow"<<endl;
}
template <class T>
void Stack<T>::pop()
{
	T x;
	if (!IsEmpty())
	{
		x = sta.s[sta.top--];
		cout << "An element " << x <<" is popped from the stack"<< endl;
	}
	else
		cout << "Stack is Empty: underflow"<<endl;

}
template <class T>
T Stack<T>::peek()
{
	T x;
	if (!IsEmpty())
	{
		x = sta.s[sta.top];
		cout << "The peek element is: " << x << endl;
	}
	else
		cout << "Stack is Empty";
	return x;
}
template <class T>
void Stack<T>::display()
{
	cout << "The elements in the stack are: " << endl;
	for (int i = 0; i <= sta.top; i++)
		cout << sta.s[i] << endl;

}
template <class T>
void operation(Stack<T> a)
{
	int operation;
	T element;
	
	cout << "\n 1.Push";
	cout << "\n 2.Pop";
	cout << "\n 3.Peek";
	cout << "\n 4.Display\n";
	do
	{
		cout << "Choose the operation you want to perform: " << endl;
		cin >> operation;
		switch (operation)
		{
		case 1:
			cout << "Enter a value to be inserted\n";
			cin >> element;
			a.push(element);
			break;

		case 2:
			a.pop();
			break;

		case 3:
			a.peek();
			break;
		case 4:
			a.display();
			break;
		default:
			cout << "Enter a valid input" << endl;
			break;
		}

	} 
	while (operation <= 4 && operation!= 0);

}

int main()
{
	int choice, size_stack;
	cout << "Enter the size of stack\n";
	cin >> size_stack;
	cout << "\n choose the type of stack you want to select" << endl;
	cout << "\n 1.Integer stack";
	cout << "\n 2.Float stack";
	cout << "\n 3.Character stack"<<endl;

	do
	{
		cout << "Enter your choice: \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Stack<int> integer(size_stack);//Integer array
			operation(integer);
			break;
		}

		case 2:
		{
			Stack<float> float_type(size_stack);//Float array
			operation(float_type);
			break;
		}

		case 3:
		{
			Stack <char> character(size_stack);//Character array
			operation(character);
			break;
		}
		default: 
			cout << "Enter a valid input" << endl;
			break;
		}

		cout << "\n 1.Integer stack";
		cout << "\n 2.Float stack";
		cout << "\n 3.Character stack";

	} 
	while (choice != 4);
	getchar();

	return 0;
}
