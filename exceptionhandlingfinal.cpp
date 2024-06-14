#include<iostream>
using namespace std;
int main()
{
	int no1,no2;
	cout<<"enter the value of no1,no2"<<endl;
	cin>>no1>>no2;
	cout<<"start"<<endl;
	try
	{
		cout<<"inside the try block"<<endl;
		if(no2==0)
		{
			throw no2;
			cout<<"invalid"<<endl;
		}
		else
		{
			float result=(float)no1/no2;
			cout<<"division of given numbers:"<<result<<endl;
		}
	}
	catch(int i)
	{
		cout<<"caught an exception trying to divide by zero:"<<endl;
		cout<<i<<endl;
	}
	cout<<"end"<<endl<<endl;
}


