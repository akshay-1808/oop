#include <iostream>
#include <vector>
#include <stdexcept>
#include"matrix.h"

using namespace std;


int main() {
    int row, col;
    cout<<"Enter the rows and column for both matrix:";
    cin>>row>>col;
    Matrix mat1(row,col), mat2(row,col);
    cout << "Enter elements of matrix 1:\n";
    cin >> mat1;
    cout << "Enter elements of matrix 2:\n";
    cin >> mat2;

    try {
        cout << "Matrix Addition Result:\n";
        cout << mat1 + mat2 << endl;

        cout << "Matrix Subtraction Result:\n";
        cout << mat1 - mat2 << endl;

        cout << "Matrix Multiplication Result:\n";
        cout << mat1 * mat2 << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
