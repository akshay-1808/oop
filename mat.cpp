// #include <bits/stdc++.h>

// using namespace std;

// class Matrix {
// private:
//     vector<vector<int>> matrix;
//     int rows;
//     int cols;

// public:
//     Matrix();
//     Matrix(int numRows, int numCols);
//     Matrix(const Matrix &other);

//     friend istream& operator>>(istream& CIN, Matrix& mat);
//     friend ostream& operator<<(ostream &COUT, const Matrix &mat);

//     Matrix operator+(const Matrix &other) const;
//     Matrix operator-(const Matrix &other) const;
//     Matrix operator*(const Matrix &other) const;

//     ~Matrix();
// };

// Matrix::Matrix() : rows(0), cols(0) {}

// Matrix::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
//     matrix.resize(rows, vector<int>(cols, 0));
// }

// Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
//     matrix = other.matrix;
// }

// istream& operator>>(std::istream& CIN, Matrix& mat) {
//     for(int i = 0; i < mat.rows; ++i) {
//         for(int j = 0; j < mat.cols; ++j) {
//             CIN >> mat.matrix[i][j];
//         }
//     }
//     return CIN;
// }

// ostream& operator<<(std::ostream &COUT, const Matrix &mat) {
//     for (int i = 0; i < mat.rows; ++i) {
//         for (int j = 0; j < mat.cols; ++j) {
//             COUT << mat.matrix[i][j] << " ";
//         }
//         COUT << std::endl;
//     }
//     return COUT;
// }

// Matrix Matrix::operator+(const Matrix &other) const {
//     if (rows != other.rows || cols != other.cols) {
//         throw std::invalid_argument("Matrix dimensions don't match for addition");
//     }

//     Matrix result(rows, cols);
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) {
//             result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
//         }
//     }
//     return result;
// }

// Matrix Matrix::operator-(const Matrix &other) const {
//     if (rows != other.rows || cols != other.cols) {
//         throw std::invalid_argument("Matrix dimensions don't match for subtraction");
//     }

//     Matrix result(rows, cols);
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) {
//             result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
//         }
//     }
//     return result;
// }

// Matrix Matrix::operator*(const Matrix &other) const {
//     if (cols != other.rows) {
//         throw std::invalid_argument("Matrix dimensions don't match for multiplication");
//     }

//     Matrix result(rows, other.cols);
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < other.cols; ++j) {
//             for (int k = 0; k < cols; ++k) {
//                 result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
//             }
//         }
//     }
//     return result;
// }

// Matrix::~Matrix() {}

// int main()
// {
//     int row, col;
//     cout << "Enter the rows and column for both matrix:";
//     cin >> row >> col;
//     Matrix mat1(row, col), mat2(row, col);
//     cout << "Enter elements of matrix 1:\n";
//     cin >> mat1;
//     cout << "Enter elements of matrix 2:\n";
//     cin >> mat2;

//     try
//     {
//         cout << "Matrix Addition Result:\n";
//         cout << mat1 + mat2 << endl;

//         cout << "Matrix Subtraction Result:\n";
//         cout << mat1 - mat2 << endl;

//         cout << "Matrix Multiplication Result:\n";
//         cout << mat1 * mat2 << endl;
//     }
//     catch (const exception &e)
//     {
//         cerr << "Error: " << e.what() << endl;
//     }

//     return 0;
// }


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