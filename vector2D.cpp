#include "vector2D.h"

    // Конструкторы
   Vector2D :: Vector2D()
   {
        this->setX(0);
        this->setY(0);
   };

    Vector2D :: Vector2D(double x, double y)
    {
        this->setX(x);
        this->setY(y);
    };


    // Получение координат
    double Vector2D :: getX() const
    {
        return this->x;
    };
    double Vector2D :: getY() const
    {
        return this->y;
    };

    double Vector2D :: getLength() const
    {
        return sqrt(this->x*this->x+this->y*this->y);
    };

    void Vector2D :: setX(double x)
    {
        this->x=x;
    };
    void Vector2D :: setY(double y)
    {
        this->y=y;
    };

    bool Vector2D :: operator== (const Vector2D& v2) const
    {
        return (this->getX()==v2.getX() && this->getY()==v2.getY());
    };
    bool Vector2D :: operator!= (const Vector2D& v2) const
    {
        return !(this->getX()==v2.getX() && this->getY()==v2.getY());
    };

    Vector2D Vector2D :: operator+ (const Vector2D& v2) const
    {
        Vector2D vtemp;
        vtemp.setX(this->getX()+v2.getX());
        vtemp.setY(this->getY()+v2.getY());
        return vtemp;
    };
    Vector2D Vector2D :: operator+= (const Vector2D& v2) const
    {
        Vector2D vtemp;
        vtemp.setX(this->getX()+v2.getX());
        vtemp.setY(this->getY()+v2.getY());
        return vtemp;
    };
    Vector2D Vector2D :: operator- (const Vector2D& v2) const
    {
        Vector2D vtemp;
        vtemp.setX(this->getX()-v2.getX());
        vtemp.setY(this->getY()-v2.getY());
        return vtemp;
    };
    Vector2D Vector2D :: operator-= (const Vector2D& v2) const
    {
        Vector2D vtemp;
        vtemp.setX(this->getX()-v2.getX());
        vtemp.setY(this->getY()-v2.getY());
        return vtemp;
    };
    Vector2D Vector2D :: operator* (const double a) const
    {
        Vector2D vtemp;
        vtemp.setX(this->getX()*a);
        vtemp.setY(this->getY()*a);
        return vtemp;
    };
    Vector2D Vector2D :: operator*= (const double a) const
    {
        Vector2D vtemp;
        vtemp.setX(this->getX()*a);
        vtemp.setY(this->getY()*a);
        return vtemp;
    };


Vector2D operator* (double a, const Vector2D& v)
{
    Vector2D vtemp;
    vtemp.setX(v.getX()*a);
    vtemp.setY(v.getY()*a);
    return vtemp;
}
double scalarProduct(Vector2D &v1, Vector2D &v2)
{
    return (v1.getX()*v2.getX()+v1.getY()+v2.getY());
}
double getAngle(Vector2D &v1, Vector2D &v2)
{
    return scalarProduct(v1, v2)/(v1.getLength()*v2.getLength());
}

std::ostream& operator<<(std::ostream& out, const Vector2D& v)
{
    out<<"("<<v.getX()<<"; "<<v.getY()<<")";
    return out;
}
std::istream& operator>>(std::istream &in, Vector2D &v)
{
    int xtemp=0, ytemp=0;
    in>>xtemp;
    v.setX(xtemp);
    in>>ytemp;
    v.setY(ytemp);
    return in;
}
