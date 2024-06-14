#include <iostream>
using namespace std;

class Matrix
{
private:
    int **arr;
    int maxRows, maxCols;

public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix operator+(Matrix &m);
    Matrix operator-(Matrix &m);
    Matrix operator*(Matrix &m);
    int getMaxRows() const;
    int getMaxCols() const;
    void show();
    friend ostream &operator<<(ostream &output, Matrix &m);
    friend istream &operator>>(istream &input, Matrix &m);
};
