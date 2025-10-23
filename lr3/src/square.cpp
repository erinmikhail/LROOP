#include "square.h"
#include <cmath>


Square::Square(const Square& other) {
    for (int i = 0; i < 4; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Square::Square() {
    vertices[0] = Point(0, 0);
    vertices[1] = Point(1, 0);
    vertices[2] = Point(1, 1);
    vertices[3] = Point(0, 1);
}

Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;
}

Point Square::center() const {
    double x = 0, y = 0;
    for (int i = 0; i < 4; ++i) {
        x += vertices[i].x;
        y += vertices[i].y;
    }
    return Point(x / 4, y / 4);
}

Square::operator double() const {
    double side = std::sqrt(std::pow(vertices[1].x - vertices[0].x, 2) + 
                           std::pow(vertices[1].y - vertices[0].y, 2));
    return side * side;
}

void Square::print(std::ostream& os) const {
    os << "Square vertices: ";
    for (int i = 0; i < 4; ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i < 3) os << ", ";
    }
}

void Square::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        if (!(is >> vertices[i].x >> vertices[i].y)) {
            throw std::exception();
        }
    }
}

Figure* Square::copy() const {
    return new Square(*this);
}

bool Square::operator==(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (!otherSquare) return false;
    
    for (int i = 0; i < 4; ++i) {
        if (!(vertices[i] == otherSquare->vertices[i])) {
            return false;
        }
    }
    return true;
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}