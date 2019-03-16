/*usage of copy constructor*/

#include <iostream>
#include <cstring>
using namespace std;
class Copy
{
	char* copiedvalue;
public:

	Copy()
	{
		copiedvalue = NULL;
	}
	Copy(char *str)
	{
		copiedvalue = str;
	}
	Copy(const char *str)
	{
		copiedvalue = new char[strlen(str) + 1];
		strcpy_s(copiedvalue, sizeof(str), str);

	}

	void display()
	{
		cout << "The value is: "<<copiedvalue<<endl;
	}
	~Copy()
	{
		delete[] copiedvalue;
	}
};
int main()
{
	Copy c1, c2("Sharanya"), c3(c2);
	c1.display();
	c2.display();
	c3.display();
	return 0;

}