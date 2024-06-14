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
    bool isempty();
    bool isfull();
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
int Stack::pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        // x = arr[top];
        // top--;
        return arr[top--];
    }
}
bool Stack::isempty()
{
    if (top == -1)
        return true;
    else
        return false;
}
bool Stack::isfull()
{
    if (top == size)
        return true;
    else
        return false;
}
class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    Queue();
    Queue(int size);
    int enqueue(int);
    int dequeue();
    bool isFull();
    bool isEmpty();
};
Queue::Queue()
{
    arr=new int[size];
    front=rear=-1;
}
Queue::Queue(int size)
{
    this->size=size;
    arr=new int[size];
    front=rear=-1;
}
int Queue::enqueue(int data)
{
    if(isEmpty)
    {
        return -1;
    }
    else{
        arr[++rear]=data;
        return 0;
    }
}
int Queue::dequeue()
{
    if(isFull)
    {
        return-1;
    }
    else{
        return arr[front--]
    }
}
bool Queue::isFull()
{
    return (rear+1)%size==front;
}
bool Queue::isEmpty()
{
    return(rear==-1&&front==-1);
}
int main()
{
    cout << "1.Stack operation"
         << endl
         << "2.Queue operation" << endl;
    int data, ans, size;
    while (1)
    {
        int ch;
        cout << "Enter opeation:";
        cin >> ch;
        switch (ch)
        {

        case 1:
            cout << "Enter the size of stack:";
            cin >> size;
            Stack s(size);
            while (1)
            {
                cout << endl
                     << "1.Push\n2.pop\n3.Isempty\n4.Isfull\n5.Exit" << endl;
                int op;
                cout << endl
                     << "Enter operation to perform:";
                cin >> op;
                switch (op)
                {
                case 1:
                    cout << "Enter the data to push:";
                    cin >> data;
                    ans = s.push(data);
                    if (ans == -1)
                    {
                        cout << "Stack if full" << endl;
                    }
                    else
                    {
                        cout << "Element is pushed" << endl;
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
                        cout << ans << "Element is poped" << endl;
                    }
                    break;
                case 3:
                    if (s.isempty())
                    {
                        cout << "Stack empty";
                    }
                    else
                    {
                        cout << "Not empty";
                    }
                    break;
                case 4:
                    if (s.isfull())
                    {
                        cout << "Stack Full";
                    }
                    else
                    {
                        cout << "Not full";
                    }
                    break;
                case 5:
                    exit(0);
                    break;
                }
            }
        }
    }
    return 0;
}