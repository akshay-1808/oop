// #include <bits/stdc++.h>
// using namespace std;
// class Date
// {
//     int day;
//     int month;
//     int year;

// public:
//     Date(int d, int m, int y)
//     {
//         day = d;
//         month = m;
//         year = y;
//     }

//     bool isLeap()
//     {
//         return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//     }
//     bool isValid()
//     {
//         if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0)
//         {
//             return false;
//         }
//         int dmonth[] = {31, 28 + isLeap(), 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
//         return day <= dmonth[month - 1];
//     }

//     void incrementDate()
//     {
//         int dmonth[] = {31, 28 + isLeap(), 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
//         if (++day >= dmonth[month - 1])
//         {
//             day = 1;
//             if (++month > 12)
//             {
//                 month = 1;
//                 year++;
//             }
//         }
//     }
//     void decrementDate()
//     {
//         int dmonth[] = {31, 28 + isLeap(), 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
//         if (--day < 1)
//         {
//             if (--month < 1)
//             {
//                 month = 12;
//                 year--;
//             }
//             day = dmonth[month - 1];
//         }
//     }

//     int getday()
//     {
//         return day;
//     }
//     int getmonth()
//     {
//         return month;
//     }
//     int getYear()
//     {
//         return year;
//     }
// };
// int main()
// {
//     int day, month, year;
//     cout << "ENter day month year:";
//     cin >> day >> month >> year;

//     Date d1(day, month, year);

//     string m[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEPT", "OCT", "NOV", "DEC"};

//     cout << d1.getday() << "/" << m[d1.getmonth() - 1] << "/" << d1.getYear();
//     cout << endl;
//     d1.decrementDate();
//     cout << d1.getday() << "/" << m[d1.getmonth() - 1] << "/" << d1.getYear();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// class Base
// {
//     public:
//    virtual void show()
//     {
//         cout<<"Base";
//     }
// };
// class Derived:public Base
// {
//     public:
//     void show()
//     {
//         cout<<"Derived";
//     }
// };
// int main(){
//     Base *b;
//     Derived d;
//     b=&d;
//     b->show();
//     // d.show();
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
private:
    int empNo;
    string empName;
    double salary;

public:
    // Method to input employee information
    void inputInformation() {
        cout << "Enter Employee Number: ";
        cin >> empNo;
        cin.ignore(); // to ignore the newline character left in the input buffer
        cout << "Enter Employee Name: ";
        getline(cin, empName);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Method to display employee information
    void displayInformation() const {
        cout << "Employee Number: " << empNo << "\nEmployee Name: " << empName << "\nSalary: " << salary << endl;
    }

    // Method to store employee information into a file
    void storeInformation() const {
        ofstream file("employees.txt", ios::app); // Append mode
        if (!file) {
            cerr << "File could not be opened!" << endl;
            return;
        }
        file << empNo << "\n" << empName << "\n" << salary << "\n";
        file.close();
        cout << "Employee information stored successfully." << endl;
    }

    // Static method to search for an employee record in the file
    static void searchRecord(int searchEmpNo) {
        ifstream file("employees.txt");
        if (!file) {
            cerr << "File could not be opened!" << endl;
            return;
        }

        int empNo;
        string empName;
        double salary;
        bool found = false;

        while (file >> empNo) {
            file.ignore(); // Ignore newline character after empNo
            getline(file, empName);
            file >> salary;

            if (empNo == searchEmpNo) {
                cout << "Employee Found:" << endl;
                cout << "Employee Number: " << empNo << "\nEmployee Name: " << empName << "\nSalary: " << salary << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Employee with number " << searchEmpNo << " not found." << endl;
        }

        file.close();
    }
};

int main() {
    Employee emp;
    int choice, searchEmpNo;

    while (true) {
        cout << "\nMenu:\n1. Input Employee Information\n2. Store Employee Information\n3. Search Employee Record\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                emp.inputInformation();
                break;
            case 2:
                emp.storeInformation();
                break;
            case 3:
                cout << "Enter Employee Number to search: ";
                cin >> searchEmpNo;
                Employee::searchRecord(searchEmpNo);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
