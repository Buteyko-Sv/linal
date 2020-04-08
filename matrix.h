#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
class Matrix
{
public:

    Matrix(unsigned int m, unsigned int n);//constructors
    Matrix(unsigned int m, unsigned int n, double **value);
    ~Matrix();//destructor

    double getValue(unsigned int i, unsigned int j) const; //���������� �������� �������� � ��������� i, j
    unsigned int getM() const; //���������� ���-�� �����
    unsigned int getN() const; //���������� ���-�� ��������

    void setValue(unsigned int i, unsigned int j, double value); //����������� �������� ��-�� � ��������� i, j

    bool operator== (const Matrix& M) const;
    bool operator!= (const Matrix& M) const;

    Matrix operator+ (const Matrix& M) const;
    Matrix operator+= (const Matrix& M) const;
    Matrix operator- (const Matrix& M) const;
    Matrix operator-= (const Matrix& M) const;
    Matrix operator* (const double a) const;
    Matrix operator*= (const double a) const;

    Matrix operator* (const Matrix& M) const;

    Matrix transpose() const;

private:
    unsigned int n=0;
    unsigned int m=0;
    double **value;
};
std::ostream& operator<<(std::ostream& out, const Matrix& M);
std::istream& operator>>(std::istream &in, Matrix &M);

#endif // MATRIX_H
