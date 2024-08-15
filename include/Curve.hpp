#pragma once
#include "Core.hpp"

class EXPORT Curve
{
private:
    Point3D<double> m_ptOrigin;

public:
    Curve(const Point3D<double> &ptOrigin = Point3D<double>(0.0, 0.0, 0.0));
    virtual ~Curve();

    virtual void setOrigin(const Point3D<double> &ptOrigin);
    virtual const Point3D<double> getOrigin() const;

    virtual const Point3D<double> getPoint(const double &t) const = 0;
    virtual const Vector3D<double> getDerivative(const double &t) const = 0;
    virtual void printType() const = 0;

    virtual void printInfo(const double &t) const;
    virtual void printPoint(const double &t) const;
    virtual void printDerivative(const double &t) const;
};