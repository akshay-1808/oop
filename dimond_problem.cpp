#include <bits/stdc++.h>
using namespace std;
class Person{
    public:
    void f1()
    {
        cout<<"Inside f1"<<endl;
    }
};
class Student: virtual public Person{
    public:
    void f2()
    {
        cout<<"Inside f2"<<endl;
    }
};
class Doctor:virtual public Person{
    public:
    void f3()
    {
        cout<<"Inside f3"<<endl;
    }
};
class Jhonny_Sins:public Student,public Doctor{
     public:
    void f4()
    {
        cout<<"Inside f4"<<endl;
    }
};
int main(){
    Jhonny_Sins j;
    j.f1();
    return 0;
}