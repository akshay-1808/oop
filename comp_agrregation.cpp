#include <iostream>
#include <string>
using namespace std;

// Class to represent a Date
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void showDate() const {
        cout << day << "/" << month << "/" << year << endl;
    }
};

// Class to represent a Subject
class Subject {
private:
    string name;
    int maxMarks;
    int marksObtained;

public:
    Subject(string sname) : name(sname), maxMarks(100), marksObtained(0) {}

    void setMarks(int marks) {
        if (marks <= maxMarks) {
            marksObtained = marks;
        } else {
            cout << "Marks cannot exceed maximum marks!" << endl;
        }
    }

    void displayResult() const {
        cout << "Subject: " << name << "\nMarks Obtained: " << marksObtained << "/" << maxMarks << endl;
    }
};

// Class to represent a Person
class Person {
private:
    string name;
    Date birthDate; // Composition: Date is part of Person and its lifetime depends on Person
    Subject* mySubject; // Aggregation: Person has a Subject but does not manage its lifetime

public:
    Person(string pname, int d, int m, int y, Subject* subject)
        : name(pname), birthDate(d, m, y), mySubject(subject) {}

    void showBirthDate() const {
        cout << "Birth Date: ";
        birthDate.showDate();
    }

    void showMySubject() const {
        if (mySubject) {
            mySubject->displayResult();
        } else {
            cout << "No subject assigned." << endl;
        }
    }
};

int main() {
    // Creating a Subject instance
    Subject math("Mathematics");
    math.setMarks(85);

    // Creating a Person instance with composition and aggregation
    Person john("John Doe", 15, 6, 1995, &math);

    // Displaying Person's information
    cout << "Person Info:\nName: John Doe" << endl;
    john.showBirthDate();
    john.showMySubject();

    return 0;
}
