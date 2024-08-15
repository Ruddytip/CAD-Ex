#pragma once
#include "Curve.hpp"

class EXPORT Circle : public Curve
{
private:
    double m_Radius;

public:
    Circle() = delete;
    Circle(const double &Radius, const Point3D<double> &ptOrigin = Point3D<double>(0.0, 0.0, 0.0));
    virtual ~Circle();

    const Point3D<double> getPoint(const double &t) const override;
    const Vector3D<double> getDerivative(const double &t) const override;
    virtual void printType() const override;

    virtual void setRadius(const double &Radius);
    virtual const double getRadius() const;
};