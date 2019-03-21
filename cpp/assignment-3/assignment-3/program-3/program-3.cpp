/*here shape is a base class. triangle, square and rectangle are the derived classes. 
Demonstrate the use of virtual function by including display_area ( ) as a virtual function*/

#include <iostream>
using namespace std;
class Shape
{
	
public:
	 virtual void get_dimension()
	{
		cout << "Dimension" << endl;
	}
	virtual void display_area()
	{
		cout << "Area" << endl;
	}
	
};
class Triangle :public Shape
{
	int base, height;
public:
	void get_dimension()
	{
		cin >> base >> height;
	}
	void display_area()
	{
		cout << "The area of a triangle is: " << (0.5*base*height) << endl;
	}
};
class Square :public Shape
{
	int side;
public:
	void get_dimension()
	{
		cin >> side;
	}
	void display_area()
	{
		cout << "The area of a square is: " << (side*side) << endl;
	}
};
class Rectangle :public Shape
{
	int length, breadth;
public:
	void get_dimension()
	{
		cin >> length >> breadth;
	}
	void display_area()
	{
		cout << "The area of a rectangle is: " << (length*breadth) << endl;
	}
};
int main()
{
	Shape *sobj;

	Triangle tobj;
	Square sqobj;
	Rectangle robj;

	sobj = &tobj;

	cout << "Enter the base and height of triangle: " << endl;
	sobj->get_dimension();
	sobj->display_area();

	sobj = &sqobj;
	cout << "Enter the side of a square: " << endl;
	sobj->get_dimension();
	sobj->display_area();

	sobj = &robj;
	cout << "Enter the length and breadth of a rectangle: " << endl;
	sobj->get_dimension();
	sobj->display_area();
	getchar();
	return 0;
}