#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    vector<int> data;

public:
    void push(int val)
    {
        data.push_back(val);
    }
    int pop()
    {
        if (isEmpty)
        {
            return -1;
        }
        else
        {
            int topEle = data.back();
            data.pop_back();
            return topEle;
        }
    }
    bool isEmpty()
    {
        return data.empty();
    }
};
int main()
{
    int data, re;
    cout << "Enter Choice";
    while (1)
    {
        Stack s;
        int ch;
        cin >> ch;
        cout << "1.push\n"
             << "2.pop\n"
             << "3.Is empty" << endl;
        switch (ch)
        {
        case 1:
            cout << "Enter the data to push:";
            cin >> data;
            s.push(data);
            break;
        case 2:
            
        default:
            break;
        }
    }
    return 0;
}