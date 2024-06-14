#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin;
    fin.open("first.txt");

    string l;

    while(!fin.eof())
    {
        getline(fin,l);
        cout<<l;
    }
    fin.close();
    return 0;
}