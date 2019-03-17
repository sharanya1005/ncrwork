/* hybrid inheritance using the virtual classes*/

#include <iostream>
using namespace std;
#define MAX_RELIGION 20

class Person
{
protected:
	int age;
	char *name;
public:
	  void get_person_data()
	{
		int size_name;
		cout << "Enter the age of a person: \n";
		cin >> age;
		cout << "Enter the length of the name of a person: \n";
		cin >> size_name;
		name = new char[size_name];
		cout << "Enter the name of a person: \n";
		cin >> name;
		
	}
	 void display_person_data()
	{
		cout << "Age: " << age << endl;
		cout << "Name: " << name << endl;
	}
	 ~Person()
	 {
		 delete[] name;
	 }
};

class Physique :virtual public Person
{
	float height, weight;
public:
	void get_physique_data()
	{
		cout << "Enter the height of the person: \n";
		cin >> height;
		cout << "Enter the weight of the person: \n";
		cin >> weight;
	}
	void display_physique_data()
	{
		cout << "Height: " << height << endl;
		cout << "Weight: " << weight << endl;
	}
};

class Family :virtual public Person
{
	char *religion;
	int numChildren;
public:
	void get_family_data()
	{
		int len_religion;
		cout << "Enter the number of children: \n";
		cin >> numChildren;
		cout << "Enter the length of the name of the religion: " << endl;
		cin >> len_religion;
		religion = new char[len_religion];
		cout << "Enter the religion: \n";
		cin >> religion;
		
	}
	void display_family_data()
	{
		cout << "Religion: " << religion << endl;
		cout << "Number of children: " << numChildren << endl;
	}
	~Family()
	{
		delete[] religion;
	}
};

class Employee :public Physique, public Family
{
	int employeeno, salary;
public:
	void get_employee_data()
	{
		cout << "Enter employee number: \n";
		cin >> employeeno;
		cout << "Enter salary: \n";
		cin >> salary;
	}
	void display_employee_data()
	{
		cout << "Employee number: " << employeeno << endl;
		cout << "Salary: " << salary << endl;
	}
};
int main()
{
	
	Employee emp;
	emp.get_person_data();
	emp.get_physique_data();
	emp.get_family_data();
	emp.get_employee_data();
	cout << "The details of a person are: " << endl;
	emp.display_person_data();
	emp.display_physique_data();
	emp.display_family_data();
	emp.display_employee_data();
	
	return 0;
}