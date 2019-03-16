/* Creating a class named student and it has got few paramters like studentname, grade and marks of three subjects, 
it takes inputs and then calculates the average of the marks entered and based on the average assigns a grade and will display the 
entire details of a student */


#include<iostream>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class student
{
public:
	char *studentname;
	int sub1, sub2, sub3;
	float average;
};
class collegecourse
{

	student s1;
	int len;
	const char *grade;
	float average;
public:
	void set_data(const char *sname, int m1, int m2, int m3)//function which takes values to the object created
	{
		len = strlen(sname);
		s1.studentname = (char *)malloc((len + 1) * sizeof(char));
		strcpy(s1.studentname, sname);
		s1.sub1 = m1;
		s1.sub2 = m2;
		s1.sub3 = m3;
	}
	void cal_average()//function calculating average
	{
		average = (float)((s1.sub1 + s1.sub2 + s1.sub3) / 3);
	}
	void compute_grade()//function assigning grade based on the above calculated average
	{
		if (average > 60)
			grade = "First class";
		else
			if (average > 50 && average < 60)
				grade = "Second class";
			else
				if (average < 50 && average>40)
					grade = "Third class";
				else
					grade = "Fail";
	}
	void display()//function to display all the properties of a student
	{
		cout << "studentname: " << s1.studentname << endl;
		cout << "subject1: " << s1.sub1 << endl;
		cout << "subject2: " << s1.sub2 << endl;
		cout << "subject3: " << s1.sub3 << endl;
		cout << "average: " << average << endl;
		cout << "grade: " << grade << endl;
	}

};
int main()
{
	collegecourse c1;
	c1.set_data("sharanya", 80, 90, 100);
	c1.cal_average();
	c1.compute_grade();
	c1.display();
	return 0;
}