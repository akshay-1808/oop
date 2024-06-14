#include<iostream>
using namespace std;
class complex
{
	private:
		int real;
		int imaginary;
	public:
		void setreal(int);
		int getreal();
		void setima(int);
		int getima();
		complex operator+(complex& q);
};
void complex::setreal(int k)
{
	real=k;
}
int complex::getreal()
{
	return real;
}
void complex::setima(int l)
{
	imaginary=l;
}
int complex::getima()
{
	return imaginary;
}
complex complex::operator+(complex &q)
{
	complex r;
	r.real=real+q.real;
	r.imaginary=imaginary+q.imaginary;
	return r;
}
int main()
{
	complex p,q,r;
	cout<<"enter real value of a"<<endl;
	int reala;
	cin>>reala;
	p.setreal(reala);
	cout<<"enter imaginary value of a"<<endl;
	int imaa;
	cin>>imaa;
	p.setima(imaa);
	cout<<"enter real value of b"<<endl;
	int realb;
	cin>>realb;
	q.setreal(realb);
	cout<<"enter imaginary value of b"<<endl;
	int imab;
	cin>>imab;
	q.setima(imab);
	r=p+q;
	cout<<"value :"<<r.getreal()<<" + i"<<r.getima()<<endl;
}
