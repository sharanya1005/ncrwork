#include<iostream>
using namespace std;
struct _queue_
{
	int rear;
	int size;
	int front;
	int *q;
};
class queue
{
	struct _queue_ que;
public:
	queue();//constructor
	void enqueue(int);//enter elements in a queue
	void getsize(int);//allocating memory
	int dequeue();//remove elemets from a queue
	bool overflow();//to know whether the queue is full or not
	bool underflow();//to know whether the queue is empty or not
	void display();//to display elements in a queue
	~queue()//destructor
	{
		delete que.q;
	}
};
queue::queue()
{
	que.rear = -1;
	que.front = -1;
	que.size = 0;
}
void queue::getsize(int n)
{
	que.size = n;
	que.q = new int[n];
}
bool queue::overflow()
{
	return(que.rear == (que.size - 1));
}
bool queue::underflow()
{
	return(que.front == -1 || que.rear == -1 || (que.front > que.rear));
}
void queue::enqueue(int n)
{
	if (!overflow())
	{
		que.q[++que.rear] = n;
		if (que.front == -1)
			que.front = 0;
	}
	else
		cout << "queue is full\n";
}
int queue::dequeue()
{
	int n = -99;
	if (!underflow())
	{
		n = que.q[que.front];
		que.front++;

	}
	else
		cout << "queue is empty\n";
	return n;
}
void queue::display()
{
	
	for (int i = que.front; i <= que.rear; i++)
	{
		
		cout << que.q[i] << endl;
	}
}
int main()
{
	queue a;
	int ch, k, n;
	cout << "Enter no of elements: ";
	cin >> n;
	a.getsize(n);
	cout << endl;
	cout << "Select the operation   1.enqueue  2.dequeue  3.display";
	cin >> ch;
	cout << endl;
	while (ch <= 3 && ch != 0)
	{
		switch (ch)
		{
		case 1:
			cout << "enter an element to place in a queue: ";
			cin >> k;
			a.enqueue(k);
			cout << endl;
			break;
		case 2:
			cout << "Deleted element is:  " << a.dequeue()<<endl;
			break;
		case 3:
			cout << "Elements in the queue are: "<<endl;
			a.display();
			break;
		}
		cin >> ch;
	}
}