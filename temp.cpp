#include <bits/stdc++.h>
using namespace std;

class A{
    public:
        int a=10;
};

class B:public virtual A{
    public:
        void f(){
            a=20;
        }
};

class C:public virtual A{
    public:
        // void f(){
        //     a=30;
        // }
};

class D:public B, public C{
    public:


};


int main(){
    D d;
    d.f();
    return 0;
}