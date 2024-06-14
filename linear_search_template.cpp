#include <bits/stdc++.h>
using namespace std;
template <typename t>

t ls(t a[], t data, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] = data)
        {
            return 0;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of array";
    cin >> n;
    int a[n], data, ans;
    cout << "Enter the array elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element to search:";
    cin >> data;
    ans = ls(a, data, n);
    if (ans==-1)
    {
        cout << "not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }
    return 0;
}