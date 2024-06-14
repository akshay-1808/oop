#include <bits/stdc++.h>
using namespace std;
class person
{
    string name;
    string add;
    long long ph;
    string dob;

public:
    person()
    {
        this->name = "";
        this->add = "";
        this->ph = 0;
        this->dob = "";
    }
    person(string name, string add, long long ph, string dob)
    {
        this->name = name;
        this->add = add;
        this->ph = ph;
        this->dob = dob;
    }
    string getName()
    {
        return name;
    }
    string getAdd()
    {
        return add;
    }
    long long getPh()
    {
        return ph;
    }
    string getDob()
    {
        return dob;
    }
};
class student
{
    char div;
    string prn;
    int avg;

public:
    student()
    {
        div = '0';
        prn = "";
        avg = 0;
    }
    student(char div, string prn, int avg)
    {
        this->div = div;
        this->prn = prn;
        this->avg = avg;
    }
    char getDiv()
    {
        return div;
    }
    string getPrn()
    {
        return prn;
    }
    int getAvg()
    {
        return avg;
    }
    void print(){
        cout<<"DIV="<<div<<endl;
        cout<<"PRN="<<prn<<endl;
        cout<<"AVG="<<avg<<endl;
    }
};
int main()
{
    char d;
    cout<<"Enter the division of student:";
    cin>>d;
    string prn;
    cout<<"Enter the PRN of student:";
    cin>>prn;
    int avg;
    cout<<"Enter the Avg marks of student:";
    cin>>avg;
    person p1;
    student s1(d,prn,avg);
    s1.print();
    string name;
    return 0;
}