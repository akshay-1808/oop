#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

class line
{
	int x1, y1, x2, y2;
	float slope, intercept;

public:
	line();
	line(int, int, int, int);
	void set_line(int, int, int, int);

	void set_slope_inter(float, float);
	void calculate_slope_inter();
	float get_slope();
	float get_intercept();
};

class circle
{
	int centerx, centery, radius;
	float circum, area;

public:
	circle();
	circle(int, int);
	circle(int, int, int);

	void set_circle(int, int, int);
	int get_cx();
	int get_cy();
	int get_radius();

	void calculateArea();
	void calculateCircumference();
	float get_area();
	float get_circum();

	bool isTangent(int, int, int, int);
	bool isTangent(float, float);
	bool isTangent(line &);
};

line::line() : x1(0), y1(0), x2(0), y2(0)
{
}
line::line(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
void line::set_line(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
void line::calculate_slope_inter()
{
	try
	{
		if ((x2 - x1) == 0)
			throw "Divide by zero";

		slope = float(y2 - y1) / (x2 - x1);
		intercept = y1 - (slope * x1);
		cout << "Slope: " << slope << endl
			 << "INtercept: " << intercept << endl;
	}
	catch (const char *n)
	{
		cout << "Exception found: " << n << endl;
	}
}
float line::get_slope()
{
	return slope;
}
float line::get_intercept()
{
	return intercept;
}
void line::set_slope_inter(float s, float i)
{
	slope = s;
	intercept = i;
}
circle::circle() : centerx(0), centery(0), radius(0)
{
}
// circle::circle(int cx,int cy,int radius=5)
//{
//	centerx=cx;
//	centery=cy;
// }
circle::circle(int cx, int cy, int r)
{
	centerx = cx;
	centery = cy;
	radius = r;
}
void circle::set_circle(int cx, int cy, int r)
{
	centerx = cx;
	centery = cy;
	radius = r;
}
int circle::get_cx()
{
	return centerx;
}
int circle::get_cy()
{
	return centery;
}
int circle::get_radius()
{
	return radius;
}
void circle::calculateCircumference()
{
	circum = 2 * (3.14 * radius);
}
void circle::calculateArea()
{
	area = 3.14 * (radius * radius);
}
float circle::get_circum()
{
	return circum;
}
float circle::get_area()
{
	return area;
}

bool circle::isTangent(int x1, int y1, int x2, int y2)
{
	line l(x1, y1, x2, y2);
	l.calculate_slope_inter();
	return isTangent(l);
}
bool circle::isTangent(float s, float i)
{
	line l;
	l.set_slope_inter(s, i);

	return isTangent(l); 
}
bool circle::isTangent(line &l)
{

	float dist = (abs(l.get_slope() * get_cx() - get_cy() + l.get_intercept()) / (sqrt(1 + (l.get_slope() * l.get_slope()))));
	cout << "DIST: " << dist << endl;
	if (abs(radius - dist) < 0.001)
		return 1;
	else
		return 0;
}

int main()
{
	int x1, x2, y1, y2, intercept, radius, cx, cy, t;
	float area, slope, inter;
	int choice;
	while (1)
	{
		// cout << "Enter your choice ";
		cout << "Enter your choice:\n"
             << "1. Calculate area and circumference of the circle\n"
             << "2. Check if a line (defined by two points) is tangent to the circle\n"
             << "3. Check if a line (defined by slope and intercept) is tangent to the circle\n"
             << "4. Check if a line (represented as a line object) is tangent to the circle\n"
             << "5. Exit\n";
		cin >> choice;
		cout << "Enter center points and radius of circle ";
		cin >> cx >> cy >> radius;
		circle c(cx, cy, radius);

		line l;
		switch (choice)
		{
		case 1:
			c.calculateArea();
			c.calculateCircumference();
			cout << "Area of circle is " << c.get_area() << endl;
			cout << "Circumference of circle is " << c.get_circum() << endl;
			break;

		case 2:
			cout << "Enter points of lines ";
			cin >> x1 >> y1 >> x2 >> y2;
			t = c.isTangent(x1, y1, x2, y2);
			if (t)
				cout << "LIne is tangent to circle " << endl;
			else
				cout << "LIne is not tangent to circle " << endl;
			break;
		case 3:
			cout << "Enter slope and intercept " << endl;
			cin >> slope >> inter;
			t = c.isTangent(slope, inter);
			if (t)
				cout << "LIne is tangent to circle " << endl;
			else
				cout << "LIne is not tangent to circle " << endl;
			break;
		case 4:
			cout << "Enter points of lines ";
			cin >> x1 >> y1 >> x2 >> y2;
			l.set_line(x1, y1, x2, y2);
			t = c.isTangent(l);
			if (t)
				cout << "LIne is tangent to circle " << endl;
			else
				cout << "LIne is not tangent to circle " << endl;
			break;
		case 5:
			exit(0);
		}
	}
}
