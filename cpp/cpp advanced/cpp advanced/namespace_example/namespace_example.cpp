/*namespace CounterNamespace //if we have multiple namespace with same name, one with variables and one with functions
{
	int LowerBound;
	int UpperBound;
}*/
namespace Counter_Lower_Namespace
{
	int LowerBound;
	namespace Counter_Upper_Namespace
	{
		int UpperBound;
		class counter
		{
			int count;
		public:
			counter(int x)
			{
				count = x;
			}
			int increment_count()
			{
				count++;
				if (count > UpperBound)
					return UpperBound;
				else
					return count;
			}
			int decrement_count()
			{
				count--;
				if (count < LowerBound)
					return LowerBound;
				else
					return count;
			}
		};
	}
}

#include<iostream>
using namespace std;
using namespace Counter_Lower_Namespace;
using Counter_Lower_Namespace::Counter_Upper_Namespace::UpperBound;
void main()
{
	LowerBound = 10;
	UpperBound = 25;
	Counter_Lower_Namespace::Counter_Upper_Namespace::counter c(15);
	for (int i = 0; i < 15; i++)
	{
		cout << "The value of increment count is: " << c.increment_count() << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "The value of count is: " << c.decrement_count() << endl;
	}

}