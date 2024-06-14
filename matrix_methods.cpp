// class_methods.cpp

#include "matrix.h"

Matrix::Matrix() : rows(0), cols(0) {}

Matrix::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
    matrix.resize(rows, vector<int>(cols, 0));
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
    matrix = other.matrix;
}

istream& operator>>(std::istream& CIN, Matrix& mat) {
    for(int i = 0; i < mat.rows; ++i) {
        for(int j = 0; j < mat.cols; ++j) {
            CIN >> mat.matrix[i][j];
        }
    }
    return CIN;
}

ostream& operator<<(std::ostream &COUT, const Matrix &mat) {
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            COUT << mat.matrix[i][j] << " ";
        }
        COUT << std::endl;
    }
    return COUT;
}

Matrix Matrix::operator+(const Matrix &other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions don't match for addition");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions don't match for subtraction");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions don't match for multiplication");
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

Matrix::~Matrix() {}
