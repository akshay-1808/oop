#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() 
{
    string movieName;
    double adultTicketPrice;
    double childTicketPrice;
    int noOfAdultTicketsSold;
    int noOfChildTicketsSold;
    double percentDonation;
    double grossAmount;
    double amountDonated;
    double netSaleAmount;

    cout << "Enter the movie name: ";
    getline(cin, movieName);
    cout << "Enter the price of an adult ticket: ";
    cin >> adultTicketPrice;
    cout << "Enter the price of a child ticket: ";
    cin >> childTicketPrice;
    cout << "Enter the number of adult tickets sold: ";
    cin >> noOfAdultTicketsSold;
    cout << "Enter the number of child tickets sold: ";
    cin >> noOfChildTicketsSold;
    cout << "Enter the percentage of the gross amount donated to the charity: ";
    cin >> percentDonation;

    grossAmount = (adultTicketPrice * double(noOfAdultTicketsSold)) + (childTicketPrice * double(noOfChildTicketsSold));
    amountDonated = grossAmount * percentDonation / 100;
    netSaleAmount = grossAmount - amountDonated;

    cout << " " << endl;
    cout << "----------------------------*" << endl;

    cout << setfill('.') << left << setw(35) << "Movie Name:" << setfill('.') << right << setw(7) << " " << movieName << endl;
    cout << setfill('.') << left << setw(35) << "Number of Tickets Sold:" << setfill('.') << right << setw(7) << " " << noOfAdultTicketsSold + noOfChildTicketsSold << endl;
    cout << setfill('.') << left << setw(35) << "Gross Amount:" << setfill('.') << right << setw(10) << " Rs " << fixed << setprecision(2) << grossAmount << endl;
    cout << setfill('.') << left << setw(35) << "Percentage of Gross Amount Donated:" << setfill('.') << right << setw(7) << " " << fixed << setprecision(2) << percentDonation << "%" << endl;
    cout << setfill('.') << left << setw(35) << "Amount Donated:" << setfill('.') << right << setw(10) << " Rs " << fixed << setprecision(2) << amountDonated << endl;
    cout << setfill('.') << left << setw(35) << "Net Sale:" << setfill('.') << right << setw(10) << " Rs " << fixed << setprecision(2) << netSaleAmount << endl;


    return 0;
}