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
	void insert_last(int);
	void insert_after(int, int);
	void insert_before(int, int);

	int delete_first();
	int delete_last();
	void delete_spec(int);

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
void __list__::insert_last(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}
void __list__::insert_after(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "Element not found";
	}
	else
		cout << "List is empty";
}
void __list__::insert_before(int sele, int ele)
{
	if (start != NULL)
	{
		if (start->data == sele)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next != NULL && curr->next->data != sele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = ele;
				temp->next = curr->next;
				curr->next = temp;
			}
			else
				cout << "Element not found";
		}
	}
	else
		cout << "List is empty";
}
int __list__::delete_first()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty";
	return x;
}
int __list__::delete_last()
{
	int x = -999;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	else
		cout << "List is empty";
	return x;
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
		
		cout << curr->data<<" ";
	}
	cout <<endl;
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
		if (start->next != NULL)
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
	int operation,first,last,node,element;
	__list__ l;
	cout << "Select the operation that needs to be performed\n";
	cout << "1.Insert first \t 2. Insert last\t 3. Insert after certain node\t";
	cout<< "4. Insert before certain node\t";
	cout << "5.Delete first\t 6. Delete last \t7. Delete specific node\t";
	cout << "8. Travel forward \t 9. Travel backward \t 10. reverse\n";
	cin >> operation;
	while (operation <= 10 && operation != 0)
	{
		switch (operation)
		{
		case 1: cout << "Enter the element to insert at first: ";
			cin >> first;
			l.insert_first(first);
			break;
		case 2:cout << "Enter the element to insert at last: " ;
			cin >> last;
			l.insert_last(last);
			break;
		case 3:cout << "Enter the node: ";
			cin >> node;
			cout << "Enter the element to insert after: " << node<<endl;
			cin >> element;
			l.insert_after(node, element);
			break;
		case 4: cout << "Enter the node: ";
			cin >> node;
			cout << "Enter the element to insert before: " << node<<endl;
			cin >> element;
			l.insert_before(node, element);
			break;
		case 5:
			cout << "An element deleted from first is: "<< l.delete_first()<<endl;
			break;
		case 6:
			cout << "An element deleted from last is : "<< l.delete_last()<<endl;
			break;
		case 7:
			cout << "Enter the element which you want to delete from the list: ";
			cin >> element;
			l.delete_spec(element);
			break;
		case 8:
			l.travel_forward();
			break;
		case 9:
			l.travel_backward();
			break;
		case 10:
			l.reverse();
			break;
		default: cout << "Enter a valid input\n";
			break;
		}
		cin >> operation;
	}

	getchar();
}