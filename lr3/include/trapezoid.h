#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid : public Figure {
private:
    Point vertices[4];

public:
    Trapezoid();
    Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Trapezoid(const Trapezoid& other); 
    ~Trapezoid() override = default;
    
    Point center() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    Figure* copy() const override;
    bool operator==(const Figure& other) const override;
    
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
};

#endif