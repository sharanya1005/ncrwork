#include<iostream>
#include<cmath>
using namespace std;
class point;
class point
{
	int x;
	int y;
public:
	void input()
	{
		cout << "Enter the cartesian coordinates";
		cin >> x >> y;
		cout << endl;
	}

	friend float distance(point, point);
};
float distance(point a, point b)
{
	float d;
	d = sqrt(( pow((b.x - a.x), 2)) + (pow((b.y - a.y), 2)));
	return d;
}
void main()
{
	float s;
	point p1, p2;
	p1.input();
	p2.input();
    s =	distance(p1, p2);
	cout << "Distance between two points: " << s;
}