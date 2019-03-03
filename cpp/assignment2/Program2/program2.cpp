#include<iostream>
using namespace std;
class student
{
	int rollno;
	char *name;
	int sub1, sub2, sub3, sub4;
	int total;
	float average;
	char grade;
public:
	void cal_avg()
	{
		total = sub1 + sub2 + sub3 + sub4;
		average = (float)(total / 4);
		if (average > 60)
			grade = 'A';
		else
			if (average < 60 && average>50)
				grade = 'B';
			else
				if (average < 50 && average >40)
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
	cout << "sub1: " << s1.sub1;
	cout << "sub2: " << s1.sub2;
	cout << "sub3: " << s1.sub3;
	cout << "sub4: " << s1.sub4;
	cout << "Total: " << s1.total;
	cout << "Average: " << s1.average;
	cout << "Grade: " << s1.grade;
	return  (cout);
}
int main()
{
	student s1;
	cin >> s1;
	cout << s1;
	return 0;
}