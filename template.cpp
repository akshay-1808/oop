#include<iostream>
using namespace std;
template <typename t>
int linearsearch(t arr[],t data, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==data)
		return i;
	}
	return -1;
}
int main()
{
	int n,i,result,result1;
	cout<<"\nEnter the array size:\n";
	cin>>n;
	float arr[n],data;
	char ar[n],dat;	
	cout<<"\nEnter the array elements:\n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"\nEnter the data to be searched:\n";
	cin>>data;
	result=linearsearch<float>(arr,data,n);
	if(result==-1)
	{
		cout<<"\nno data found\n";
	}
	else
	cout<<"\ndata found at "<<result+1;
	cout<<"\nEnter the array elements:char\n";
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"\nEnter the data:\n";
	cin>>dat;
	result=linearsearch<char>(ar,dat,n);
	if(result==-1)
	{
		cout<<"\nno data found\n";
	}
	else
	cout<<"\ndata found at "<<result+1;
} 
