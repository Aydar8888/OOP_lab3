#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <algorithm> 

class Rectangle : public Figure {
public:
    Rectangle();

    Rectangle(double x1, double y1, double width, double height);

    double area() const override;

    Point center() const override;

    void print(std::ostream& os) const override;

    void read(std::istream& is) override;

    operator double() const override;

    Rectangle(const Rectangle& other);

    Rectangle& operator=(const Rectangle& other);

    Rectangle(Rectangle&& other) noexcept;

    Rectangle& operator=(Rectangle&& other) noexcept;

    bool operator==(const Rectangle& other) const;

private:
    Point vertex_; 
    double width_;
    double height_;
};

#endif