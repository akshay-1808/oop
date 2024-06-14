#include <bits/stdc++.h>
using namespace std;
class Matrix
{
private:
    int mat[10][10], i, j, row, col;

public:
    Matrix();
    void getMatrix();
    void printMatrix();
    friend void operator<<(ostream &output, Matrix &m);
    friend void operator>>(istream &input, Matrix &m);
    Matrix operator+(Matrix c);
};
Matrix::Matrix()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = 0;
        }
    }
}
void Matrix::getMatrix()
{
    cin >> row;
    cin >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
}
void Matrix::printMatrix()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j];
        }
    }
}
void operator<<(ostream &output, Matrix &m)

{
    for (m.i = 0; m.i < m.row; m.i++)
    {
        for (m.j = 0; m.j < m.col; m.j++)
        {
            output << m.mat[m.i][m.j];
        }
        output << endl;
    }
}
void operator>>(istream &input, Matrix &m)
{
    input >> m.row;
    input >> m.col;
    for (m.i = 0; m.i < m.row; m.i++)
    {
        for (m.j = 0; m.j < m.col; m.j++)
        {
            input >> m.mat[m.i][m.j];
        }
    }
}
Matrix Matrix ::operator+(Matrix c)
{
    Matrix result = c;
    if (row == c.row && col == c.col)
    {
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                result.mat[i][j] = mat[i][j] + c.mat[i][j];
            }
        }
    }
}
int main()
{
    Matrix m1, m2, m3;
    cin >> m1;
    cin >> m2;
    cout << m1;
    cout << m2;
    return 0;
}