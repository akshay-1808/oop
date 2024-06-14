#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex ():real(0), imaginary(0){}
    
    Complex(double realPart, double imagPart) {
        real = realPart;
        imaginary = imagPart;
    }

    // Copy constructor
    Complex(const Complex &other) {
        real = other.real;
        imaginary = other.imaginary;
    }

    // Addition operator overloading
    Complex operator+(const Complex &other) {
        Complex temp;
        temp.real = real + other.real;
        temp.imaginary = imaginary + other.imaginary;
        return temp;
    }

    // Subtraction operator overloading
    Complex operator-(const Complex &other) {
        Complex temp;
        temp.real = real - other.real;
        temp.imaginary = imaginary - other.imaginary;
        return temp;
    }

    // Display complex number
    void display() {
        cout << real << " + " << imaginary << "i";
    }
};

int main() {
    // Create complex numbers
    Complex num1(2.5, 3.7);
    Complex num2(1.2, 0.5);

    // Perform addition and display result
    Complex sum = num1 + num2;
    cout << "Addition Result: ";
    sum.display();
    cout << endl;

    // Perform subtraction and display result
    Complex diff = num1 - num2;
    cout << "Subtraction Result: ";
    diff.display();
    cout << endl;

    return 0;
}
