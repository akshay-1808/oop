#include <bits/stdc++.h>
using namespace std;
class Address
{
private:
    int houseno;
    string city;
    int pincode;

public:
    void setHouseno(int);
    void setCity(string);
    void setPincode(int);
    int getHouseno();
    string getCity();
    int getPincode();
};
void Address::setHouseno(int houseno)
{
    this->houseno = houseno;
}
void Address::setCity(string city)
{
    this->city=city;
}
void Address::setPincode(int pin)
{
    this->pincode=pin;
}
int Address::getHouseno()
{
    return houseno;
}
string Address::getCity()
{
    return city;
}
int Address::getPincode()
{
    return pincode;
}
class Person
{
private:
    int id;
    string name;
    int age;
    Address a;

public:
    void setId(int);
    void setName(string);
    void setAge(int);
    int getId();
    string getName();
    int getAge();
    void setAddres(Address);
};
void Person::setId(int id)
{
    this->id = id;
}
void Person::setName(string name)
{
    this->name = name;
}
void Person::setAge(int age)
{
    this->age = age;
}
int Person::getId()
{
    return id;
}
string Person::getName()
{
    return name;
}
int Person::getAge()
{
    return age;
}
// void Pesron::setAddres()
int main()
{

    return 0;
}