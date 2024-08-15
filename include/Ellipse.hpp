#pragma once
#include "Curve.hpp"

class EXPORT Ellipse : public Curve
{
private:
    double m_Radius1;
    double m_Radius2;

public:
    Ellipse() = delete;
    Ellipse(const double &Radius1, const double &Radius2, const Point3D<double> &ptOrigin = Point3D<double>(0.0, 0.0, 0.0));
    virtual ~Ellipse();

    virtual const Point3D<double> getPoint(const double &t) const;
    virtual const Vector3D<double> getDerivative(const double &t) const;
    virtual void printType() const override;

    virtual void setRadius1(const double &Radius);
    virtual const double getRadius1() const;

    virtual void setRadius2(const double &Radius);
    virtual const double getRadius2() const;
};
