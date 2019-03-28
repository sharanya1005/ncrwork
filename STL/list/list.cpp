#include<iostream>
#include<list>
using namespace std;
void show(list<int>l)
{
	list<int>::iterator it;
	cout << "List elements" << endl;
	it = l.begin();
	while (it != l.end())
	{
		cout << *it++ << endl;
	}
}
int main()
{
	list<int>l;
	l.push_front(10);
	l.push_front(90);
	show(l);
	l.push_back(50);
	l.push_back(70);
	show(l);
	l.pop_front();
	l.pop_back();
	show(l);
	l.sort();
	show(l);
	list<int>l2;
	l2.push_back(100);
	l2.push_back(200);
	show(l2);
	l.merge(l2);
	show(l);
	show(l2);//here list will be empty
	l.reverse();
	show(l);
	return 0;
}