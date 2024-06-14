#include <bits/stdc++.h>
using namespace std;
template <typename type>
int ls(type a[], type data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == data)
        {
            return 1;
        }
    }
    return -1;
}
int main()
{
    int size, data;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cout << "Enter data:";
    cin >> data;
    int re = ls<int>(a, data, size);
    if (re)
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
    return 0;
}