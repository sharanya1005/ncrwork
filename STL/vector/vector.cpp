#include<iostream>
#include<vector>
using namespace std;
void show(vector<int>v)
{
	vector<int>::iterator it;
	cout << "vector elements" << endl;
	it = v.begin();
	while (it != v.end())
	{
		cout << *it++ << endl;
	}
}
int main()
{
	int position,element;
	vector<int>v;
	vector<int>::iterator it;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	cout << "Vector size is: " << v.size() << endl;
	show(v);
	cout << "Enter the position where u want to insert element: " << endl;
	cin >> position;
	cout << "Enter the element you want to insert: " << endl;
	cin >> element;
	it = v.begin();
	it = it + position;
	v.insert(it, element);
	show(v);
	cout << "Enter the element you want to delete from the vector: " << endl;
	cin >> position;
	it = v.begin();
	it = it + position;
	v.erase(it);
	show(v);
	return 0;


}


/* array notation of a vector
vector<int>v(5);
vector<int>::iterator it;
cout << "Size of vector is: " << v.size() << endl;
for (int i = 0; i < v.size(); i++)
v[i] = i;
cout << "Vector content " <<endl;
for (int i = 0; i < v.size(); i++)
cout << v[i] << endl;
*/

/* for iterator notation of a vector
int i = 0;
it = v.begin();
while (it != v.end())
{
*it++ = i++;
}
it = v.begin();
while (it != v.end())
{
cout << *it++ << endl;
}
*/


	
	
