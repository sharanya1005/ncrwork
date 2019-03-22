#include<iostream>
using namespace std;
class Polygon
{
public:
	float dimension_1;
	float dimension_2;
	Polygon()
	{
		dimension_1 = 0;
		dimension_2 = 0;
	}
	Polygon(float num_1, float num_2)
	{
		dimension_1 = num_1;
		dimension_2 = num_2;
	}
	float get_dimen1()
	{
		return dimension_1;
	}
	float get_dimen2()
	{
		return dimension_2;
	}
	void virtual  calculate_area() = 0;
	~Polygon()
	{
		cout << "Polygon class destructor" << endl;
	}
};
class Rectangle : public  Polygon
{
public:
	
	Rectangle(float length, float breadth):Polygon(length, breadth)
	{
	}
	void calculate_area()
	{
		float area = get_dimen1() * get_dimen2();
		cout << "Area of rectangle is: " << area << endl;
	}
	~Rectangle()
	{
		cout << "Rectangle class destructor" << endl;
	}
};
class Triangle : public  Polygon
{
public:
	Triangle(float base, float height):Polygon(base, height)
	{
	}
	void calculate_area()
	{
		float area = 0.5*get_dimen1() * get_dimen2();
		cout << "Area of triangle is: " << area << endl;
	}
	~Triangle()
	{
		cout << "Triangle class destructor" << endl;
	}
};

int main()
{
	Triangle *tri_ptr = new Triangle(10, 20);
	Polygon *poly1_ptr = tri_ptr;
	Rectangle *rect_ptr = new Rectangle(20, 30);
	Polygon *poly2_ptr = rect_ptr;
	poly1_ptr->calculate_area();
	poly2_ptr->calculate_area();
	delete tri_ptr;
	delete rect_ptr;
	return 0;
	
}