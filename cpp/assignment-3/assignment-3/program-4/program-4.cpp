/* demonstrate the different types of access specifiers*/

#include <iostream>
using namespace std;
class First
{
	private://it is fine even if we donot mention private here, coz by default it will be private
		int private_var = 10;
	protected:
		int protected_var;
	public:
		int public_var;

	void get_element()
	{
		cout << "Enter the private element: \n";
		cin >> private_var;
		cout << "Enter the protected element: \n";
		cin >> protected_var;
		cout << "Enter the public element: \n";
		cin >> public_var;
	}

	void display_First()
	{
		cout << "Private variable is: " << private_var << endl;
		cout << "Protected variable is: " << protected_var << endl;
		cout << "Public variable is: " << public_var << endl;
	}
};

class Second :private First
{
public:
	//protected_var and public_var will become the private members of class first and private_var remains private
	void get_seconddata()
	{
		get_element();
	}
	void display_Second()
	{
		display_First();
	}
};
class Third :protected First
{
	//protected_var and public_var will become the protected members of class first
public:
	void get_thirddata()
	{
		get_element();
	}
	void display_Third()
	{
		display_First();
	}
};
class Fourth :public First
{
	//protected_var will become protected and public_var will be public
public:
	void get_fourthdata()
	{
		get_element();
	}
	void display_Fourth()
	{
		display_First();
	}
};
int main()
{
	First fir;
	fir.get_element();
	fir.display_First();
	//fir.private_var = 33; this is inaccessible as it is private
	//fir.protected_var = 44; this is also inaccessible
	fir.public_var = 12;
	fir.display_First();

	Second sd;
	//sd.get_element(); won't work as get_element is inherited in private mode
	sd.get_seconddata();
	sd.display_Second();

	Third th;
	//th.get_element(); protected mode can be accessed only through member functions
	th.get_thirddata();
	th.display_Third();

	Fourth four;
	four.get_fourthdata();
	four.display_Fourth();
	four.public_var = 14;
	four.display_Fourth();
	getchar();
	return 0;
}