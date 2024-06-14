#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    float adult_ticket_pri, child_ticket_pri, per_gross_carity, gross_amount, amount_donated, net_sale;
    int no_adult_tic, no_child_tic;
    cout << "Enter the movie name:";
    getline(cin, name);
    cout << "Enter the Adult ticket price:";
    cin >> adult_ticket_pri;
    cout << "Enter the Child ticket price:";
    cin >> child_ticket_pri;
    cout << "Enter no of Adult ticket sold:";
    cin >> no_adult_tic;
    cout << "Enter no of Child ticket sold:";
    cin >> no_child_tic;
    cout << "Enter the percentaghe of grosss amount donate:";
    cin >> per_gross_carity;
    gross_amount = (adult_ticket_pri * no_adult_tic) + (child_ticket_pri * no_child_tic);
    amount_donated = gross_amount * per_gross_carity / 100;
    net_sale = gross_amount - amount_donated;

    cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;
    cout << endl;
    cout << setfill('.') << left << setw(35) << "Movie Name:" << name << endl;
    cout << setfill('.') << left << setw(35) << "Number Of Tickets Sold:" << "Rs" << " " << fixed << setprecision(2) << no_adult_tic + no_child_tic << endl;
    cout << setfill('.') << left << setw(35) << "Gross Amount:" << "Rs" << " " << fixed << setprecision(2) << gross_amount << endl;
    cout << setfill('.') << left << setw(35) << "Percentage Of Gross Amount Doneted:" << per_gross_carity << "%" << endl;
    cout << setfill('.') << left << setw(35) << "Amount Donated:" << "Rs" << " " << fixed << setprecision(2) << amount_donated << endl;
    cout << setfill('.') << left << setw(35) << "Net Sale:" << "Rs" << " " << fixed << setprecision(2) << net_sale << endl;
    return 0;
}