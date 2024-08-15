#include "Helix.hpp"
#include <iostream>

Helix::Helix(const double &Radius, const double &Heigth, const Point3D<double> &ptOrigin)
    : Circle(Radius, ptOrigin), m_Heigth(0.0)
{
    setHeigth(Heigth);
}

Helix::~Helix()
{
}

inline const Point3D<double> Helix::getPoint(const double &t) const
{
    Point3D<double> ptOut = Circle::getPoint(t);
    ptOut.z = t / (M_PI * 2.0) * getHeigth();
    return ptOut;
}

const Vector3D<double> Helix::getDerivative(const double &t) const
{
    Vector3D<double> vecOut = Circle::getDerivative(t);
    constexpr double delta = 1.0 / ((M_PI * 2.0));
    vecOut.z = delta * getHeigth();
    return vecOut;
}

void Helix::printType() const
{
    std::cout << "Helix" << std::endl;
}

void Helix::setHeigth(const double &Heigth)
{
    m_Heigth = Heigth;
}

const double Helix::getHeigth() const
{
    return m_Heigth;
}
