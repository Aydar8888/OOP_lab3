#include "../include/rhomb.h"

Rhomb::Rhomb() : vertex_(0.0, 0.0), d1_(0.0), d2_(0.0) {}

Rhomb::Rhomb(double x1, double y1, double d1, double d2)
    : vertex_(x1, y1), d1_(d1), d2_(d2) {
    if (d1 < 0 || d2 < 0) {
        throw std::invalid_argument("Диагонали ромба не могут быть отрицательными!");
    }
}

double Rhomb::area() const {
    return 0.5 * d1_ * d2_;
}

Point Rhomb::center() const {
    return Point(vertex_.get_x() + (d1_ / 2), vertex_.get_y());
}

void Rhomb::print(std::ostream& os) const {
    double x = vertex_.get_x();
    double y = vertex_.get_y();
    os << "Ромб: (" << x << ", " << y << "), ("
       << x << ", " << y + d2_/2 << "), (" 
       << x + d1_ << ", " << y << "), (" 
       << x + d1_ / 2 << ", " << y - d2_ / 2 << ")";
}

void Rhomb::read(std::istream& is) {
    double x1, y1, d1, d2;
    is >> x1 >> y1 >> d1 >> d2;
    if (d1 < 0 || d2 < 0) {
        throw std::invalid_argument("Диагонали ромба не могут быть отрицательными!");
    }
    vertex_ = Point(x1, y1);
    d1_ = d1;
    d2_ = d2;
}

Rhomb::Rhomb(const Rhomb& other)
    : vertex_(other.vertex_), d1_(other.d1_), d2_(other.d2_) {}

Rhomb& Rhomb::operator=(const Rhomb& other) {
    if (this != &other) {
        vertex_ = other.vertex_;
        d1_ = other.d1_;
        d2_ = other.d2_;
    }
    return *this;
}

Rhomb::Rhomb(Rhomb&& other) noexcept
    : vertex_(std::move(other.vertex_)), d1_(std::move(other.d1_)), d2_(std::move(other.d2_)) {
}

Rhomb& Rhomb::operator=(Rhomb&& other) noexcept {
    if (this != &other) {
        vertex_ = std::move(other.vertex_);
        d1_ = std::move(other.d1_);
        d2_ = std::move(other.d1_);
    }
    return *this;
}

bool Rhomb::operator==(const Rhomb& other) const {
    return vertex_.get_x() == other.vertex_.get_x() && vertex_.get_y() == other.vertex_.get_y() && d1_ == other.d1_ && d2_ == other.d2_;
}

Rhomb::operator double() const {
    return area();
}