#include<iostream>
using namespace std;
class vehicle
{
	private:
	int i;
	public:
	vehicle(int);
};
vehicle::vehicle(int arg)
{
	i=arg;
	cout<<"vehicle's constructor called:value of i:"<<i<<endl;
}
class car:vehicle
{
	public:
	car(int);
};
car::car(int x):vehicle(x)
{
	cout<<"car's constructor is called"<<endl;
}
int main()
{
	car obj(10);
	return 0;
}
