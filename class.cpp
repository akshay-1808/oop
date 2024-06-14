#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	string moviename;
	double adultticketprice, childticketprice;
	int noofadultticketsold, noofchildticketsold;
	double donationrate, grossamount, amountdonated, netsale;
	cout<<fixed<<setprecision(2);
	cout<<"\nEnter the Movie Name : ";
	getline(cin,moviename);
	cout<<"\nEnter the Price of Adult ticket : ";
	cin>>adultticketprice;
	cout<<"\nEnter the Price of Child ticket : ";
	cin>>childticketprice;
	cout<<"\nEnter the No. of Adult ticket Sold : ";
	cin>>noofadultticketsold;
	cout<<"\nEnter the No. of Child ticket Sold : ";
	cin>>noofchildticketsold;
	cout<<"\nEnter the Donation Rate : "; 
	cin>>donationrate;
	grossamount=(adultticketprice * noofadultticketsold)+(childticketprice * noofchildticketsold);
	amountdonated=(grossamount * donationrate)/100;
	netsale=grossamount - amountdonated;
	cout<<"\n";
	cout<<"_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_";

	cout<<"\n";

	cout<<setfill('.')<<left<<setw(30)<<"Movie Name"<<right<<moviename<<"\n";

	cout<<setfill('.')<<left<<setw(30)<<"No. of Tickets Sold"<<right<<noofadultticketsold+noofchildticketsold<<"\n";

	cout<<setfill('.')<<left<<setw(30)<<"Gross Amount"<<right<<"$"<<grossamount<<"\n";

	cout<<setfill('.')<<left<<setw(30)<<"Donation Rate"<<right<<donationrate<<"%"<<"\n";

	cout<<setfill('.')<<left<<setw(30)<<"Amount Donated"<<right<<"$"<<amountdonated<<"\n";

	cout<<setfill('.')<<left<<setw(30)<<"Net Sale"<<right<<"$"<<netsale<<"\n";
}
