#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class COPY
{
	char* ELEMENT;
public:

	COPY()
	{
		ELEMENT = NULL;
	}
	COPY(char *s)
	{
		ELEMENT = s;
	}
	COPY(const char *str)
	{
		ELEMENT = new char[strlen(str) + 1];
		strcpy( ELEMENT, str);

	}

	void display()
	{
		cout << "Output is: "<< ELEMENT;
	}
	~COPY()
	{
		delete[] ELEMENT;
	}
};
int main()
{
	COPY c1, c2("sharanya"), c3(c2);

	c2.display();
	c3.display();
	return 0;

}