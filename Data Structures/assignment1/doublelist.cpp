#include<iostream>
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
			curr = curr->next;
		temp->prev = curr;
		curr->next = temp;
	}
}

void doublelist::insert_after(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr,*temp;
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
			cout << "Element not found"<<endl;
	}
	else
		cout << "List is empty"<<endl;
}

void doublelist::insert_before(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr, *temp;
		curr = start;
			while (curr!= NULL && curr->data != sele)
				curr = curr->next;
			if (curr!= NULL)
			{
				temp = new node;
				temp->data = ele;
				temp->prev = curr->prev;
				temp->next = curr;
				if (curr->prev != NULL)
					curr->prev->next = temp;
				else
				{
					start = temp;
					curr->prev = temp;
				}
			}
			else
				cout << "Element not found";
		}
	else
		cout << "List is empty";
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
		cout << "List is empty";
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
		cout << "List is empty";
	return x;
}

void doublelist::delete_spec(int ele)
{
	struct node  *curr;
	if (start != NULL)
	{
			curr = start;
			while (curr!= NULL && curr->data != ele)
				curr = curr->next;
			if (curr!= NULL)
			{
				if (curr->prev != NULL)
					curr->next->prev = curr->prev;
				else
					start = curr->next;
				if (curr->next != NULL)
					curr->next->prev = curr->prev;
				delete curr;
			}
			else
				cout << "Element not found";
	}
	else
		cout << "List is empty";
}

void doublelist::travel_forward()
{
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

void doublelist::travel_backward()
{
	struct node *curr;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		while (curr != NULL)
		{
			cout << curr->data;
			curr = curr->prev;
		}
	}
	cout << endl;
}

/*void doublelist::reverse()
{
	struct node *curr;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		while (curr != NULL)
		{
			cout << curr->data;
			curr = curr->prev;
		}
	}
}*/

doublelist::~doublelist()
{
	struct node *temp;
		temp = start;
		start = temp->next;
		delete temp;
}

void main()
{
	doublelist ll;
	ll.insert_first(20);
	ll.insert_last(40);
	ll.insert_last(50);
	ll.insert_after(50, 60);
	ll.insert_before(20, 70);
	ll.travel_forward();
	ll.travel_backward();
	ll.delete_first();
	ll.delete_last();
	ll.delete_spec(20);
	ll.travel_forward();
	ll.travel_backward();
}