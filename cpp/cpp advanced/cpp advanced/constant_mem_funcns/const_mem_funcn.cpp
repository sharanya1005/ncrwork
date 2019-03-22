#include<iostream>
using namespace std;
class Myclass
{
	mutable int x;
	int y;
public:
	Myclass(int a, int b)
	{
		x = a;
		y = b;
	}
	int getx() const
	{
		return x;
	}
	int setx(int a) const
	{
		x = a;
		return x;
	}
};
int main()
{
	Myclass obj(10, 20);
	cout << "The value of x is: " << obj.getx() << endl;
	double res = obj.setx(15);
	cout << "The value of x after modification is: " <<res  << endl;
}