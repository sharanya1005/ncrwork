#include<iostream>
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
	void insert_after(int , int);
	void insert_before(int ,int);

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
	while (curr != NULL)
	{
		cout << curr->data<<" ";
		curr = curr->next;
	}
	cout << endl;
}

void __list__::travel_backward()
{
	struct node *start;
	if (start != NULL)
		print(start);
}
void print(struct node *curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << curr->data;
	}
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

void main()
{
	__list__ l;
	l.insert_first(10);
	l.insert_first(22);
	l.insert_first(44);
	l.insert_first(76);
	l.delete_spec(22);
	l.insert_last(4);
	l.delete_first();
	l.insert_before(10, 82);
	l.delete_last();
	l.insert_after(44, 98);
	l.travel_forward();
	l.travel_backward();
	l.reverse();
	l.travel_forward();
}