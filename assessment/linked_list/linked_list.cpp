#include<iostream>
#include<cstdio>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class __list__
{
	struct node *start;
public:
	__list__()
	{
		start = NULL;
	}
	void insert_first(int);
	void delete_spec(int);
	int insert_spec(int position, int element);
	void travel_forward();
	void travel_backward();

	friend void print(struct node *);

	void reverse();
	~__list__();
};
void __list__::insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
int __list__::insert_spec(int position, int element)
{
	int count = 1;
	if (position == 1)
	{
		struct node *temp;
		temp = new node;
		temp->data = element;
		temp->next = start;
		start = temp;
		return 1;
	}
	else
	{
		if (start != NULL)
		{
			struct node *curr;
			curr = start;
			while (curr != NULL && count != position - 1)
			{
				curr = curr->next;
				count++;
			}
			if (curr != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = element;
				temp->next = curr->next;
				curr->next = temp;
				return 1;
			}
			else
			{
				cout << "enter a valid position";
				return 0;
			}
		}
		else
		{
			cout << "list is empty";
			return 0;
		}
	}

}


void __list__::delete_spec(int ele)
{
	struct node *temp, *curr;
	if (start != NULL)
	{
		if (start->data == ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			curr = start;
			while (curr->next != NULL && curr->next->data != ele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "Element not found";
		}
	}
	else
		cout << "List is empty";
}
void __list__::travel_forward()
{
	struct node *curr;
	curr = start;
	cout << "Travel forward ouput\n";
	while (curr != NULL)
	{

		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}
void print(struct node *curr)
{

	if (curr != NULL)
	{
		print(curr->next);

		cout << curr->data << " ";
	}
	cout << endl;
}

void __list__::travel_backward()
{
	cout << "Travel backward output";
	if (start != NULL)
		print(start);
}


void __list__::reverse()
{
	struct node *rev, *temp;
	rev = NULL;
	if (start != NULL)
	{
		if(start->next != NULL)
		{
			while (start != NULL)
			{
				temp = start;
				start = temp->next;
				temp->next = rev;
				rev = temp;
			}
			start = rev;
		}
	}
	cout << "Travel reverse ouput\n";
	while (rev != NULL)
	{

		cout << rev->data << " ";
		rev = rev->next;
	}
	cout << endl;
}

__list__::~__list__()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}

int main()
{
	int operation, first,element,position;
	__list__ l;
	cout << "Choose the operation you want to perform: " << endl;
	cout << "1. Insert elements into list" << endl;
	cout << "2. Insert at nth position in the list" << endl;
	cout << "3. Reverse the elements in the list" << endl;
	cout << "4. print elements in forward direction" << endl;
	cout << "5.print elements in reverse direction" << endl;
	cout << "6.Delete a node with particular value" << endl;
	cin >> operation;
	while (operation <= 6 && operation != 0)
	{
		switch (operation)
		{
		case 1:cout << "Enter the element to insert at first: "<<endl;
			cin >> first;
			l.insert_first(first);
			break;
		case 2: cout << "Enter an element: "<<endl;
			cin >> element;
			cout << " Enter the position"<<endl;
			cin >> position;
			if (!l.insert_spec(position, element))
			{

				break;
			}
			else
				break;
		case 3:l.reverse();
			break;
		case 4: l.travel_forward();
			break;
		case 5: l.travel_backward();
			break;
		case 6: cout << "Enter the element which you want to delete from the list: ";
			cin >> element;
			l.delete_spec(element);
			break;

		default: cout << "Enter a valid input\n";
			break;
		}
		cin >> operation;
	}
	cout << "Enter a valid input\n";
	getchar();
}