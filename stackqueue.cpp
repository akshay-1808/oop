#include<iostream>
using namespace std;
void push(int data);
int pop();
void display();
class stack
{
	private:
		int top;
		int size;
		int a[20];
	public:
		void push(int);
		int pop();
		void display();
		stack();
};
class queue
{
	private:
		int frount;
		int rear;
		int a[20];
	public:
		void enqueue(int);
		int dequeue();
		void display();
		queue();
};
stack::stack()
{
	top=0;
}
queue::queue()
{
	frount=-1;
	rear=-1;
}
int main()
{
	int size;
	cout<<"enter the size of array"<<endl;
	cin>>size;
	int a[size];
	stack s;
	queue q;
	int temp=1,no,choice,data,result,p=1,r=1;
	while(p)	
	{
		cout<<"1.stack\n2.queue"<<endl;
		cin>>no;
		switch(no)
		{
			case 1:while(temp)
			{
				cout<<"1.push\n2.pop\n3.display\n4.exit"<<endl;
				cin>>choice;
				switch(choice)
				{
					case 1:cout<<"enter the data you want to insert"<<endl;
						cin>>data;
						s.push(data);
						break;
					case 2:result=s.pop();
						if(result==1)
						{
							cout<<"no elements in array"<<endl;
						}
						else
						{
							cout<<"element is poped :"<<result<<endl;
						}
						break;
					case 3:s.display();
						break;
					case 4:temp=0;
						break;
				}
			
			}
			case 2:while(r)
				{
				cout<<"1.enqueue\n2.dequeue\n3.display"<<endl;
				cin>>choice;
				switch(choice)
				{
					case 1:cout<<"enter the data you want to insert"<<endl;
						cin>>data;
						q.enqueue(data);
						break;
					case 2:result=q.dequeue();
						if(result==1)
						{
							cout<<"no elements in array"<<endl;
						}
						else
						{
							cout<<"element is dequeue :"<<result<<endl;
						}
						break;
					case 3:q.display();
						break;
					case 4:temp=0;
						break;
				}
			}
		}
	}
}
void stack::push(int data)
{
	top=top+1;
	a[top]=data;
}
int stack::pop()
{
	if(top==0)
	{
		return 1;
	}
	else
	{
		int k=a[top];
		top=top-1;
		return k;
	}
}
void stack::display()
{
	int i;
	if(top==0)
	{
		cout<<"no elements in array"<<endl;
	}
	else
	{
		for(i=top;i>0;i--)
		{
			cout<<a[i]<<endl;
		}
	}
}
void queue::enqueue(int data)
{
	if(frount==-1&&rear==-1)
	{
		frount=frount+1;
		rear=rear+1;
		a[frount]=data;
		a[rear]=data;
	}
	else
	{
		rear=rear+1;
		a[rear]=data;
	}
}
int queue::dequeue()
{
	if(frount==-1)
	{
		return 1;
	}
	else
	{
		int k=a[frount];
		frount=frount+1;
		return k;
	}
}
void queue::display()
{
	int i;
	for(i=frount;i<=rear;i++)
	{
		cout<<a[i]<<endl;
	}
}
