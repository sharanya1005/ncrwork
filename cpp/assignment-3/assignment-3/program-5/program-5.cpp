#include <iostream>
using namespace std;
#define MAX_RELIGION 20
#define MAX_NAME 40
class Person
{
	int age;
	char *name;
public:
	virtual void get_data()
	{
		int size_name;
		cout << "enter the age\n";
		cin >> age;
		name = new char[MAX_NAME];
		cout << "enter the name\n";
		cin >> name;
	}
	virtual void display()
	{
		cout << "Age=" << age << endl;
		cout << "Name=" << name << endl;
	}
};
class Physique :public Person
{
	float height, weight;
public:
	void get_data()
	{
		cout << "enter the height of the person\n";
		cin >> height;
		cout << "enter the weight of the person\n";
		cin >> weight;
	}
	void display()
	{
		cout << "Height=" << height << endl;
		cout << "Weight=" << weight << endl;
	}
};
class Family :public Person
{
	char *religion;
	int numChildren;
public:
	void get_data()
	{
		cout << "enter the number of children\n";
		cin >> numChildren;
		religion = new char[MAX_RELIGION];
		cout << "enter the religion\n";
		cin >> religion;
	}
	void display()
	{
		cout << "Religion=" << religion << endl;
		cout << "Number of children" << numChildren << endl;
	}
};
class Employee :public Physique, Family
{
	int employeeno, salary;
public:
	void get_data()
	{
		cout << "enter employee number\n";
		cin >> employeeno;
		cout << "enter salary\n";
		cin >> salary;
	}
	void display()
	{
		cout << "Employee number=" << employeeno << endl;
		cout << "Salary=" << salary << endl;
	}
};
int main()
{
	Person per;
	per.get_data();
	per.display();
	Physique phy;
	phy.get_data();
	phy.display();
	Family fml;
	fml.get_data();
	fml.display();
	Employee emp;
	emp.get_data();
	emp.display();
	return 0;
}