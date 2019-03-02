#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class _stack_
{
	struct node *top;
public:
	_stack_();
	void push(int);
	int pop();
	void display();
	~_stack_();
};
_stack_::_stack_()
{
	top = NULL;
}

void _stack_::push(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = top;
	top = temp;
}
int _stack_::pop()
{
	int x = -999;
	if(top!=NULL)
	{
		struct node *temp;
		temp = top;
		top = top->next;
		x = temp->data;
		delete temp;
	}


	else
		cout << "List is Empty\n";
	return x;
}

void _stack_::display()
{
	struct node *curr;
	curr = top;
	cout << "Elements in the stack are: " << endl;
	while (curr != NULL)
	{
		cout << curr->data<<" ";
		curr = curr->next;

	}
	
}
_stack_::~_stack_()
{
	struct node *temp;
	while (top != NULL)
	{
		temp = top;
		top = temp->next;
		delete temp;
	}
}
void main()
{
	int operation, n;
	_stack_ s1;
	
	cout << "Select an operation that needs to be performed. 1. push  2. pop  3. display \n";
	cin >> operation;
	while (operation <= 3 && operation != 0)
	{
		switch (operation)
		{
		case 1:
			cout << "Enter the element to push: ";
			cin >> n;
			s1.push(n);
			break;
		case 2:
			cout << "An element is popped out: " <<s1.pop()<<endl;;
			break;
		case 3:
			s1.display();
			break;
		}
		cin >> operation;
	}
	getchar();
}