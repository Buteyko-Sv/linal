#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <iostream>

class Vector2D
{
public:
    // ������������
    Vector2D();
    Vector2D(double x, double y);

    //����������
    ~Vector2D(){};

    // ��������� ���������
    double getX() const;
    double getY() const;

    double getLength() const; //��������� ������ �������

    void setX(double x); //��������� ���������� �
    void setY(double y); //��������� ���������� �

    bool operator== (const Vector2D& v2) const; //�������� �������� �������� �� ���������
    bool operator!= (const Vector2D& v2) const; //��������� �������� �������� �� �����������

    Vector2D operator+ (const Vector2D& v2) const; //�������� ��������
    Vector2D operator+= (const Vector2D& v2) const;
    Vector2D operator- (const Vector2D& v2) const; //�������� ���������
    Vector2D operator-= (const Vector2D& v2) const;
    Vector2D operator* (const double a) const; //��������� ������ �� ������
    Vector2D operator*= (const double a) const;

private:
    double x=0, y=0;
};

Vector2D operator* (double a, const Vector2D& v); //��������� ������� � ������
double scalarProduct(Vector2D &v1, Vector2D &v2); //��������� ������������ ���� ��������
double getAngle(Vector2D &v1, Vector2D &v2); //��������� ���� ����� ���������

std::ostream& operator<<(std::ostream& out, const Vector2D& v);//����� ������� � ������� (�; �)
std::istream& operator>>(std::istream &in, Vector2D &v);//���� ��������� �������

#endif // VECTOR2D_H
