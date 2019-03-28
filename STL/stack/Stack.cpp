#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int>s;
	cout << "size of stack: " << s.size() << endl;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << "Top of the stack: " << s.top() << endl;
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}