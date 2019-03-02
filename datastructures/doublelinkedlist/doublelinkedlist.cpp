#include<iostream>
#include<cstdio>
using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
class doublelist
{
	struct node *start;
public:
	doublelist()
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

	friend void print(struct node *curr);

	void reverse();
	~doublelist();
};
void doublelist::insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->prev = NULL;
	temp->next = start;
	if (start != NULL)
		start->prev = temp;
	start = temp;
}
void doublelist::insert_last(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}

	else
	{
		curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
			
		temp->prev = curr;
		curr->next = temp;
	}
}

void doublelist::insert_after(int sele, int ele)
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
			temp->prev = curr;
			temp->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = temp;
			curr->next = temp;
		}
		else
			cout << "Element not found\n";
	}
	else
		cout << "List is empty\n";
}

void doublelist::insert_before(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr, *temp;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			temp = new node;
			temp->data = ele;
			temp->prev = curr->prev;
			temp->next = curr;
			if (curr->prev != NULL)
				curr->prev->next = temp;
			else
				start = temp;
			curr->prev = temp;
		}
		else
			cout << "Element not found\n";
	}
	else
		cout << "List is empty\n";
}

int doublelist::delete_first()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty\n";
	return x;
}

int doublelist::delete_last()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		x = curr->data;
		if (curr->prev != NULL)
			curr->prev->next = NULL;
		else
			start = NULL;
		delete curr;
	}
	else
		cout << "List is empty\n";
	return x;
}

void doublelist::delete_spec(int ele)
{
	struct node  *curr;
	if (start != NULL)
	{
		curr = start;
		while (curr != NULL && curr->data != ele)
			curr = curr->next;
		if (curr != NULL)
		{
			if (curr->prev != NULL)
				curr->prev->next = curr->next;
			else
				start = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			delete curr;
		}
		else
			cout << "Element not found\n";
	}
	else
		cout << "List is empty\n";
}

void doublelist::travel_forward()
{
	struct node *curr;
	curr = start;
	cout << "Travel forward output is: " << endl;
	while (curr != NULL)
	{
		cout << curr->data<<" ";
		curr = curr->next;
	}
	cout << endl;
}

void doublelist::travel_backward()
{
	struct node *curr=NULL;
	if (start != NULL)
		curr = start;
	while (curr->next != NULL)
		curr = curr->next;
	cout << "Travel backward output is: "<<endl;
	while (curr != NULL)
	{
		cout << curr->data<<" ";
		curr = curr->prev;
	}
	cout << endl;
}

void doublelist::reverse()
{
	struct node *curr;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		cout << "Reverse output is: \n";
		while (curr != NULL)
		{
			cout << curr->data<<" ";
			curr = curr->prev;
		}
	}
}

doublelist::~doublelist()
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
	int operation, first, last, node, element;
	doublelist d;
	cout << "Select the operation that needs to be performed\n";
	cout << "1.Insert first \t 2. Insert last\t 3. Insert after certain node\t";
	cout << "4. Insert before certain node\t";
	cout << "5.Delete first\t 6. Delete last \t7. Delete specific node\t";
	cout << "8. Travel forward \t 9. Travel backward \t 10. reverse\n";
	cin >> operation;
	while (operation <= 10 && operation != 0)
	{
		switch (operation)
		{
		case 1: cout << "Enter the element to insert at first: ";
			cin >> first;
			d.insert_first(first);
			break;
		case 2:cout << "Enter the element to insert at last: ";
			cin >> last;
			d.insert_last(last);
			break;
		case 3:cout << "Enter the node: ";
			cin >> node;
			cout << "Enter the element to insert after: " << node << endl;
			cin >> element;
			d.insert_after(node, element);
			break;
		case 4: cout << "Enter the node: ";
			cin >> node;
			cout << "Enter the element to insert before: " << node << endl;
			cin >> element;
			d.insert_before(node, element);
			break;
		case 5:
			cout << "An element deleted from first is: " << d.delete_first() << endl;
			break;
		case 6:
			cout << "An element deleted from last is : " << d.delete_last() << endl;
			break;
		case 7:
			cout << "Enter the element which you want to delete from the list: ";
			cin >> element;
			d.delete_spec(element);
			break;
		case 8:
			d.travel_forward();
			break;
		case 9:
			d.travel_backward();
			break;
		case 10:
			d.reverse();
			break;
		}
		cin >> operation;

	}
	cout << "Enter a valid input\n";
	getchar();
}