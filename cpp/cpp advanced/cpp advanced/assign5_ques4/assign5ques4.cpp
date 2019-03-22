#include<iostream>
using namespace std;
class Myclass1
{
	const int num_A;
	const int num_B;
public:
	
	Myclass1(int x , int y) :num_A(x), num_B(y)
	{
		cout << "Value of number A is: " << num_A << endl;
		cout << "Value of number B is: " << num_B << endl;
	}
	
};
class Myclass2
{
public:
	Myclass1 class1;
	Myclass2(int x, int y) :class1(x, y)
	{

	}
};
int main()
{
	Myclass2 obj(5, 10);
	return 0;
}