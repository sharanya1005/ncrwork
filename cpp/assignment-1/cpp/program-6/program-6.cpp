/* creating a class named point which represents cartesian coordinates and finding the distance between the 
two entered points */

#include<iostream>
#include<cmath>
using namespace std;
class point;
class point
{
	int x;
	int y;
public:
	void input()//function taking the cartesian coordinates
	{
		cout << "Enter the cartesian coordinates: ";
		cin >> x >> y;
		cout << endl;
	}

	friend float distance(point, point);
};
float distance(point a, point b)//function which calculates distance
{
	float d;
	d = sqrt((pow((b.x - a.x), 2)) + (pow((b.y - a.y), 2)));//formula to calculate distance
	return d;
}
void main()
{
	float s;
	point p1, p2;//creating objects to the class
	p1.input();//taking inputs
	p2.input();
	s = distance(p1, p2);//calling the distance function
	cout << "Distance between two points: " << s;
}