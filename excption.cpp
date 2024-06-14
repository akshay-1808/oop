#include <bits/stdc++.h>
using namespace std;
class myException{

};
int main(){
    myException e1;
    int num;
    cin>>num;

    try{
        if(num%2!=0)
        throw e1;
    }
    catch(myException e1){
        cout<<"Not even";
    }
    return 0;
}