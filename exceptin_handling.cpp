#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2;
    cin>>n1>>n2;

    try
    {
        if(n2==0)
        {
            throw n2;
        }
        else{
            float result=(float)n1/n2;
            cout<<result<<endl;
        }
    }
    catch(int n2)
    {
        cout<<"Error";
    }
    return 0;
}