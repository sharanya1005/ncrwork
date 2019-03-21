/* creating a class named student which has few data members and overloading the insertion and extraction operator */

#include<iostream>
using namespace std;
class student
{
	int rollno;
	char name[30];
	int sub1, sub2, sub3, sub4;
	int total;
	float average;
	char grade;
public:
	void cal_avg()//function calculating average and assigning grade based on obtained average
	{
		total = sub1 + sub2 + sub3 + sub4;
		average = (float)(total / 4);
		if (sub1 > 40 && sub2 > 40 && sub3 > 40 && sub4 > 40 && average > 60)
			grade = 'A';
		else
			if (sub1 > 40 && sub2 > 40 && sub3 > 40 && sub4 > 40 && average < 60 && average>50)
				grade = 'B';
			else
				if (sub1 > 40 && sub2 > 40 && sub3 > 40 && sub4 > 40 && average < 50 && average >40)
					grade = 'C';
				else
					grade = 'F';
	}
	friend istream& operator >> (istream& cin, student &s1);
	friend ostream& operator << (ostream& cout, student s1);
};
istream& operator >> (istream& cin, student &s1)
{
	cin >> s1.rollno;
	cin >> s1.name;
	cin >> s1.sub1 >> s1.sub2 >> s1.sub3 >> s1.sub4;
	s1.cal_avg();
	return (cin);
}
ostream& operator << (ostream& cout, student s1)
{
	cout << "student name: " << s1.name << endl;
	cout << "roll no: " << s1.rollno << endl;
	cout << "sub1: " << s1.sub1 << endl;
	cout << "sub2: " << s1.sub2<<endl;
	cout << "sub3: " << s1.sub3<<endl;
	cout << "sub4: " << s1.sub4<<endl;
	cout << "Total: " << s1.total<<endl;
	cout << "Average: " << s1.average<<endl;
	cout << "Grade: " << s1.grade<<endl;
	return  (cout);
}
int main()
{
	student s1;
	cout << "Enter the details of a student: " << endl;
	cin >> s1;
	cout << s1;
	return 0;
}