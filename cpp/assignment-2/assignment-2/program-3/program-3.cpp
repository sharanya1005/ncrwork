#include <iostream>
#include<string>
using namespace std;
class employee
{
public:
	int employeeno;
	char name[30];
	float salary;
	void display()
	{
		cout << "The details of the employee are: " << endl;
		cout << "Employee no =" << employeeno << endl;
		cout << "Name =" << name << endl;
		cout << "Salary =" << salary << endl;
	}
	friend istream& operator >>(istream& cin, employee& e);
};
istream& operator >> (istream& cin, employee& e)
{
	cin >> e.employeeno;
	cin >> e.name;
	cin >> e.salary;
	return cin;
}
int main()
{
	employee emp[5];
	for (int i = 1; i <= 5; i++)
	{
		cout << "enter the values of  " << i << " th object " << endl;
		cin >> emp[i];
	}
	for (int i = 1; i <= 5; i++)
	{
		emp[i].display();
	}
	cout << endl;
}