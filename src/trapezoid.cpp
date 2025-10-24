#include "../include/trapezoid.h"

Trapezoid::Trapezoid() : vertex_(0.0, 0.0), a_(0.0), b_(0.0), height_(0.0) {}

Trapezoid::Trapezoid(double x1, double y1, double a, double b, double height)
    : vertex_(x1, y1), a_(a), b_(b), height_(height) {
    if (a < 0 || b < 0 || height < 0) {
        throw std::invalid_argument("Основания и высота трапеции не могут быть отрицательными!");
    }
}

double Trapezoid::area() const {
    return 0.5 * (a_ + b_) * height_;
}

Point Trapezoid::center() const {
    double x = vertex_.get_x() + a_ / 2.0;
    double y_center = vertex_.get_y() + (height_ * (a_ + 2 * b_)) / (3 * (a_ + b_));
    return Point(x, y_center);
}

void Trapezoid::print(std::ostream& os) const {
    double x = vertex_.get_x();
    double y = vertex_.get_y();
    double offset = (a_ - b_) / 2.0; 
    
    os << "Трапеция: (" << x << ", " << y << "), "           
       << "(" << x + offset << ", " << y + height_ << "), " 
       << "(" << x + offset + b_ << ", " << y + height_ << "), " 
       << "(" << x + a_ << ", " << y << ")";                
}

void Trapezoid::read(std::istream& is) {
    double x1, y1, a, b, height;
    is >> x1 >> y1 >> a >> b >> height;
    
    if (a < 0 || b < 0 || height < 0) {
        throw std::invalid_argument("Основания и высота трапеции не могут быть отрицательными!");
    }
    
    vertex_ = Point(x1, y1);
    a_ = a;
    b_ = b;
    height_ = height;
}

Trapezoid::Trapezoid(const Trapezoid& other)
    : vertex_(other.vertex_), a_(other.a_), b_(other.b_), height_(other.height_) {}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        vertex_ = other.vertex_;
        a_ = other.a_;
        b_ = other.b_;
        height_ = other.height_;
    }
    return *this;
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept
    : vertex_(std::move(other.vertex_)), a_(std::move(other.a_)), 
      b_(std::move(other.b_)), height_(std::move(other.height_)) {}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        vertex_ = std::move(other.vertex_);
        a_ = std::move(other.a_);
        b_ = std::move(other.b_);
        height_ = std::move(other.height_);
    }
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    return vertex_.get_x() == other.vertex_.get_x() && 
           vertex_.get_y() == other.vertex_.get_y() && 
           a_ == other.a_ && 
           b_ == other.b_ && 
           height_ == other.height_;
}

Trapezoid::operator double() const {
    return area();
}