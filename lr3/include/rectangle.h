#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
private:
    Point vertices[4];

public:
    Rectangle();
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Rectangle(const Rectangle& other);
    ~Rectangle() override = default;
    
    Point center() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    Figure* copy() const override;
    bool operator==(const Figure& other) const override;
    
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
};

#endif