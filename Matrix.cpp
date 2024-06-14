#include<iostream>
using namespace std;
class date
{
	private:
		int day;
		int month;
		int year;
	public:
		void setdate(int,int,int); 
		int getday();
		int getmonth();
		int getyear();
		int checkday(int,int,int);
		int checkleap(int);
		int checkmonth(int);
		int checkyear(int);
};
int main()
{
	date d1;
	int d,m,y;
  	cout<<"enter the date=";
  	cin>>d>>m>>y;
   	d1.setdate(d,m,y);
   	cout<<"day="<<d<<endl;
   	cout<<"month="<<d1.getmonth()<<endl;
   	cout<<"year="<<d1.getyear()<<endl;
   	cout<<"the date ="<<d1.getday()<<"/"<<d1.getmonth()<<"/"<<d1.getyear()<<endl;
   	d1.checkday(d,m,y);
   	d1.checkleap(y);
  	d1.checkmonth(m);
   	d1.checkyear(y);
}
void date::setdate(int d,int m,int y)
{
	day=d;
	month=m;
	year=y;
}
int date::getday()
{
 	return day;
}
int date::getmonth()
{
 	return month;
}
int date::getyear()
{
	return year;
}
int date::checkday(int d,int m,int y)
{
	if((d>=1 && d<=31) && (m==1 || m==3|| m==5 || m==7 || m==8 || m==10 || m==12))
	{
		cout<<"day is valid"<<endl;
	}
	else if((d>=1 && d<=30) && (m==4 || m==6|| m==9 || m==11))
	{
		cout<<"day is valid"<<endl;
	}
	else if((d==29 && m==2) && (y%400==0 || y%100!=0 || y%4==0))
	{
		cout<<"day is valid"<<endl;
	}
	else
	{
	 cout<<"day is invalid"<<endl;	
	}
 }
int date:: checkleap(int y)
{
	if(y%4==0&&y%100!=0||y%4==0)
	{
		cout<<"year is leap "<<endl;
	}
	else
	{
		cout<<"year is not leap"<<endl;
	}
} 
int date:: checkmonth(int m)
{
	if(m>=1 && m<=12)
	{
		cout<<"month is valid"<<endl;
	}
	else
	{
		cout<<"month is invalid"<<endl;
	}
}  
int date:: checkyear(int y)
{
	if(y>=2000 && y<=2999)
	{
		cout<<"year is valid"<<endl;
	}
	else
	{
		cout<<"year is not valid"<<endl;
	}
}    
