#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include <algorithm> 

class Trapezoid : public Figure {
public:
    Trapezoid();

    Trapezoid(double x1, double y1, double a, double b, double height);

    double area() const override;

    Point center() const override;

    void print(std::ostream& os) const override;

    void read(std::istream& is) override;

    operator double() const override;

    Trapezoid(const Trapezoid& other);

    Trapezoid& operator=(const Trapezoid& other);

    Trapezoid(Trapezoid&& other) noexcept;

    Trapezoid& operator=(Trapezoid&& other) noexcept;

    bool operator==(const Trapezoid& other) const;

private:
    Point vertex_; 
    double a_;
    double b_;
    double height_;
};

#endif