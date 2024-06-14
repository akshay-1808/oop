#include <bits/stdc++.h>
using namespace std;

class App{
	public:
		virtual void os()=0;
};

class Ios_Dev: public App{
	public:
		void os(){
			cout<<"Ios"<<endl;
		}
};

class Android_Dev: public App{
	public:
		void os(){
			cout<<"Android"<<endl;
		}
};

int main(){
	Ios_Dev i;
	i.os();
	return 0;
}