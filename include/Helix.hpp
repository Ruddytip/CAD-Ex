#pragma once
#include "Circle.hpp"

class EXPORT Helix : public Circle
{
private:
    double m_Heigth;

public:
    Helix() = delete;
    Helix(const double &Radius, const double &Heigth, const Point3D<double> &ptOrigin = Point3D<double>(0.0, 0.0, 0.0));
    virtual ~Helix();

    virtual const Point3D<double> getPoint(const double &t) const;
    virtual const Vector3D<double> getDerivative(const double &t) const;
    virtual void printType() const override;

    virtual void setHeigth(const double &Heigth);
    virtual const double getHeigth() const;
};
