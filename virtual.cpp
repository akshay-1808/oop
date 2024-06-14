// #include <bits/stdc++.h>
// using namespace std;

// class Base{
// 	public:
// 		virtual void f(){
// 			cout<<"Base class"<<endl;
// 		}
// };

// class Derived: public Base{
// 	public:
// 		virtual void f(){
// 			cout<<"Derived class"<<endl;
// 		}
// };

// class Derived2: public Derived{
// 	public:
// 		void f(){
// 			cout<<"Derived2 class"<<endl;
// 		}
// };

// int main(){
// 	Base* b=new Derived();
// 	Derived* d=new Derived2();
// 	b->f();
// 	// d->f();
// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
class Base
{
public:
	virtual void f1()
	{
		cout << "Base";
	}
};
class Derived : public Base
{
public:
	void f1()
	{
		cout << "Derived";
	}
};
int main()
{
	Base *ob1,ob2;
	Derived d;
	ob1=&d;
	ob1->f1();
	return 0;
}