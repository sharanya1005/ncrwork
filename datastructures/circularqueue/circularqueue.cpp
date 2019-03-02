#include<iostream>
using namespace std;
struct _queue_
{
	int rear;
	int size;
	int front;
	int *q;
};
class cirqueue
{
	struct _queue_ que;
public:
	cirqueue();//constructor
	void enqueue(int);//to enter elements in a queue
	void getsize(int);//allocate memory for reqd size
	int dequeue();//to delete elements from the queue
	bool overflow();//to check whether the queue is full or not
	bool underflow();//to check whether the queue is empty or not
	void display();//to display the elements in a queue
	~cirqueue()//destructor
	{
		delete que.q;
	}
};
cirqueue::cirqueue()
{
	que.rear = -1;
	que.front = -1;
	que.size = 0;
}
void cirqueue::getsize(int n)
{
	que.size = n;
	que.q = new int[n];
}
bool cirqueue::overflow()
{
	return(que.front == (que.rear + 1) % que.size);
}
bool cirqueue::underflow()
{
	return(que.front == -1 || que.rear == -1 || (que.front > que.rear));
}
void cirqueue::enqueue(int n)
{
	if (!overflow())
	{
		que.rear = (que.rear + 1) % que.size;
		que.q[que.rear] = n;
		if (que.front == -1)
			que.front = 0;
	}
	else
		cout << "cirular queue is full\n";
}
int cirqueue::dequeue()
{
	int x = -999;
	if (!underflow())
	{
		x = que.q[que.front];
		que.front = (que.front + 1) % que.size;

	}
	else
		cout << "cirular queue is empty\n";
	return x;
}
void cirqueue::display()
{
	int i;
	for (i = que.front; i != que.rear; i = (i + 1) % que.size)
	{
		cout << que.q[i] << endl;
	}
	cout << que.q[i];
}
int main()
{
	cirqueue a;
	int operation, element, n;
	cout << "Enter the number of elements to be in a queue: " << endl;
	cin >> n;
	a.getsize(n);
	cout << "Enter \n1.enqueue \n2.dequeue \n 3.display\n";
	cin >> operation;
	while (operation <= 3 && operation != 0)
	{
		switch (operation)
		{
		case 1:
			cout << "Enter an element to place in a queue: ";
			cin >> element;
			a.enqueue(element);
			cout << endl;
			break;
		case 2:
			cout << "Deleted element from the queue is: " << a.dequeue()<<endl;
			break;
		case 3:
			cout << "Elements in the circular queue are: "<<endl;
			a.display();
			break;
		}
		cin >> operation;
	}
}