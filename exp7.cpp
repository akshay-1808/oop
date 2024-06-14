#include <bits/stdc++.h>
using namespace std;
class Complex
{
private:
    float real;
    float img;
public:
    Complex();
    Complex(float,float);
    ~Complex();
    Complex operator+(const Complex&) ;
    Complex operator-(const Complex&) ;
    float getReal();
    float getImg();
};

Complex::Complex()
{
    real=img=0;
}

Complex::Complex(float real,float img)
{
    this->real=real;
    this->img=img;
}

Complex::~Complex()
{
}
Complex Complex::operator+(const Complex& temp)
{
    Complex ans;
    ans.real=real+temp.real;
    ans.img=real+temp.img;
    return ans;
}
Complex Complex:: operator-(const Complex& temp) 
{
    Complex ans;
    ans.real=real-temp.real;
    ans.img=real-temp.img;
    return ans;
}
float Complex:: getReal()
{
    return real;
}
float Complex::getImg()
{
    return img;
}
int main(){
    float real1,img1,real2,img2;
    cout<<"Enter the First real part of number:";
    cin>>real1;
    cout<<"Enter the First img part of number:";
    cin>>img1;
    Complex c1(real1,img1);
    cout<<"Enter the secomd real part of number:";
    cin>>real2;
    cout<<"Enter the secomd img part of number:";
    cin>>img2;
    Complex c2(real2,img2);
    Complex sum=c1+c2;
    Complex diff=c1-c2;
    // cout<<"Sum of complex number is:";
    // cout << real << " + " << img << "i" << endl;
    // cout<<"Difference of Complex number is:";
    // cout << real << " + " << img << "i" << endl;
    
    cout << "Sum of complex number is: " << sum.getReal() << " + " << sum.getImg() << "i" << endl;
    cout << "Difference of Complex number is: " << diff.getReal() << " + " << diff.getImg() << "i" << endl;
    
    return 0;
}