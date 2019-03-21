/* create a class named polar and an object which named point which represents polar coordinates and static member is included 
to figure the active number of objects in a class*/

#include<iostream>
using namespace std;
class polar
{
	float angle, radius;
	static int count;
public:
	polar()//default constructor
	{
		angle = 0;
		radius = 0;
		count++;
	}
	polar(float a, float b)//parameter passing
	{
		angle = a;
		radius = b;
		count++;
	}
	polar(polar &s)//copy constructor
	{
		angle = s.angle;
		radius = s.radius;
		count++;
	}
	void display()//display function
	{
		cout << "No. of active objects in a class are: " << count;
	}

};
int polar::count;
void main()
{
	polar p1, p2(20, 5), p3(p2);
	p1.display();
}