#include "Ellipse.hpp"
#include <iostream>

Ellipse::Ellipse(const double &Radius1, const double &Radius2, const Point3D<double> &ptOrigin)
    : Curve(ptOrigin), m_Radius1(0.0), m_Radius2(0.0)
{
    setRadius1(Radius1);
    setRadius2(Radius2);
}

Ellipse::~Ellipse()
{
}

inline const Point3D<double> Ellipse::getPoint(const double &t) const
{
    double x = getRadius1() * std::cos(t);
    double y = getRadius2() * std::sin(t);

    return Point3D<double>(x, y, 0.0);
}

const Vector3D<double> Ellipse::getDerivative(const double &t) const
{
    double x = getRadius1() * -std::sin(t);
    double y = getRadius2() * std::cos(t);

    return Vector3D<double>(x, y, 0.0);
}

void Ellipse::printType() const
{
    std::cout << "Ellipse" << std::endl;
}

void Ellipse::setRadius1(const double &Radius)
{
    m_Radius1 = (Radius < 0.0 ? 0.0 : Radius);
}

const double Ellipse::getRadius1() const
{
    return m_Radius1;
}

void Ellipse::setRadius2(const double &Radius)
{
    m_Radius2 = (Radius < 0.0 ? 0.0 : Radius);
}

const double Ellipse::getRadius2() const
{
    return m_Radius2;
}
