#include<iostream>
using namespace std;
int add(int x,int y)
{
	int z=x+y;
	return z;
}
int add(int x,int y,int w)
{
	int z=x+y+w;
	return z;
}
int add(int x)
{
	int z=x+x;
	return z;
}
int main()
{
	int a,b,c;
	cout<<"\nEnter 1 number\n";
	cin>>a;
	cout<<"\nEnter 2 numbers\n";
	cin>>b>>c;
	cout<<"\nsum of similar numbers\n"<<add(a);
	cout<<"\nsum of two numbers\n"<<add(b,c);
	cout<<"\nsum of three numbers\n"<<add(a,b,c);
} 
