#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
private:
    Point vertices[4];

public:
    Square();
    Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Square(const Square& other);
    ~Square() override = default;
    
    Point center() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    Figure* copy() const override;
    bool operator==(const Figure& other) const override;
    
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
};

#endif