#include<iostream>
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
	char *grade;
	float average;
public:
	void set_data(const char *sname, int m1, int m2, int m3)
	{
		len = strlen(sname);
		s1.studentname = (char *)malloc((len + 1) * sizeof(char));
		strcpy(s1.studentname, sname);
		s1.sub1 = m1;
		s1.sub2 = m2;
		s1.sub3 = m3;
	}
	void cal_average()
	{
		average = (s1.sub1 + s1.sub2 + s1.sub3) / 3;
	}
	void compute_grade()
	{
		if (average > 60)
			grade = "firstclass";
		else
			if (average > 50 && average < 60)
				grade = "secondclass";
			else
				if (average < 50 && average>40)
					grade = "thirdclass";
				else
					grade = "fail";
	}
	void display()
	{
		cout<<"studentname: "<<s1.studentname<<endl;
		cout<< "subject1: "<<s1.sub1 <<endl;
		cout<< "subject2: "<<s1.sub2 << endl;
		cout<< "subject3: "<<s1.sub3 << endl;
		cout << "average: "<<average << endl;
		cout << "grade: "<<grade << endl;
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