#include "trapezoid.h"
#include <cmath>


Trapezoid::Trapezoid(const Trapezoid& other) {
    for (int i = 0; i < 4; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Trapezoid::Trapezoid() {
    vertices[0] = Point(0, 0);
    vertices[1] = Point(3, 0);
    vertices[2] = Point(2, 1);
    vertices[3] = Point(1, 1);
}

Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;
}

Point Trapezoid::center() const {
    double x = 0, y = 0;
    for (int i = 0; i < 4; ++i) {
        x += vertices[i].x;
        y += vertices[i].y;
    }
    return Point(x / 4, y / 4);
}

Trapezoid::operator double() const {
    double a = std::sqrt(std::pow(vertices[1].x - vertices[0].x, 2) + 
                        std::pow(vertices[1].y - vertices[0].y, 2));
    double b = std::sqrt(std::pow(vertices[2].x - vertices[3].x, 2) + 
                        std::pow(vertices[2].y - vertices[3].y, 2));
    
    double h = (std::abs(vertices[2].y - vertices[1].y) + 
               std::abs(vertices[3].y - vertices[0].y)) / 2;
    
    return (a + b) * h / 2;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid vertices: ";
    for (int i = 0; i < 4; ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i < 3) os << ", ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        if (!(is >> vertices[i].x >> vertices[i].y)) {
            throw std::exception();
        }
    }
}

Figure* Trapezoid::copy() const {
    return new Trapezoid(*this);
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* otherTrap = dynamic_cast<const Trapezoid*>(&other);
    if (!otherTrap) return false;
    
    for (int i = 0; i < 4; ++i) {
        if (!(vertices[i] == otherTrap->vertices[i])) {
            return false;
        }
    }
    return true;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}