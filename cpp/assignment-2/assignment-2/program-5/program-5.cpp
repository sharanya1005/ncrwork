#include <iostream>
#include <cstring>
using namespace std;
class String
{
public:
	char *sptr;
	int len;
	String()
	{
		sptr = NULL;
		len = 0;
	}
	/*String(const String &s)
	{
		len = s.len;
		strcpy(sptr, s.sptr);
	}*/
	~String()
	{
		if (sptr != NULL)
			free(sptr);
	}
	String(const String&temp)
	{
		len = temp.len;
		sptr = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, temp.sptr);
	}
	String operator=(String temp)
	{
		len = temp.len;
		if (sptr != NULL)
			free;
		sptr = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, temp.sptr);
	}
	friend istream& operator>>(istream& cin, String& s);
	friend ostream& operator<<(ostream& cout, String s);
};
istream& operator>>(istream& cin, String& s)
{
	cin >> s.len;
	s.sptr = new char[s.len + 1];
	for (int i = 0; i < s.len; i++)
	{
		cin >> s.sptr[i];
	}
	return cin;
}
ostream& operator<<(ostream& cout, String s)
{
	cout << "The length of the string is " << s.len << endl;
	cout << "The string is" << s.sptr << endl;
	return cout;
}
int main()
{
	String s1, s4, s3(s4);
	cout << "enter the contents of the string s1" << endl;
	cin >> s1;
	cout << "enter the contents of string s4" << endl;
	cin >> s4;
	cout << s1;
	cout << s3;
	cout << s4;
	return 0;
}