
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    vector<vector<int>> matrix;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(int numRows, int numCols);
    Matrix(const Matrix &other);

    friend istream& operator>>(istream& CIN, Matrix& mat);
    friend ostream& operator<<(ostream &COUT, const Matrix &mat);

    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;

    ~Matrix();
};

