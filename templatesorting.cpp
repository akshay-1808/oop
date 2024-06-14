#include<iostream>
using namespace std;
template<class T>
void sort(T arr[],int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=size-1;i<j;j--)
		{
			if(arr[j]<arr[j-1])
			{
				T temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
}
int main()
{
	int arr[]={2,6,4,9,5};
	float arr1[]={5.4,8.7,9.0,1.2,3.4};
	char arr2[]={'a','t','e','r','l'};
	
	sort(arr,5);
	cout<<"After sorting "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	sort(arr1,5);
	cout<<endl<<"After sorting "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<arr1[i]<<" ";
	}
	
	sort(arr2,5);
	cout<<endl<<"After sorting "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<arr2[i]<<" ";
	}
	
}
