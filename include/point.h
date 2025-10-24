#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point() : x_(0.0), y_(0.0) {}
    Point(double x, double y) : x_(x), y_(y) {}

    double get_x() const { return x_; }
    double get_y() const { return y_; }

private:
    double x_, y_;
};

#endif 