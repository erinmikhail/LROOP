#include "rectangle.h"
#include <cmath>


Rectangle::Rectangle(const Rectangle& other) {
    for (int i = 0; i < 4; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Rectangle::Rectangle() {
    vertices[0] = Point(0, 0);
    vertices[1] = Point(2, 0);
    vertices[2] = Point(2, 1);
    vertices[3] = Point(0, 1);
}

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;
}

Point Rectangle::center() const {
    double x = 0, y = 0;
    for (int i = 0; i < 4; ++i) {
        x += vertices[i].x;
        y += vertices[i].y;
    }
    return Point(x / 4, y / 4);
}

Rectangle::operator double() const {
    double width = std::sqrt(std::pow(vertices[1].x - vertices[0].x, 2) + 
                            std::pow(vertices[1].y - vertices[0].y, 2));
    double height = std::sqrt(std::pow(vertices[3].x - vertices[0].x, 2) + 
                             std::pow(vertices[3].y - vertices[0].y, 2));
    return width * height;
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle vertices: ";
    for (int i = 0; i < 4; ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i < 3) os << ", ";
    }
}

void Rectangle::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        if (!(is >> vertices[i].x >> vertices[i].y)) {
            throw std::exception();
        }
    }
}

Figure* Rectangle::copy() const {
    return new Rectangle(*this);
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (!otherRect) return false;
    
    for (int i = 0; i < 4; ++i) {
        if (!(vertices[i] == otherRect->vertices[i])) {
            return false;
        }
    }
    return true;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}