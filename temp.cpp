#include <bits/stdc++.h>
using namespace std;
class Matrix
{
    int row, col;
    vector<vector<int>> mat;

public:
    Matrix();
    Matrix(int r, int c);
    friend istream &operator>>(istream &CIN, Matrix &temp);
    friend ostream &operator<<(ostream &COUT, Matrix &temp);
    Matrix operator+(Matrix &temp);
    Matrix operator-(Matrix &temp);
    Matrix operator*(Matrix &temp);
    int operator==(Matrix &temp);
};
Matrix::Matrix()
{
    row = col = 0;
}
Matrix::Matrix(int r, int c)
{
    this->row = r;
    this->col = c;
    mat.resize(row, vector<int>(col));
}
istream &operator>>(istream &CIN, Matrix &temp)
{
    for (int i = 0; i < temp.row; i++)
    {
        for (int j = 0; j < temp.col; j++)
        {
            CIN >> temp.mat[i][j];
        }
    }
    return CIN;
}
ostream &operator<<(ostream &COUT, Matrix &temp)
{
    for (int i = 0; i < temp.row; i++)
    {
        for (int j = 0; j < temp.col; j++)
        {
            COUT << temp.mat[i][j];
        }
        cout<<endl;
    }
    return COUT;
}
Matrix Matrix::operator+(Matrix &temp)
{
    Matrix add(row, col);
    if (row == temp.row && col == temp.col)
    {
        for (int i = 0; i < temp.row; i++)
        {
            for (int j = 0; j < temp.col; j++)
            {
                add.mat[i][j] = mat[i][j] + temp.mat[i][j];
            }
        }
        return add;
    }
}
Matrix Matrix::operator-(Matrix &temp)
{
    Matrix sub(row, col);
    if (row == temp.row && col == temp.col)
    {
        for (int i = 0; i < temp.row; i++)
        {
            for (int j = 0; j < temp.col; j++)
            {
                sub.mat[i][j] = mat[i][j] - temp.mat[i][j];
            }
        }
        return sub;
    }
}
Matrix Matrix::operator*(Matrix &temp)
{
    Matrix mul(row, col);

    if (row == temp.col && col == temp.row)
    {
        for (int i = 0; i < temp.row; i++)
        {
            for (int j = 0; j < temp.col; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    mul.mat[i][j] += mat[i][k] * temp.mat[k][j];
                }
            }
        }
        return mul;
    }
}
int Matrix ::operator==(Matrix &temp)
{
    int i,j;
    try{
        int x;
        if(row!=temp.row || col!=temp.col )
        {
            throw(x);
        }
    }
    catch(int x){
        return 0;
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(mat[i][j]!=temp.mat[i][j])
            return 0;
        }
    }
    return 1;
}
int main()
{
    int row1, col1, row2, col2;
    cout << "Enter the row and col of Mat 1:";
    cin >> row1 >> col1;
    Matrix m1(row1, col1);

    cout << "Enter the matrix 1 element:";
    cin >> m1;
    cout << "Enter the row and col of Mat 2:";
    cin >> row2 >> col2;
    cout << "Enter the matrix 2 element:";
    Matrix m2(row2, col2);
    cin >> m2;

    Matrix m3;
    cout<<"Addition:"<<endl;
    m3=m1+m2;
    cout<<m3<<endl;
    cout<<"Substraction:"<<endl;
    m3=m1-m2;
    cout<<m3<<endl;
    cout<<"Multiplication:"<<endl;
    m3=m1*m2;
    cout<<m3<<endl;

    if(m1==m2){
        cout<<"Same"<<endl;
    }
    else
    {
        cout<<"Diff"<<endl;
    }
    return 0;
}