#include <bits/stdc++.h>
using namespace std;
class Person
{
    string name;
    string address;
    string city;
    string phone;

public:
    Person();
    Person(string, string, string, string);
    string getName();
    string getAddress();
    string getCity();
    string getPhone();
};
Person :: Person()
{
    name=" ";
    address=" ";
    city=" ";
    phone=" ";
}
Person(string name, string address, string city, string phone)
{
    this->name=name;
    this->address=address;
    this->city=city;
    this->phone=phone;

}
string getName();
string getAddress();
string getCity();
string getPhone();
int main()
{

    return 0;
}