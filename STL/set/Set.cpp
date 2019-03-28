#include<iostream>
#include<set>
using namespace std;
int main()
{
	//set<int>s;
	//set<int>::iterator it;

	multiset<int>s;
	multiset<int>::iterator it;

	s.insert(10);
	s.insert(20);
	s.insert(90);
	s.insert(40);
	s.insert(70);
	s.insert(10);
		s.insert(90);
	it = s.begin();
	while (it != s.end())
	{
		cout << *it++ << endl;
	}
	return 0;
}