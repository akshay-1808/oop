#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack();
    Stack(int);
    int push(int);
    int pop();
    bool isEmpty();
    bool isFull();
};
Stack::Stack()
{
    this->top = -1;
}
Stack::Stack(int size)
{
    this->size = size;
    arr = new int[size];
    this->top = -1;
}
int Stack::push(int data)
{
    if (top == size - 1)
    {
        return -1;
    }
    else
    {
        arr[++top] = data;
        return 0;
    }
}
int Stack ::pop()
{
    if (top == -1)
        return -1;
    else
    {
        top--;
        return arr[top];
    }
}
bool Stack::isEmpty()
{
    return (top == -1);
}
bool Stack::isFull()
{
    return (top == size - 1);
}
class Queue{
    int *queArray;
    int front;
    int rear;
    int space_used;
    int size;
    public:
    Queue();
    Queue(int size);
    // ~Queue();
    int enqueue(int data);
    int dequeue();
    bool isEmpty();
    bool isFull();
};
Queue::Queue()
{
    front=0;
    rear=-1;
    space_used=0;
}
Queue :: Queue(int size)
{
    this->size=size;
    queArray=new int [size];
    front=0;
    rear=-1;
    space_used=0;
}
// ~Queue();
int Queue::enqueue(int data)
{
    if(isFull())
    {
        return -1;
    }
    else{
        rear=(rear+1)%size;
        queArray[rear]=data;
        space_used++;
        return 0;
    }
}
int Queue :: dequeue()
{
    if(isEmpty())
    {
        return -1;
    }
    else{
        int data=queArray[front];
        front=(front+1)%size;
        space_used--;
        return data;
    }
}
bool Queue :: isEmpty()
{
    return (space_used==0);
}
bool Queue :: isFull()
{
    return (space_used==size);
}
int main()
{

    cout << "1.For Stack" << endl
         << "2.For Queue" << endl;
    int data, ans, size, ch;
    while (1)
    {
        cout << "Enter Choice:";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter the size of stack:";
            cin >> size;
            Stack s(size);
            while (1)
            {
                cout << "1.Push data:\n2.Pop data:\n3.isEmpty\n4.isFull:\n5.Exit\n";
                cout << "Enter the choice to perform operation:";
                cin >> ch;

                switch (ch)
                {
                case 1:
                    cout << "Enter data to push";
                    cin >> data;
                    ans = s.push(data);
                    if (ans == -1)
                    {
                        cout << "Stack is full" << endl;
                    }
                    else
                    {
                        cout << data << " is Pushed " << endl;
                    }
                    break;
                case 2:
                    ans = s.pop();
                    if (ans == -1)
                    {
                        cout << "Stack is empty" << endl;
                    }
                    else
                    {
                        cout << data << " is poped" << endl;
                    }
                    break;
                case 3:
                    if (s.isEmpty())
                    {
                        cout << "Stack is empty" << endl;
                    }
                    else
                    {
                        cout << "Stack is not empty" << endl;
                    }
                    break;
                case 4:
                    if (s.isFull())
                    {
                        cout << "Stack is full" << endl;
                    }
                    else
                    {
                        cout << "Stack is not full" << endl;
                    }
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    cout << "Enter the valid choice" << endl;
                }
            }
        }
        else if(ch==2)
        {
            cout<<"Enter the size of Queue:";
            cin>>size;
            Queue q(size);
            while(1)
            {
                cout << "1.Enqueue data:\n2.Dequeue data:\n3.isEmpty\n4.isFull:\n5.Exit\n";
                cout << "Enter the choice to perform operation:";
                cin >> ch;
            }
        }
    }
    return 0;
}