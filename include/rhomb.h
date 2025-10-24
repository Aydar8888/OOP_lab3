#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"
#include <algorithm> 

class Rhomb : public Figure {
public:
    Rhomb();

    Rhomb(double x1, double y1, double d1, double d2);

    double area() const override;

    Point center() const override;

    void print(std::ostream& os) const override;

    void read(std::istream& is) override;

    operator double() const override;

    Rhomb(const Rhomb& other);

    Rhomb& operator=(const Rhomb& other);

    Rhomb(Rhomb&& other) noexcept;

    Rhomb& operator=(Rhomb&& other) noexcept;

    bool operator==(const Rhomb& other) const;

private:
    Point vertex_; 
    double d1_;
    double d2_;
};

#endif