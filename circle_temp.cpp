#include <bits/stdc++.h>
using namespace std;
class Line{
    int x1,y1,x2,y2;
    float slope,inter;

    public:
    // constructor
    Line();
    Line(int x1,int y1,int x2,int y2);
    // setter & getter
    void set_line(int x1,int y1,int x2,int y2);
    void set_slope_inter(float s,float i);

    // calculate slope & intercept

    void cal_slope_inter();
    float get_slope();
    float get_inter();

};

Line :: Line(): x1(0),y1(0),x2(0),y2(0)
{
}
Line :: Line(int x1,int y1,int x2,int y2)
{
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
}

void Line :: set_line(int x1,int y1,int x2,int y2)
{
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
}
void Line:: set_slope_inter(float s,float i)
{
    this->slope=s;
    this->inter=i;
}

void Line:: cal_slope_inter()
{
    try{
        if(x2-x1==0)
        {
            throw "invalid divide by zero";
        }
        slope=float(y2-y1)/(x2-x1);

        inter=y1-(slope*x1);   
    }
    catch (const char *n)
    {
        cout<<"Execption found:"<< n <<endl;
    }
}
float Line :: get_slope()
{
    return slope;
}
float Line :: get_inter()
{
    return inter;
}

class Circle{
    int cenx,ceny,radius;
    float circum,area;
    public:
    // Constructor
    Circle();
    Circle(int cx,int cy);
    Circle(int cx,int cy,int r);
    // setter & getter
    void set_circle(int cx,int cy,int r);
    int get_cenx();
    int get_ceny();
    int get_radius();

    // Calculate area & circumference

    void cal_area(); 
    void cal_cerfrence();
    float get_area();
    float get_cirm();

    // check line tangent

    bool isTangent(int x1,int x2,int y1,int y2);
    bool isTangent(float slope,float inter);
    bool isTangent(Line &l);  

};
Circle :: Circle() : cenx(0),ceny(0),radius(0){ }
Circle :: Circle (int cx,int cy)
{
    this->cenx=cx;
    this->ceny=cy;
}
Circle :: Circle(int cx,int cy,int r)
{
    this->cenx=cx;
    this->ceny=cy;
    this->radius=r;
}

void Circle::set_circle(int cx,int cy,int r)
{
    this->cenx=cx;
    this->ceny=cy;
    this->radius=r;
}
int Circle ::get_cenx()
{
    return cenx;
}
int Circle::get_ceny()
{
    return ceny;
}
int Circle::get_radius()
{
    return radius;

}


void Circle ::  cal_area()
{
    area=3.14*radius*radius;
}
void Circle :: cal_cerfrence()
{
    circum=2*3.14*radius;
}
float Circle :: get_area()
{
    return area;
}
float Circle :: get_cirm()
{
    return circum;
}

bool Circle ::  isTangent(int x1,int x2,int y1,int y2)
{
    Line l(x1,y1,x2,y2);
    l.cal_slope_inter();
    return isTangent(l);
}
bool Circle :: isTangent(float slope,float inter)
{
    Line l;
    l.set_slope_inter(slope,inter);

    return isTangent(l);
}
bool Circle :: isTangent(Line &l)
{
    
}  

int main(){
    
    return 0;
}