/*here shape is a base class. triangle, square and rectangle are the derived classes.
Demonstrate the use of pure virtual function by including display_area ( ) as a pure virtual function*/

#include <iostream>
using namespace std;
class Shape
{

public:
	virtual void get_dimension() = 0;
	
	virtual void display_area() = 0;
	

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
	Triangle tobj;
	Square sqobj;
	Rectangle robj;

	cout << "Enter the base and height of triangle: " << endl;
	tobj.get_dimension();
	tobj.display_area();

	
	cout << "Enter the side of a square: " << endl;
	sqobj.get_dimension();
	sqobj.display_area();

	
	cout << "Enter the length and breadth of a rectangle: " << endl;
	robj.get_dimension();
	robj.display_area();
	getchar();
	return 0;
}