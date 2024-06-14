#include <bits/stdc++.h>
using namespace std;
class Line
{
private:
    int x1, y1, x2, y2;
    float slope, intercept;

public:
    Line();
    Line(int x1, int y1, int x2, int y2);
    int getx1();
    int getx2();
    int gety1();
    int gety2();
    void calSlope();
    void calIntercept();
    double getSlope();
    double getIntercept();
};
Line ::Line()
{
    x1 = y1 = x2 = y2 = 0;
    slope = intercept = 0;
}
Line::Line(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}
int Line::getx1()
{
    return x1;
}
int Line::getx2()
{
    return x2;
}
int Line::gety1()
{
    return y1;
}
int Line::gety2()
{
    return y2;
}
void Line:: calSlope()
{
    if(x2-x1!=0)
    {
        slope=static_cast<double>(y2-y1)/(x2-x1);
    }
    else{
        slope=NAN;
    }
}
void Line:: calIntercept()
{
    intercept=y1-slope*x1;
}
double Line:: getSlope()
{
    return slope;
}
double Line:: getIntercept()
{
    return intercept;
}
class Circle
{
private:
    int cenX, cenY, radius;
    float circumference, area;

public:
    Circle();
    Circle(int cx, int cy);
    Circle(int cx, int cy, int r);
    void setCenter(int cx, int cy);
    void setRadius(int r);
    int getCenterX();
    int getCenterY();
    int getRadius();
    void calArea();
    void calCircumference();
    float getArea();
    float getCircumference();
};
Circle::Circle()
{
    cenX = cenY = radius = 0;
}
Circle::Circle(int cx, int cy)
{
    this->cenX = cx;
    this->cenY = cy;
}
Circle::Circle(int cx, int cy, int r)
{
    this->cenX = cx;
    this->cenY = cy;
    this->radius = r;
}
void Circle::setCenter(int cx, int cy)
{
    this->cenX = cx;
    this->cenY = cy;
}
void Circle::setRadius(int r)
{
    this->radius = r;
}
int Circle::getCenterX()
{
    return cenX;
}
int Circle::getCenterY()
{
    return cenY;
}
int Circle::getRadius()
{
    return radius;
}
void Circle::calArea()
{
    area = 3.14 * radius * radius;
}
void Circle::calCircumference()
{
    circumference = 2 * 3.14 * radius;
}
float Circle::getArea()
{
    return area;
}
float Circle::getCircumference()
{
    return circumference;
}
int main()
{

    return 0;
}