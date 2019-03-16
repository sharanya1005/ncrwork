#include <iostream>
using namespace std;
class First
{
	int priv_a = 10;
protected:
	int prot_a;
public:
	int pub_a;
	void get_elem()
	{
		cout << "enter the protected element\n";
		cin >> prot_a;
		cout << "enter the public element\n";
		cin >> pub_a;
	}
	void display_First()
	{
		//cout << "private variable" << priv_a << endl;
		cout << "protected variable" << prot_a << endl;
		cout << "public variable" << pub_a << endl;
	}
};
class Second :private First
{
public:
	void get_sdata()
	{
		get_elem();
	}
	void display_Second()
	{
		display_First();
	}
};
class Third :protected First
{
public:
	void get_tdata()
	{
		get_elem();
	}
	void display_Third()
	{
		display_First();
	}
};
class Fourth :public First
{
public:
	void get_fdata()
	{
		get_elem();
	}
	void display_Fourth()
	{
		display_First();
	}
};
int main()
{
	First fr;
	fr.get_elem();
	fr.display_First();
	fr.pub_a = 12;
	fr.display_First();
	Second sd;
	//sd.get_elem(); won't owrk as get_elem is inherited in private mode
	sd.get_sdata();
	sd.display_Second();
	Third th;
	//th.get_elem(); protected mode can be accessed only through member functions
	th.get_tdata();
	th.display_Third();
	Fourth four;
	four.get_fdata();
	four.display_Fourth();
	four.pub_a = 14;
	four.display_Fourth();
	cout << "waiting to enter a key to exit program" << endl;
	getchar();
	return 0;
}