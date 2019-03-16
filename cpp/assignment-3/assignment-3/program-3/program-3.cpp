#include <iostream>
using namespace std;
class Shape
{
	int color;
public:
	void get_color()
	{
		cin >> color;
	}
	void get_dimension()
	{
		cout << "dimension" << endl;
	}
	void display_area()
	{
		cout << "area" << endl;
	}
	void print_color()
	{
		cout << "color=" << color << endl;
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
		cout << "the triangle area is=" << (0.5*base*height) << endl;
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
		cout << "the area of the square is=" << (side*side) << endl;
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
		cout << "the area of the rectangle is=" << (length*breadth) << endl;
	}
};
int main()
{
	Shape sobj;
	cout << "Displaying the objects of shape class" << endl;
	sobj.get_dimension();
	sobj.get_color();
	sobj.display_area();
	sobj.print_color();
	Triangle tobj;
	cout << "enter the base and height of triangle\n";
	tobj.get_dimension();
	tobj.display_area();
	Square sqobj;
	cout << "enter the side of square\n";
	sqobj.get_dimension();
	sqobj.display_area();
	Rectangle robj;
	cout << "enter the length and breadth of rectangle\n";
	robj.get_dimension();
	robj.display_area();
	getchar();
	return 0;
}