#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct student 
{
	string clas;
	string prn;
	float marks;
};
struct person
{
	string name;
	string add;
	string phone;
};
struct emp
{
	string empid;
	string desig;
	int sal;
};
struct date
{
	int day;
	int month;
	int year;
};

void set_student(struct student*,string,string,float);
void set_person(struct person*,string,string,string);
void set_emp(struct emp*,string,string,int);
// string get_clas(struct student*);
// string get_prn(struct student*);
// float get_marks(struct student*);
// string get_name(struct person*);
// string get_add(struct person*);
// int get_pone(struct person*);
// string get_id(struct emp*);
// string get_desig(struct emp*);
// int get_sal(struct emp*);
void display(struct student*,struct person*,struct emp*,struct date*);
int check_date(struct date*);
int leap(struct date*d);
float check_marks(float marks);
int check_phone(string phone);

int main()
{
	struct student s;
	string clas;
	string prn;
	float marks;
	cout<<"Enter information of student:\n";
	cout<<"Enter class:\n";
	cin>>clas;
	cout<<"Enter PRN:\n";
	cin>>prn;
	
	while(1)
	{
	    cout<<"Enter Average mark of student:\n";
		cin>>marks;
		int q1=check_marks(marks);
		if(q1==-1)
    	cout<<"\nInvalid marks please re-enter\n";
	    else
	    break;
	}
	
	set_student(&s,clas,prn,marks);
	
	struct person p;
	string name;
	string add;
	string phone;
	string birth;
	cout<<"\nEnter information of person\n";
	cout<<"Name:"<<endl;
	getline(cin,name);
	cout<<"Address:";
	getline(cin,add);
	while(1)
	{
	     cout<<"Phone no.:\n";
	     cin>>phone;
	     int q=check_phone(phone);
	     if(q==-1)
	     cout<<"Invalid phone number please re-enter\n";
	     else
	     break;
	}
	struct date d;
	while(1)
	{
		cout<<"Birth date (Enter day, month & year):\n";
     	cin>>d.day>>d.month>>d.year;
    	int q=check_date(&d);
    	if(q==-1)
    	cout<<"\nInvalid date please re-enter";
	    else
	    break;
    }
	set_person(&p,name,add,phone);
	
	struct emp e;
	string empid;
	string desig;
	int sal;
	cout<<"\nEnter information of employee:\n";
	cout<<"Employee id:\n";
	cin>>empid;
	cout<<"Employees designation:\n";
	cin>>desig;
	cout<<"Employees salary:\n";
	cin>>sal;
	set_emp(&e,empid,desig,sal);
	display(&s,&p,&e,&d);
}
void set_student(struct student*s,string clas,string prn,float marks)
{
	s->clas=clas;
	s->marks=marks;
	s->prn=prn;
}
void set_person(struct person*p,string name,string add,string phone)
{
	p->add=add;
	p->name=name;
	p->phone=phone;
}
void set_emp(struct emp*e,string empid,string desig,int sal)
{
	e->desig=desig;
	e->empid=empid;
	e->sal=sal;
}
// string get_clas(struct student*s)
// {
// 	return s->clas;
// }
// string get_prn(struct student*s)
// {
// 	return s->prn;
// }
// float get_marks(struct student*s)
// {
// 	return s->marks;
// }
// string get_name(struct person*p)
// {
// 	return p->name;
// }
// string get_add(struct person*p)
// {
// 	return p->add;
// }
// string get_phone(struct person*p)
// {
// 	return p->phone;
// }
// string get_id(struct emp*e)
// {
// 	return e->empid;
// }
// string get_desig(struct emp*e)
// {
// 	return e->desig;
// }
// int get_sal(struct emp*e)
// {
// 	return e->sal;
// }
void display(struct student*s,struct person*p,struct emp*e,struct date*d)
{
	// cout<<"\nInformation of student:";
	// cout<<"\nClass:"<<get_clas(s);
	// cout<<"\nPRN:"<<get_prn(s);
	// cout<<"\nMarks:"<<get_marks(s);
	// cout<<"\n\nInformation of person:";
	// cout<<"\nName:"<<get_name(p);
	// cout<<"\nAddress:"<<get_add(p);
	// cout<<"\nPhone:"<<get_phone(p);
	// cout<<"\nBirth date:"<<d->day<<"/"<<d->month<<"/"<<d->year;
	// cout<<"\n\nInformation of Employee:";
	// cout<<"\nEmployee id:"<<get_id(e);
	// cout<<"\nEmployees designation:"<<get_desig(e);
	// cout<<"\nEmployee salary:"<<get_sal(e);
	cout<<"\nInformation of student:";
	cout<<"\nClass:"<<s->clas;
	cout<<"\nPRN:"<<s->prn;
	cout<<"\nMarks:"<<s->marks;
	cout<<"\n\nInformation of person:";
	cout<<"\nName:"<<p->name;
	cout<<"\nAddress:"<<p->add;
	cout<<"\nPhone:"<<p->phone;
	cout<<"\nBirth date:"<<d->day<<"/"<<d->month<<"/"<<d->year;
	cout<<"\n\nInformation of Employee:";
	cout<<"\nEmployee id:"<<e->empid;
	cout<<"\nEmployees designation:"<<e->desig;
	cout<<"\nEmployee salary:"<<e->sal;
}

int check_date(struct date*d)
{
	int arr1[6]={1,3,5,7,9,11},arr2[5]={4,6,8,10,12},i;
	
	if(d->year>=1990&&d->year<=2070)
	{
		for(i=0;i<6;i++)
		{
			if(arr1[i]==d->month)
			{
				if(d->day<=31&&d->day>=1)
				return 0;
				else
				return -1;
			}
		}
		for(i=0;i<5;i++)
		{
			if(arr2[i]==d->month)
			{
				if(d->day<=30&&d->day>=1)
				return 0;
				else
				return -1;
			}
		}
		if(2==d->month)
		{
			int q=leap(d);
			if(d->day<=29&&d->day>=1&&q==1)
			return 0;
			else if(d->day<=28&&d->day>=1&&q==0)
			return 0;
			else
			return -1;
		}
		else
		return -1;
	}
	return -1;
}
int leap(struct date*d)
{
	return ((d->year%4==0&&d->year%100!=0)||d->year%400==0);
}


float check_marks(float marks)
{
	if(marks>=1.00&&marks<=100.00)
    return 0;
	else
	return -1;
}


int check_phone(string phone)
{
     int i;
     for(i=0;phone[i]!='\0';i++)
     {
         if(i==10)
         {
             return 0;
         }
     }
     if(i!=10)
     return -1;
}