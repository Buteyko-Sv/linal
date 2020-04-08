#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <iostream>

class Vector2D
{
public:
    // Конструкторы
    Vector2D();
    Vector2D(double x, double y);

    //деструктор
    ~Vector2D(){};

    // Получение координат
    double getX() const;
    double getY() const;

    double getLength() const; //получение модуля вектора

    void setX(double x); //получение координаты х
    void setY(double y); //получение координаты у

    bool operator== (const Vector2D& v2) const; //оператор проверки векторов на равенство
    bool operator!= (const Vector2D& v2) const; //опрератор проверки векторов на неравенство

    Vector2D operator+ (const Vector2D& v2) const; //оператор сложения
    Vector2D operator+= (const Vector2D& v2) const;
    Vector2D operator- (const Vector2D& v2) const; //оператор вычитания
    Vector2D operator-= (const Vector2D& v2) const;
    Vector2D operator* (const double a) const; //умножение векора на скаляр
    Vector2D operator*= (const double a) const;

private:
    double x=0, y=0;
};

Vector2D operator* (double a, const Vector2D& v); //умножение скаляра н вектор
double scalarProduct(Vector2D &v1, Vector2D &v2); //скалярное произведение двух векторов
double getAngle(Vector2D &v1, Vector2D &v2); //получение угла между векторами

std::ostream& operator<<(std::ostream& out, const Vector2D& v);//вывод вектора в формате (х; у)
std::istream& operator>>(std::istream &in, Vector2D &v);//ввод координат вектора

#endif // VECTOR2D_H
