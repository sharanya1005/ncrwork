#include<iostream>
using namespace std;
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
class String_st
{
	char *sptr;
	int length;

public:

	String_st()//default constructor
	{
		sptr = NULL;
		length = 0;
	}

	String_st(const char *inp)//paramterized constructor
	{
		sptr = new char[strlen(inp) + 1];
		strcpy_s(sptr,sizeof(inp), inp);
		length = strlen(inp);
	}

	String_st(const String_st &inp)//copy constructor
	{

		sptr = new char[inp.length + 1];
		strcpy_s(sptr, sizeof(inp.sptr), inp.sptr);
		length = inp.length;
	}

	void print_String_st()
	{
		cout << "The string is: " << endl;
		cout << sptr << endl;
	}

	void scan_String_st()
	{
		sptr = new char[10];
		cin >> sptr;
	}

	~String_st()//destructor
	{
		if (sptr != NULL)
		delete[]sptr;
	}

	String_st operator=(String_st inp)//overloading = operator
	{
		delete[] sptr;
		sptr = new char[strlen(inp.sptr) + 1];
		strcpy_s(sptr, sizeof(inp.sptr), inp.sptr);
		length = inp.length;
		return (*this);
	}

	String_st operator+(String_st &inp)//overloading + operator
	{

		String_st temp;
		temp.length = length + inp.length;
		temp.sptr = new char[temp.length + 1];
		strcpy_s(temp.sptr, sizeof(sptr), sptr);
		strcat_s(temp.sptr, sizeof(inp.sptr), inp.sptr);
		return temp;
	}
	char  operator[](int index)
	{
		if (index >= length)
		cout << "\n invalid arguments";
		return (sptr[index]);
	}
	friend ostream& operator<<(ostream &cout, const String_st &inp);
	friend istream& operator>>(istream &cin, String_st &inp);
};


ostream& operator<<(ostream &cout, const String_st &inp)//overloading << operator
{
	cout << inp.sptr;
	return cout;
}

istream& operator>>(istream &cin, String_st &inp)//overloading >> operator
{
	char buffer[100];
	cin >> buffer;
	inp.sptr = new char[strlen(buffer) + 1];
	inp.length = strlen(buffer);
	strcpy_s(inp.sptr, sizeof(buffer), buffer);
	//cin>>inp.sptr;
	return cin;
}

int main()
{
	String_st str1, str2("Hello"), str3(str2), str4, str5;
	cout << "Enter the string: "<<endl;
	str1.scan_String_st();
	cout << "Entered string is: " << endl;
	cout << str1;
	cout << "parameterized constructor string is: " << endl;
	str2.print_String_st();
	cout << "Copy constructor string is: " << endl;
	str3.print_String_st();
	str4 = str1;  //deep copying
	cout << "Deep copied string: " << endl;
	str4.print_String_st();
	str5 = str3 + str4;
	cout << "After concatenating copy and deep string: " << endl;
	str5.print_String_st();
	cout << str5 << endl;
	return 0;
}
