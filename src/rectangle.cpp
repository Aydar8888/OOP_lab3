#include "../include/rectangle.h"

Rectangle::Rectangle() : vertex_(0.0, 0.0), width_(0.0), height_(0.0) {}

Rectangle::Rectangle(double x1, double y1, double width, double height)
    : vertex_(x1, y1), width_(width), height_(height) {
    if (width < 0 || height < 0) {
        throw std::invalid_argument("Ширина и высота прямоугольника не могут быть отрицательными!");
    }
}

double Rectangle::area() const {
    return width_ * height_;
}

Point Rectangle::center() const {
    return Point(vertex_.get_x() + (width_ / 2), vertex_.get_y() + (height_ / 2));
}

void Rectangle::print(std::ostream& os) const {
    double x = vertex_.get_x();
    double y = vertex_.get_y();
    os << "Прямоугольник: (" << x << ", " << y << "), ("
       << x << ", " << y + height_ << "), (" 
       << x + width_ << ", " << y + height_ << "), (" 
       << x + width_ << ", " << y << ")";
}

void Rectangle::read(std::istream& is) {
    double x1, y1, w, h;
    is >> x1 >> y1 >> w >> h;
    if (w < 0 || h < 0) {
        throw std::invalid_argument("Ширина и высота прямоугольника не могут быть отрицательными!");
    }
    vertex_ = Point(x1, y1);
    width_ = w;
    height_ = h;
}

Rectangle::Rectangle(const Rectangle& other)
    : vertex_(other.vertex_), width_(other.width_), height_(other.height_) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        vertex_ = other.vertex_;
        width_ = other.width_;
        height_ = other.height_;
    }
    return *this;
}

Rectangle::Rectangle(Rectangle&& other) noexcept
    : vertex_(std::move(other.vertex_)), width_(std::move(other.width_)), height_(std::move(other.height_)) {
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        vertex_ = std::move(other.vertex_);
        width_ = std::move(other.width_);
        height_ = std::move(other.height_);
    }
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const {
    return vertex_.get_x() == other.vertex_.get_x() && vertex_.get_y() == other.vertex_.get_y() && width_ == other.width_ && height_ == other.height_;
}

Rectangle::operator double() const {
    return area();
}