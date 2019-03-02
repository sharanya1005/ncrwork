#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class QueuefromLL
{
	struct node *rear;
public:
	QueuefromLL();
	void Enqueue(int);
	int Dequeue();
	void display();
	~QueuefromLL();
};
QueuefromLL::QueuefromLL()
{
	rear = NULL;
}
void QueuefromLL::Enqueue(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (rear == NULL)
	{
		rear = temp;
	}
	else
	{
		curr = rear;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}
int QueuefromLL::Dequeue()
{
	int x = -999;
	if (rear != NULL)
	{
		struct node *temp;
		temp = rear;
		rear = rear->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty\n";
	return x;
}
void QueuefromLL::display()
{
	struct node *curr;
	curr = rear;
	cout << "Elements in the queue are: " << endl;
	while (curr != NULL)
	{
		cout << curr->data<<" ";
		curr = curr->next;
	}
	cout << endl;
}

QueuefromLL::~QueuefromLL()
{
	struct node *temp;
	while (rear != NULL)
	{
		temp = rear;
		rear = temp->next;
		delete temp;
	}
}
int main()
{
	QueuefromLL q;
	int ele, ch, k;
	cout << "Enter an operation to perform  1.Enqueue   2.Dequeue   3.Display\n";
	cin >> ch;
	while (ch <= 3 && ch != 0)
	{
		switch (ch)
		{
		case 1: cout << "Enter an element to insert: "<<endl;
			cin >> ele;
			q.Enqueue(ele);
			break;
		case 2: k = q.Dequeue();
			cout << "Deleted element is:" << k<<endl;
			break;
		case 3:q.display();
			break;
		}
		cout << "Enter an operation to be performed:";
		cin >> ch;
	}
	return 0;
}