#include <bits/stdc++.h>
using namespace std;

int main(){

    // write of file
    
    ofstream obj;
    obj.open("first.txt");

    string s;
    // cout<<"Enter the string :";
    // cin>>s;
    char arr[50]="susesh kumbhar";
    obj<<arr;

    obj.close();
// Read of file

    // ifstream fr;
    // fr.open("first.txt");
    // char ch;
    // int i=1;

    // while(!fr.eof())
    // {
    //     fr.get(ch);
    //     cout<<ch;
    // }
    // fr.close();
    return 0;
}