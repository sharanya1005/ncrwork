#include<iostream>
using namespace std;
class Person
{
public:
	char *name;
	int age;

	void get_person_data()
	{
		int lengthofname;
		cout << "Enter the age of a person: "<<endl;
		cin >> age;
		cout << "Enter the length of the name of a person: " << endl;
		cin >> lengthofname;
		name = new char[lengthofname];
		cout << "Enter the name: " << endl;
		cin >> name;
	}
	void display_person_data()
	{
		cout << "Name of a person is: " << name << endl;
		cout << "Age of a person is: " << age << endl;
	}
	~Person()
	{
		delete[] name;
	}
};

class Person_Address : virtual public Person
{
	int street_no;
	char *location;
public:
	void get_address_data()
	{
		int lengthoflocation_name;
		cout << "Enter the street number: " << endl;
		cin >> street_no;
		cout << "Enter the length of the name of a location: " << endl;
		cin >> lengthoflocation_name;
		location = new char[lengthoflocation_name];
		cout << "Enter the location: " << endl;
		cin >> location;
	}
	void display_address_data()
	{
		cout << "ADDRESS:" << endl;
		cout << "Street No: " << street_no << endl;
		cout << "Location: " << location << endl;
	}
	~Person_Address()
	{
		delete[] location;
	}
};

class Person_Qualification : virtual public Person
{
	int SSC_marks, Inter_marks;
	char *School_name, *College_name;
public:
	void get_qualification_data()
	{
		int lengthofschool_name, lengthofcollege_name;
		cout << "Enter the length of the school name: " << endl;
		cin >> lengthofschool_name;
		School_name = new char[lengthofschool_name];
		cout << "Enter the school name: " << endl;
		cin >> School_name;
		cout << "Enter SSC Marks: " << endl;
		cin >> SSC_marks;
		cout << "Enter the length of the college name: " << endl;
		cin >> lengthofcollege_name;
		College_name = new char[lengthofcollege_name];
		cout << "Enter the college name: " << endl;
		cin >> College_name;
		cout << "Enter Inter marks: " << endl;
		cin >> Inter_marks;
	}
	void display_qualification_data()
	{
		cout << "Qualification Details are: " << endl;
		cout << "School name is: " << School_name << endl;
		cout << "SSC Marks: " << SSC_marks << endl;
		cout << "Inter college name is: " << College_name << endl;
		cout << "Inter marks scored: " << Inter_marks << endl;
	}
	~Person_Qualification()
	{
		delete[] School_name;
		delete[] College_name;
	}
	
};
class Personal_Details:public Person_Address,public Person_Qualification
{
	float height, weight;
public: 
	void get_data()
	{
		cout << "Enter the height of a person: " << endl;
		cin >> height;
		cout << "Enter the weight of a person: " << endl;
		cin >> weight;
	}
	void display_data()
	{
		cout << "Height of the person is: " << height << endl;
		cout << "Weight of the person is: " << weight << endl;
	}
};
int main()
{
	Personal_Details per_de;
	per_de.get_person_data();
	per_de.get_address_data();
	per_de.get_qualification_data();
	per_de.get_data();
	cout << "All the details of a person are: " << endl;
	per_de.display_person_data();
	per_de.display_address_data();
	per_de.display_qualification_data();
	per_de.display_data();
	return 0;
}