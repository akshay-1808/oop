#include <bits/stdc++.h>
using namespace std;

class Matrix
{
    int row, col;
    vector<vector<int>> v;

public:
    Matrix(int r, int c)
    {
        row = r;
        col = c;
        v.resize(row, vector<int>(col));
    }

    friend istream &operator>>(istream &CIN, Matrix &temp)
    {
        for (int i = 0; i < temp.row; i++)
        {
            for (int j = 0; j < temp.col; j++)
            {
                CIN >> temp.v[i][j];
            }
        }
        return CIN;
    }

    friend ostream &operator<<(ostream &COUT, Matrix &temp)
    {
        for (int i = 0; i < temp.row; i++)
        {
            for (int j = 0; j < temp.col; j++)
            {
                COUT << temp.v[i][j]<<" ";
            }
            cout<<endl;
        }
        return COUT;
    }
    Matrix operator+(Matrix &m)
    {
        Matrix temp(row,col);
        if (row == temp.row && col == temp.col)
        {
            for (int i = 0; i < temp.row; i++)
            {
                for (int j = 0; j < temp.col; j++)
                {
                   temp.v[i][j]=v[i][j]+m.v[i][j];
                }
            }
            return temp;
        }
    }
    Matrix operator-(Matrix &m)
    {
        Matrix temp(row,col);
        if (row == temp.row && col == temp.col)
        {
            for (int i = 0; i < temp.row; i++)
            {
                for (int j = 0; j < temp.col; j++)
                {
                   temp.v[i][j]=v[i][j]-m.v[i][j];
                }
            }
            return temp;
        }
    }
    Matrix operator*(Matrix &m)
    {
        Matrix temp(row,col);
        if (row == temp.col && col == temp.row)
        {
            for (int i = 0; i < temp.row; i++)
            {
                for (int j = 0; j < temp.col; j++)
                {
                   for(int k=0;k<col;k++)
                   {
                        temp.v[i][j]+=v[i][k]*m.v[k][j];
                   }
                }
            }
            return temp;
        }
    }
};

int main()
{
    int row, col;
    cout<<"Enter the row and col:";
    cin >> row >> col;
    Matrix m1(row, col), m2(row, col), m3(row, col);
    cout<<"Enter mat 1:";
    cin >> m1;
    cout<<"Enter mat 2:";
    cin >> m2;
    m3 = m1 + (m2);
    cout<<"m1+m2:"<<endl;
    cout<<m3<<endl;
    m3=m1-m2;
    cout<<m3<<endl;
    m3=m1*m2;
    cout<<m3<<endl;
    return 0;
}