#include<iostream>
#include<map>
using namespace std;
int main()
{
	//map<int, int>m;
	//map<int, int>::iterator it;

	multimap<int, int>m;
	multimap<int, int>::iterator it;

	m.insert(pair<int, int>(1, 2));
	m.insert(pair<int, int>(10, 20));
	m.insert(pair<int, int>(100, 200));
	m.insert(pair<int, int>(12, 21));
	m.insert(pair<int, int>(1, 2));
	m.insert(pair<int, int>(12, 21));
	it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		it++;
	}
	return 0;
}