#include<iostream>
using namespace std;
#include<string>
#define LEN 30
class String_st
{
	char *name;
	int length;

public:

	String_st()//default constructor
	{
		name = NULL;
		length = 0;
	}

	String_st(const char *inp)//paramterized constructor
	{
		name = new char[strlen(inp) + 1];
		strcpy(name, inp);
		length = strlen(inp);
	}

	String_st(const String_st &inp)//copy constructor
	{

		name = new char[inp.length + 1];
		strcpy(name, inp.name);
		length = inp.length;
	}

	void print_String_st()
	{

		cout << name << endl;
	}

	void scan_String_st()
	{
		name = new char[10];
		cin >> name;
	}

	~String_st()//destructor
	{
		if (name != NULL)
			delete[]name;
	}

	String_st operator=(String_st temp)//overloading = operator
	{

		length = temp.length;
		if (name != NULL)
			free(name);
		name = (char*)malloc(sizeof(char)*(length + 1));
		strcpy(name, temp.name);
		return (*this);
	}

	String_st operator+(String_st &inp)//overloading + operator
	{

		String_st temp;
		temp.length = length + inp.length;
		temp.name = new char[temp.length + 1];
		strcpy(temp.name, name);
		strcat(temp.name, inp.name);
		return temp;
	}

	friend ostream& operator<<(ostream &cout, const String_st &inp);
	friend istream& operator>>(istream &cin, String_st &inp);
	friend void sort(String_st s[], int);
};

void sort(String_st s[10], int n)  	// Sorting strings using bubble sort 
{
	char temp[LEN];
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = j + 1; i < n; i++)
		{
			if (strcmp(s[j].name, s[i].name) > 0)
			{
				strcpy(temp, s[j].name);
				strcpy(s[j].name, s[i].name);
				strcpy(s[i].name, temp);
			}
		}
	}
}


ostream& operator<<(ostream &cout, const String_st &inp)//overloading << operator
{
	cout << inp.name;
	return cout;
}

istream& operator>>(istream &cin, String_st &inp)//overloading >> operator
{
	char buffer[100];
	cin >> buffer;
	inp.name = new char[strlen(buffer) + 1];
	inp.length = strlen(buffer);
	strcpy(inp.name, buffer);
	//cin>>inp.sptr;
	return cin;
}

int main()
{
	//char a[10];
	String_st str1, str2("Hello"), str3(str2), str4, str5;
	cout << "Enter the string: " << endl;
	str1.scan_String_st();
	cout << "Entered string is: " << endl;
	cout << str1;
	cout << "\nparameterized constructor string is: " << endl;
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

	int itr1;

	String_st sample[10];
	int number;
	cout << "Enter no of Strings to be sorted:";
	cin >> number;

	for (itr1 = 0; itr1 < number; itr1++)
	{
		cout << "Enter string" << itr1 << ":";
		sample[itr1].scan_String_st();
	}
	sort(sample, number);
	for (itr1 = 0; itr1 < number; itr1++)
	{
		sample[itr1].print_String_st();
		cout << endl;
	}
	return 0;
}
