#include "Circle.hpp"
#include <iostream>

Circle::Circle(const double &Radius, const Point3D<double> &ptOrigin)
    : Curve(ptOrigin), m_Radius(0.0)
{
    setRadius(Radius);
}

Circle::~Circle()
{
}

inline const Point3D<double> Circle::getPoint(const double &t) const
{
    const double R = getRadius();
    double x = R * std::cos(t);
    double y = R * std::sin(t);

    return Point3D<double>(x, y, 0.0);
}

const Vector3D<double> Circle::getDerivative(const double &t) const
{
    const double R = getRadius();
    double x = R * -std::sin(t);
    double y = R * std::cos(t);

    return Vector3D<double>(x, y, 0.0);
}

void Circle::printType() const
{
    std::cout << "Circle" << std::endl;
}

void Circle::setRadius(const double &Radius)
{
    m_Radius = (Radius < 0.0 ? 0.0 : Radius);
}

const double Circle::getRadius() const
{
    return m_Radius;
}
