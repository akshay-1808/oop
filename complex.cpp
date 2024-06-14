#include <bits/stdc++.h>
using namespace std;
class Complex
{
    float real;
    float img;

public:
    Complex();
    Complex(float, float);
    Complex operator+(Complex &);
    Complex operator-(Complex &);
    float getReal();
    float getImg();
};
Complex::Complex()
{
    real = img = 0;
}
Complex ::Complex(float real, float img)
{
    this->real = real;
    this->img = img;
}
Complex Complex ::operator+(Complex &temp)
{
    Complex ans;
    ans.real = real + temp.real;
    ans.img = img + temp.img;
    return ans;
}
Complex Complex ::operator-(Complex &temp)
{
    Complex ans;
    ans.real = real - temp.real;
    ans.img = img - temp.img;
    return ans;
}
float Complex::getReal()
{
    return real;
}
float Complex:: getImg()
{
    return img;
}
int main()
{
    float real1, img1, real2, img2;
    cout << "Enter the First real part of number:";
    cin >> real1;
    cout << "Enter the First img part of number:";
    cin >> img1;
    Complex c1(real1, img1);
    cout << "Enter the secomd real part of number:";
    cin >> real2;
    cout << "Enter the secomd img part of number:";
    cin >> img2;
    Complex c2(real2, img2);

    Complex sum = c1 + c2;
    Complex sub = c1 -  c2;

    cout << "Sum of complex no. is:"<<sum.getReal()<<"+"<<"i"<<sum.getImg()<<endl;
    cout << "Sub of complex no. is:"<<sub.getReal()<<"-"<<"i"<<sub.getImg()<<endl;
    return 0;
}