#include "Curve.hpp"
#include <iostream>

Curve::Curve(const Point3D<double> &ptOrigin) : m_ptOrigin(ptOrigin)
{
}

Curve::~Curve()
{
}

void Curve::setOrigin(const Point3D<double> &ptOrigin)
{
    m_ptOrigin = ptOrigin;
}

const Point3D<double> Curve::getOrigin() const
{
    return m_ptOrigin;
}

void Curve::printInfo(const double &t) const
{
    printType();
    printPoint(t);
    printDerivative(t);
}

void Curve::printPoint(const double &t) const
{
    const Point3D<double> point = getPoint(t);
    std::cout << "Point: x(" << point.x << "), y(" << point.y << "), z(" << point.z << ")" << std::endl;
}

void Curve::printDerivative(const double &t) const
{
    const Vector3D<double> vec = getDerivative(t);
    std::cout << "Derivative: x(" << vec.x << "), y(" << vec.y << "), z(" << vec.z << ")" << std::endl;
}
